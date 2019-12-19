import QtQuick 2.6
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2
import QtQuick.Layouts 1.1

Page {
    id: adminMainPage
    property int customerId
    header: ToolBar {
        ToolButton {
            text: qsTr("Back")
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.verticalCenter: parent.verticalCenter
            onClicked: adminMainPage.StackView.view.pop()
        }
        Label {
            text: qsTr("About")
            font.pixelSize: 20
            anchors.centerIn: parent
        }
    }
    Text {
        id: name
        font.pointSize: 25
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        text: qsTr("Created by Yauheni Rotar.")
    }
}
