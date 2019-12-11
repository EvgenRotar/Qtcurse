import QtQuick 2.7
import QtQuick.Controls 2.0

Page {
    id: page
    width: 600
    height: 400
    property alias passwordEditField: passwordEditField
    property alias loginEditField: loginEditField
    property alias signInButton: signInButton


    Button {
        id: signInButton
        x: 164
        width: 271
        height: 48
        text: qsTr("sign in")
        autoRepeat: false
        anchors.top: passwordEditField.bottom
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        padding: 0
    }

    TextField {
        id: loginEditField
        x: 164
        y: 79
        width: 271
        height: 43
        text: qsTr("login")
        font.pointSize: 10
        anchors.bottom: passwordEditField.top
        anchors.bottomMargin: 0
        anchors.horizontalCenter: parent.horizontalCenter
        horizontalAlignment: Text.AlignHCenter
        font.family: webFont.name
    }

    TextField {
        id: passwordEditField
        x: 165
        y: 211
        width: 271
        height: 43
        text: qsTr("password")
        font.pointSize: 10
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        horizontalAlignment: Text.AlignHCenter
        font.family: webFont.name
    }

    /*extEdit {
        id: loginEditField
        x: 165
        y: 122
        width: 271
        height: 48
        color: "#ffffff"
        text: qsTr("login")
        anchors.bottom: passwordEditField.top
        anchors.bottomMargin: 0
        anchors.horizontalCenterOffset: 1
        anchors.horizontalCenter: parent.horizontalCenter
        selectionColor: "#000000"
        clip: false
        textFormat: Text.AutoText
        horizontalAlignment: Text.AlignHCenter
        cursorVisible: true
        font.pixelSize: 12
        font.family: webFont.name
    }*/

    /*xtEdit {
        id: passwordEditField
        x: 165
        y: 206
        width: 271
        height: 48
        color: "#ffffff"
        text: qsTr("password")
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        selectionColor: "#000000"
        cursorVisible: true
        textFormat: Text.AutoText
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 12
    }*/

    Item {
        id: element
        x: 692
        y: 341
        width: 200
        height: 200
    }

    FontLoader {
    id:webFont
    source: "https://fonts.googleapis.com/css?family=Roboto:300,400,500,700,400italic|Roboto+Mono:400,500|Material+Icons"
    }

}




/*##^##
Designer {
    D{i:1;anchors_y:332}
}
##^##*/
