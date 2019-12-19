import QtQuick 2.6
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2
import QtQuick.Layouts 1.1

Page {
    Material.accent: Material.Cyan
    id: registratinPage
    header: ToolBar {
        Material.background: Material.Cyan
        ToolButton {
               text: qsTr("Back")
               anchors.left: parent.left
               anchors.leftMargin: 10
               anchors.verticalCenter: parent.verticalCenter
               onClicked: registratinPage.StackView.view.pop()
           }
        Label {
            text: qsTr("SignUp")
            font.pixelSize: 20
            anchors.centerIn: parent
        }
    }

    Column {
        anchors.centerIn: parent
        width: parent.width - 50
        height: parent.height - 150

        TextField {

            id: firstname
            Layout.fillWidth: true
            width: parent.width
            placeholderText: qsTr("Firstname")
            onFocusChanged: {
                wrongfields.visible = false
            }
        }
        TextField {

            id: lastname
            Layout.fillWidth: true
            width: parent.width
            placeholderText: qsTr("Lastname")
            onFocusChanged: {
                wrongfields.visible = false
            }
        }
        TextField {

            id: email
            Layout.fillWidth: true
            width: parent.width
            placeholderText: qsTr("Email")
            onFocusChanged: {
                wrongfields.visible = false
                wrongEmail.visible = false
            }
        }

        TextField {
            id: password
            echoMode: TextInput.Password
            Layout.fillWidth: true
            width: parent.width
            placeholderText: qsTr("Password")
            onFocusChanged: {
                wrongPasswords.visible = false
            }
        }
        TextField {
            id: repeatedPassword
            echoMode: TextInput.Password
            Layout.fillWidth: true
            width: parent.width
            placeholderText: qsTr("Repeat password")
            onFocusChanged: {
                wrongPasswords.visible = false
            }
        }

        Button {
            contentItem: Text {
                text: parent.text
                font: parent.font
                opacity: enabled ? 1.0 : 0.3
                color: "white"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                elide: Text.ElideRight
            }
            id: signIn
            width: parent.width
            text: qsTr("Register")

            Material.background: Material.Green // Change the background
            onClicked: {
                if (password.text !== repeatedPassword.text) {
                    wrongPasswords.visible = true
                    return
                }
                if (firstname.text.length === 0) {
                    wrongfields.visible = true
                    return
                }
                if (lastname.text.length === 0) {
                    wrongfields.visible = true
                    return
                }
                if (email.text.length === 0) {
                    wrongfields.visible = true
                    return
                }
                if (password.text.length === 0) {
                    wrongfields.visible = true
                    return
                }
                if (repeatedPassword.text.length === 0) {
                    wrongfields.visible = true
                    return
                }
                var dbResponse = serviceAccessor.registerUser(
                            firstname.text, lastname.text, email.text,
                            password.text)
                if (dbResponse === 0) {
                    wrongEmail.visible = true
                }
                if (dbResponse !== 0) {
                    succsess.visible = true
                }
            }
        }

        Text {
            visible: false
            id: succsess
            color: "green"
            text: qsTr("You are successfully registred.")
        }
        Text {
            visible: false
            id: wrongEmail
            color: "red"
            text: qsTr("User with this email alredy exist.")
        }
        Text {
            visible: false
            id: wrongfields
            color: "red"
            text: qsTr("Please fill all fields correctly.")
        }

        Text {
            visible: false
            id: wrongPasswords
            color: "red"
            text: qsTr("Passwords do not match.")
        }
    }
}
