import QtQuick 2.6
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2
import QtQuick.Layouts 1.1
import CustomerOrders 1.0



Page {
    property var customerId

    property var orderId
    property var orderAssigned
    property var orderDescriptiom
    property var orderPrice
    property var orderSendingDate
    property var orderType
    property var itemName
    property var itemHeigh
    property var itemWidth
    property var itemLength
    property var startAddres
    property var endAddres
    property bool isBtnActive

    property var driverFirstName
    property var driverLastName
    property var companyName
    property CustomerOrderModel backEnd


    id: adminDetailPage
    header: ToolBar {
        ToolButton {
            text: qsTr("Back")
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.verticalCenter: parent.verticalCenter
            onClicked: adminDetailPage.StackView.view.pop()
        }
        Label {
            text: qsTr("Order Details")
            font.pixelSize: 20
            anchors.centerIn: parent
        }
    }

    Column {
        id:anchCol
        anchors.centerIn: parent
        width: parent.width - 50
        height: parent.height - 50
        spacing: 10


        Label {
            font.pointSize: 20
            text: "Item: " + itemName
        }

        Label {
            font.pointSize: 20
            text: "Type: " + orderType
        }
        Label {
            font.pointSize: 20
            text: "Item width: " + itemWidth
        }
        Label {
            font.pointSize: 20
            text: "Item height: " + itemHeigh
        }
        Label {
            font.pointSize: 20
            text: "Item length: " + itemLength
        }

        Label {
            font.pointSize: 20
            text: "Price: " + orderPrice
        }

        Label {
            font.pointSize: 20
            text: "Sending date: " + orderSendingDate
        }
        Label {
            font.pointSize: 20
            text: "Start addres: " + startAddres
        }
        Label {
            font.pointSize: 20
            text: "Start addres: " + endAddres
        }
        Label {
            font.pointSize: 20
            text: "Description: " + orderDescriptiom
        }
        Rectangle{
            width: parent.width
            height: 1;
            color: "grey"

        }
        Label {
            font.pointSize: 20
            text: "Carrier company: " + companyName
        }
        Label {
            font.pointSize: 20
            text: "Carrier first name: " + driverFirstName
        }
        Label {
            font.pointSize: 20
            text: "Carrier last name: " + driverLastName
        }

        Button {
            id: rmoveButton
            contentItem: Text {
                text: parent.text
                font: parent.font
                opacity: enabled ? 1.0 : 0.3
                color: "white"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                elide: Text.ElideRight
            }


            width: parent.width
            text: qsTr("Close Order")
            enabled: isBtnActive

            Material.background: Material.Red // Change the background
            onClicked: {
                backEnd.removeOrder(orderId)
                adminDetailPage.StackView.view.pop()
            }

        }
    }
}
