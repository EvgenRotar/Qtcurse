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
        id: signUpButton
        x: 319
        y: 341
        width: 271
        height: 48
        text: qsTr("sign up")
    }

    Button {
        id: signInButton
        x: 10
        y: 341
        width: 271
        height: 48
        text: qsTr("sign in")
    }

    TextEdit {
        id: passwordEditField
        x: 165
        y: 206
        width: 271
        height: 48
        color: "#ffffff"
        text: qsTr("password")
        selectionColor: "#000000"
        cursorVisible: true
        textFormat: Text.AutoText
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 12
    }

    TextEdit {
        id: loginEditField
        x: 165
        y: 152
        width: 271
        height: 48
        color: "#ffffff"
        text: qsTr("login")
        selectionColor: "#000000"
        clip: false
        textFormat: Text.AutoText
        horizontalAlignment: Text.AlignHCenter
        cursorVisible: true
        font.pixelSize: 12
        font.family: webFont.name
    }

    Item {
        id: element
        x: 692
        y: 341
        width: 200
        height: 200
    }

//    FontLoader {
//    id:webFont
//    source: "https://fonts.googleapis.com/css?family=Roboto:300,400,500,700,400italic|Roboto+Mono:400,500|Material+Icons"
//    }
}



