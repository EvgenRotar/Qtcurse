import QtQuick 2.6
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2
import QtQuick.Layouts 1.1
import CustomerOrders 1.0

Page {
    Material.accent: Material.Cyan
    CustomerOrderModel {
        activeCustomer: customerId
        id: backEnd
    }

    id: adminMainPage
    property int customerId
    header: ToolBar {
        Material.background: Material.Cyan
        ToolButton {
            text: qsTr("LogOut")
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.verticalCenter: parent.verticalCenter
            onClicked: adminMainPage.StackView.view.pop()
        }
        Label {
            text: qsTr("My open orders")
            font.pixelSize: 20
            anchors.centerIn: parent
        }
    }
    ColumnLayout {
        anchors.fill: parent
        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        ListView {
            id: mainUserListView
            visible: true
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.margins: 15
            displayMarginBeginning: -60
            displayMarginEnd: 0
            verticalLayoutDirection: ListView.TopToBottom
            spacing: 10
            model: backEnd
            ScrollBar.vertical: ScrollBar {
            }
            delegate: ItemDelegate {
                width: mainUserListView.width - mainUserListView.leftMargin
                       - mainUserListView.rightMargin
                height: 100
                spacing: 10
                Column {
                    spacing: 8
                    Label {
                        text: "Order item: " + OrderItemName
                    }
                    Label {
                        text: "Order price: " + OrderPrice
                    }
                    Label {
                        text: "Sending date: " + OrderSendingDate
                    }

                    Label {
                        text: "Assigned to Driver: " + IsAssigned
                    }
                    Rectangle {
                        width: mainUserListView.width - mainUserListView.leftMargin
                               - mainUserListView.rightMargin
                        height: 1
                        color: "grey"
                    }
                }
                onClicked: {
                    var isBtnActive
                    isBtnActive = true
                    if (IsAssigned === "Assigned")
                        isBtnActive = false

                    adminMainPage.StackView.view.push(
                                "qrc:/CustomerOrderDetails.qml", {
                                    customerId: customerId,
                                    orderId: dbId,
                                    orderAssigned: IsAssigned,
                                    orderDescriptiom: OrderDescription,
                                    orderPrice: OrderPrice,
                                    orderSendingDate: OrderSendingDate,
                                    orderType: OrderTypeName,
                                    itemName: OrderItemName,
                                    itemHeigh: OrderItemHeight,
                                    itemWidth: OrderItemWidth,
                                    itemLength: OrderItemLength,
                                    startAddres: OrderFromAddress,
                                    endAddres: OrderToAddress,
                                    driverFirstName: DriverFirstName,
                                    driverLastName: DriverLastName,
                                    companyName: CompanyName,
                                    backEnd: backEnd,
                                    isBtnActive: isBtnActive
                                })
                }
            }
        }
    }

    RoundButton {
        text: "\uff0b" // Unicode Character 'CHECK MARK'
        width: 80
        height: 80
        Material.background: Material.Cyan
        anchors.bottomMargin: 20
        anchors.rightMargin: 20
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        onClicked: {
            adminMainPage.StackView.view.push("qrc:/CustomerCreateOrder.qml", {
                                                  bakcAccess: backEnd,
                                                  customerIdd: customerId
                                              })
        }
    }
}
