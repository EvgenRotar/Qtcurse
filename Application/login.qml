import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2

ApplicationWindow {
    id: appWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Login")
    Material.theme: Material.Dark
    SwipeView {
        id: swipeView
        currentIndex: tabBar.currentIndex

        AuthorizationForm {
            signInButton.onClicked: {
                console.log(tabBar.currentIndex);

                var loggin  = loginEditField.text;
                var password    = passwordEditField.text;

                console.log(loggin);
                console.log(password);

                // todo: validate and handle
                if (!loggin) {
                    console.log("login empty");
                }
                if (!password) {
                    console.log("password empty");
                }

                var isSignedIn = employeeDao.signIn(loggin, password);

                if (isSignedIn) {

        //                    swipeView.visible=false;
        //                    swipeView.enabled=false;
        //                    tabBar.visible=false;
        //                    tabBar.enabled=false;
        //                    appWindow.visible=false;
                    appWindow.close();

                    loader.source = "Main.qml";

                }

            }
        }

        RegistrationForm {
            signInButton.onClicked: {
                console.log(tabBar.currentIndex);

                var loggin = loginEditField.text;
                var password = passwordEditField.text;

                console.log(loggin);
                console.log(password);

                // todo: validate and handle
                if (!loggin) {
                    console.log("login empty");
                }
                if (!password) {
                    console.log("password empty");
                }

                var isSignedUn = employeeDao.signUp(loggin, password);
                console.log(isSignedUn);
                if (isSignedUn) {
                    tabBar.setCurrentIndex(0);
                }
            }
        }

        Loader {
            id: loader;
            anchors.fill: parent;
        }

    }

    property variant win;

    header: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex
        TabButton {
            text: qsTr("authorization")

        }
        TabButton {
            text: qsTr("registration")
        }
    }

}
