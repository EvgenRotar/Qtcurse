import QtQuick 2.6
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2
import QtQuick.Layouts 1.1
import CustomerOrders 1.0

Page {
    id: createOrderPage
    property int userId
    header: ToolBar {
        ToolButton {
            text: qsTr("Back")
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.verticalCenter: parent.verticalCenter
            onClicked: createOrderPage.StackView.view.pop()
        }
        Label {
            text: qsTr("Create new Order")
            font.pixelSize: 20
            anchors.centerIn: parent
        }
        Column {
            anchors.centerIn: parent
            width: parent.width - 50
            height: parent.height - 150

            TextField {
                onFocusChanged: wrongfields.visible = false
                id: orderItemName
                Layout.fillWidth: true
                width: parent.width
                color: "black"
                placeholderText: qsTr("Order Item Name")
            }

            TextField {
                onFocusChanged: wrongfields.visible = false
                id: startAddres
                Layout.fillWidth: true
                width: parent.width
                color: "black"
                placeholderText: qsTr("Start addres")
            }

            TextField {
                onFocusChanged: wrongfields.visible = false
                id: endAddres
                Layout.fillWidth: true
                width: parent.width
                color: "black"
                placeholderText: qsTr("End addres")
            }

            TextField {
                onFocusChanged: wrongfields.visible = false
                id: sendingDate
                Layout.fillWidth: true
                width: parent.width
                color: "black"
                placeholderText: qsTr("Sending date")
            }

            TextField {
                onFocusChanged: wrongfields.visible = false
                id: price
                Layout.fillWidth: true
                width: parent.width
                color: "black"
                placeholderText: qsTr("Price")
            }

            TextField {
                onFocusChanged: wrongfields.visible = false
                id: itemLength
                Layout.fillWidth: true
                width: parent.width
                color: "black"
                placeholderText: qsTr("Length")
            }

            TextField {
                onFocusChanged: wrongfields.visible = false
                id: itemHeight
                Layout.fillWidth: true
                width: parent.width
                color: "black"
                placeholderText: qsTr("Heigh")
            }

            TextField {
                onFocusChanged: wrongfields.visible = false
                id: itemWidth
                Layout.fillWidth: true
                width: parent.width
                color: "black"
                placeholderText: qsTr("Width")
            }

            TextField {
                onFocusChanged: wrongfields.visible = false
                id: description
                Layout.fillWidth: true
                width: parent.width
                color: "black"
                placeholderText: qsTr("Description")
            }

            ComboBox{
                id: cbItems
                Layout.fillWidth: true
                width: parent.width
                currentIndex: 1

                model: ListModel {


                        ListElement { text: "Fragile" }
                        ListElement { text: "Not Fragile"}
                    }

            }
            Text {
                onFocusChanged: wrongfields.visible = false
                visible: false
                id: wrongfields
                color: "red"
                text: qsTr("Please fill all fields correctly.")
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
                id: backLogIn
                width: parent.width
                text: qsTr("Create and save movie")

                Material.background: Material.Pink // Change the background
                onClicked: {
                    if(orderItemName.length ===0){wrongfields.visible = true; return}
                    if(startAddres.length ===0){wrongfields.visible = true; return}
                    if(endAddres.length ===0){wrongfields.visible = true; return}
                    if(sendingDate.length ===0){wrongfields.visible = true; return}
                    if(price.length ===0){wrongfields.visible = true; return}
                    if(itemLength.length ===0){wrongfields.visible = true; return}
                    if(itemHeight.length ===0){wrongfields.visible = true; return}
                    if(itemWidth.length ===0){wrongfields.visible = true; return}
                    var requestResult = CustomerOrderModel.createNewOrder(cbItems.currentIndex,userId,
                                                                   description.text,price.text,
                                                                   startAddres.text,endAddres.text,
                                                                   sendingDate.text,orderItemName.text,
                                                                   itemLength.text,itemWidth.text,itemHeight.text)
                    if(requestResult !== 0){
                        succsess.visible = true
                        return
                    }

                }
            }
        }
    }
}
