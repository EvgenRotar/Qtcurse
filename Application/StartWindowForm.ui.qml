import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Controls.Material 2.2

Page {
    width: 600
    height: 400
    property alias pressStartButton: pressStartButton
    property alias pressAboutButton: pressAboutButton

    BorderImage {
        id: borderImage
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent
        source: "file:/home/engeny/Downloads/Telegram Desktop/Qt-AddressBook/Application/qml/resources/image.jpg"

        Text {
            id: element
            x: 434
            y: 372
            width: 158
            height: 20
            text: qsTr("Created by Yauheni Rotar")
            anchors.right: parent.right
            anchors.rightMargin: 8
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 8
            font.pixelSize: 12
        }
        Button {
            id: pressAboutButton
            x: 200
            y: 318
            width: 201
            height: 48
            text: qsTr("About")
            anchors.horizontalCenterOffset: -191
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 34
        }
        Button {
            id: pressStartButton
            x: 200
            y: 318
            width: 201
            height: 48
            text: qsTr("press to start")
            anchors.horizontalCenterOffset: 192
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 34
        }


    }

}

/*##^##
Designer {
    D{i:3;anchors_x:200}D{i:1;anchors_height:400;anchors_width:600;anchors_x:0;anchors_y:0}
}
##^##*/
