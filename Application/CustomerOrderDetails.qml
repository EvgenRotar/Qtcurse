import QtQuick 2.6
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2
import QtQuick.Layouts 1.1
import CustomerOrders 1.0



Page {
    onActiveFocusChanged: {
        if(backEnd.orderAssigned(orderId)){
            rmoveButton.enabled = true
        } else{
            rmoveButton.enabled = false
        }
    }


    id: adminDetailPage
    property var orderId
    property var activeCustomer
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
    CustomerOrderModel{
        id: backEnd
        activeCustomer: activeCustomer
    }

    Column {
        anchors.centerIn: parent
        width: parent.width - 50
        height: parent.height - 50
        spacing: 10

        Label {
            font.pointSize: 20
            text: "Price: " + backEnd.data(orderId)
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

            Material.background: Material.Red // Change the background
            onClicked: {
            }
        }
    }
}
