import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2
import Customer 1.0

ApplicationWindow {

    visible: true
    width: 640
    height: 480
    title: qsTr("Грузоперевозки")

    property variant win;

    ListView {
        model: CustomerModel{}
    }

    SwipeView {
        id: swipeView
        anchors.fill: parent

        StartWindowForm {
            pressStartButton.onClicked: {
                hide();
                var component = Qt.createComponent("login.qml");
                       win = component.createObject(this);
                       win.show();
            }

            pressAboutButton.onClicked: {
                hide();
                var component = Qt.createComponent("login.qml");
                       win = component.createObject(this);
                       win.show();
            }

        }
    }
}
