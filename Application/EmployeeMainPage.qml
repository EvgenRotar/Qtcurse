import QtQuick 2.6
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2
import QtQuick.Layouts 1.1
import EmployeeOrders 1.0

Page {
    EmployeeOrderModel {
        id: backEnd
        activeCustomer: 0
    }
    id: userMainPage
    property int userId
    header: ToolBar {
        ToolButton {
            text: qsTr("LogOut")
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.verticalCenter: parent.verticalCenter
            onClicked: userMainPage.StackView.view.pop()
        }
        Label {
            text: qsTr("Active orders")
            font.pixelSize: 20
            anchors.centerIn: parent
        }
    }
    TabBar {
        id: tabBar
        width: userMainPage.widh

        currentIndex: view.currentIndex

        TabButton {
            enabled: false
            width: userMainPage.width / 2
            text: qsTr("Open orders")
        }

        TabButton {
            enabled: false
            width: userMainPage.width / 2
            text: qsTr("My orders")
        }
    }

    SwipeView {
        id: view
        anchors.topMargin: 60
        currentIndex: 0
        anchors.fill: parent
        onCurrentIndexChanged: {
            var ind = view.currentIndex
            if(ind === 0 ){
                backEnd.setActiveUserId(0)
            }
            if(ind === 1){
                backEnd.setActiveUserId(userId)
            }
        }

        Item {
            id: firstPage
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
                        height: 125
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
                                text: "Start addres: " + OrderFromAddress
                            }
                            Label {
                                text: "End addres: " + OrderToAddress
                            }
                            Rectangle {
                                width: mainUserListView.width - mainUserListView.leftMargin
                                       - mainUserListView.rightMargin
                                height: 1
                                color: "grey"
                            }
                        }
                        onClicked: userMainPage.StackView.view.push("qrc:/EmployeeMainOrderDetails.qml",{
                                                                        customerId: userId,
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
                                                                        backEnd: backEnd
                                                                    })
                    }
                }
            }
        }
        Item {

            id: secondPage
            ColumnLayout {
                anchors.fill: parent
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                ListView {
                    id: likedUserListView
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
                        height: 125
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
                                text: "Start addres: " + OrderFromAddress
                            }
                            Label {
                                text: "End addres: " + OrderToAddress
                            }
                            Rectangle {
                                width: mainUserListView.width - mainUserListView.leftMargin
                                       - mainUserListView.rightMargin
                                height: 1
                                color: "grey"
                            }
                        }
                        onClicked: userMainPage.StackView.view.push("qrc:/EmployeePersonalOrderDetails.qml",{
                                                                        customerId: userId,
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
                                                                        backEnd: backEnd
                                                                    })
                    }
                }
            }
        }
    }
}
