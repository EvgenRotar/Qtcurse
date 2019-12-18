import QtQuick 2.6
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2
import QtQuick.Layouts 1.1
//import moviemodel 1.0

Page {
    id: userMainPage
    property int userId
    header: ToolBar {
        ToolButton {
            text: qsTr("LogOut")
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.verticalCenter: parent.verticalCenter
            onClicked: userMainPage.StackView.view.pop()
        }
        Label {
            text: qsTr("Movies")
            font.pixelSize: 20
            anchors.centerIn: parent
        }
    }
    TabBar {
        id: tabBar
        width: userMainPage.widh

        currentIndex: view.currentIndex

        TabButton {
            enabled: false
            width: userMainPage.width / 2
            text: qsTr("All movies")
        }

        TabButton {
            enabled: false
            width: userMainPage.width / 2
            text: qsTr("Liked movies")
        }
    }

    SwipeView {
        id: view
        anchors.topMargin: 60
        currentIndex: 0
        anchors.fill: parent
        onCurrentIndexChanged: {
            var ind = view.currentIndex
            if(ind === 0 ){
                MovieModel.setActiveUserId(0)
            }
            if(ind === 1){
                MovieModel.setActiveUserId(userId)
            }
        }

        Item {
            id: firstPage
            ColumnLayout {
                anchors.fill: parent
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                ListView {
                    id: mainUserListView
                    visible: true
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.margins: 15
                    displayMarginBeginning: -60
                    displayMarginEnd: 0
                    verticalLayoutDirection: ListView.TopToBottom
                    spacing: 10
                    model: MovieModel
                    ScrollBar.vertical: ScrollBar {
                    }
                    delegate: ItemDelegate {
                        width: mainUserListView.width - mainUserListView.leftMargin
                               - mainUserListView.rightMargin
                        height: 100
                        spacing: 10
                        Column{
                            spacing: 5
                            Label {
                                  text: "Movie name: " + MovieName
                            }
                            Label {
                                  text: "Language: " + Language
                            }
                            Label {
                                  text: "Duration: " + RunningTime
                            }
                            Label {
                                  text: "Cinema name: " + CinemaName
                            }

                        }
                        onClicked: userMainPage.StackView.view.push("qrc:/MovieDetailsUser.qml",{
                                                                        movName : MovieName,
                                                                        movlang : Language,
                                                                        movRunTime : RunningTime,
                                                                        movRentType : RentalType,
                                                                        movReleaseDate : ReleaseDate,
                                                                        movEndDate : EndDate,
                                                                        movCinemaName : CinemaName,
                                                                        movCinemaAddres : CinemaAddres,
                                                                        movAuthFirstName : AuthorFirstName,
                                                                        movAuthLAstName : AuthorLastName,
                                                                        movAuthDateOfBirth : AuthorDateOfBirth,
                                                                        movDirFirstName : DirectorFirstName,
                                                                        movDirLAstName : DirectorLastName,
                                                                        movDirDateOfBirth : DirectorDateOfBirth,
                                                                        movId : MovieId,
                                                                        userId : userId})
                    }
                }
            }
        }
        Item {

            id: secondPage
            ColumnLayout {
                anchors.fill: parent
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                ListView {
                    id: likedUserListView
                    visible: true
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.margins: 15
                    displayMarginBeginning: -60
                    displayMarginEnd: 0
                    verticalLayoutDirection: ListView.TopToBottom
                    spacing: 10
                    model: MovieModel

                    ScrollBar.vertical: ScrollBar {
                    }
                    delegate: ItemDelegate {
                        width: mainUserListView.width - mainUserListView.leftMargin
                               - mainUserListView.rightMargin
                        height: 100
                        spacing: 10
                        Column{
                            spacing: 5
                            Label {
                                  text: "Movie name: " + MovieName
                            }
                            Label {
                                  text: "Language: " + Language
                            }
                            Label {
                                  text: "Duration: " + RunningTime
                            }
                            Label {
                                  text: "Cinema name: " + CinemaName
                            }

                        }
                        onClicked: userMainPage.StackView.view.push("qrc:/MovieDetailsUser.qml",{
                                                                        movName : MovieName,
                                                                        movlang : Language,
                                                                        movRunTime : RunningTime,
                                                                        movRentType : RentalType,
                                                                        movReleaseDate : ReleaseDate,
                                                                        movEndDate : EndDate,
                                                                        movCinemaName : CinemaName,
                                                                        movCinemaAddres : CinemaAddres,
                                                                        movAuthFirstName : AuthorFirstName,
                                                                        movAuthLAstName : AuthorLastName,
                                                                        movAuthDateOfBirth : AuthorDateOfBirth,
                                                                        movDirFirstName : DirectorFirstName,
                                                                        movDirLAstName : DirectorLastName,
                                                                        movDirDateOfBirth : DirectorDateOfBirth,
                                                                        movId : MovieId,
                                                                        userId : userId})
                    }
                }
            }
        }
    }
}
