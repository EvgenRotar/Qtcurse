#include "employeeordermodel.h"
#include <QQmlEngine>
#include <QDebug>

EmployeeOrderModel::EmployeeOrderModel()
{
    updateOrders();
}

void EmployeeOrderModel::removeOrder(int orderId){
    m_reader.deleteOrder(orderId);
     updateOrders();
}

void EmployeeOrderModel::setActiveUserId(int userId){
    setActiveCustomer(userId);
}

void EmployeeOrderModel::updateOrders(){
    QList<Order> CustomerOrders;
    if(m_ActiveCustomerId == 0){

        CustomerOrders = m_reader.getAllOrders();

    } else{

        CustomerOrders = m_reader.getAssignedToEmployeeOrders(m_ActiveCustomerId);
    }

    m_orders = CustomerOrders;
    emit QAbstractListModel::endResetModel();
}

void EmployeeOrderModel::setActiveCustomer(int custId){
    m_ActiveCustomerId = custId;
    updateOrders();
}

int EmployeeOrderModel::getActiveCustomer(){
   return m_ActiveCustomerId;
}


int EmployeeOrderModel::createNewOrder(int orderType,int customerId,
                                       QString description, QString price,
                                       QString fromAddress, QString toAddress,
                                       QString sendingDate, QString orderItemName,
                                       QString length, QString width,
                                       QString height)
{
    int result = m_reader.addOrder(orderType ,customerId,description.toStdString() ,price.toInt(),
                                   fromAddress.toStdString(),toAddress.toStdString(),
                                   sendingDate.toStdString(),orderItemName.toStdString(),
                                   length.toInt(),width.toInt(),height.toInt());
    updateOrders();
    return result;
}

void EmployeeOrderModel::registerMe(const std::string& moduleName)
{
    qmlRegisterType<EmployeeOrderModel>(moduleName.c_str(), 1, 0, "EmployeeOrderModel");
}

int EmployeeOrderModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent)
    return static_cast<int>(m_orders.size());
}

QVariant EmployeeOrderModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid() || index.row() > rowCount(index)) {
        return {};
    }

    const Order& order = m_orders.at(index.row());

    switch (role) {
        case OrderRoles::CustomerFirstNameRole: {
            return QVariant::fromValue(order.customerFirstName());
        }
        case OrderRoles::CustomerSecondNameRole: {
            return QVariant::fromValue(order.customerSecondName());
        }
        case OrderRoles::CustomerEmailRole: {
            return QVariant::fromValue(order.customerEmail());
        }
        case OrderRoles::DescriptionRole: {
            return QVariant::fromValue(order.description());
        }
        case OrderRoles::PriceRole: {
            return QVariant::fromValue(order.price());
        }
        case OrderRoles::FromAddressRole: {
            return QVariant::fromValue(order.fromAddress());
        }
        case OrderRoles::ToAddressRole: {
            return QVariant::fromValue(order.toAddress());
        }
        case OrderRoles::OrderSendingDateRole: {
            return QVariant::fromValue(order.orderSendingDate());
        }
        case OrderRoles::OrderItemNameRole: {
            return QVariant::fromValue(order.orderItemName());
        }
        case OrderRoles::OrderItemLengthRole: {
            return QVariant::fromValue(order.orderItemLength());
        }
        case OrderRoles::OrderItemHeightRole: {
            return QVariant::fromValue(order.orderItemHeight());
        }
        case OrderRoles::OrderItemWidthRole: {
            return QVariant::fromValue(order.orderItemWidth());
        }
        case OrderRoles::OrderTypeNameRole: {
            return QVariant::fromValue(order.orderTypeName());
        }
        case OrderRoles::DriverFirstNameRole: {
            return QVariant::fromValue(order.driverFirstName());
        }
        case OrderRoles::DriverSecondNameRole: {
            return QVariant::fromValue(order.driverSecondName());
        }
        case OrderRoles::DriverEmailRole: {
            return QVariant::fromValue(order.driverEmail());
        }
        case OrderRoles::CarNumberRole: {
            return QVariant::fromValue(order.carNumber());
        }
        case OrderRoles::CarModelRole: {
            return QVariant::fromValue(order.carModel());
        }
        case OrderRoles::CompanyNameRole: {
            return QVariant::fromValue(order.companyName());
        }
        case OrderRoles::CompanyRegistrationDateRole: {
            return QVariant::fromValue(order.companyRegistrationDate());
        }
        case OrderRoles::ShippingSendingDateRole: {
            return QVariant::fromValue(order.shippingSendingDate());
        }
        case OrderRoles::ShippingArrivalDateRole: {
            return QVariant::fromValue(order.shippingArrivalDate());
        }
        case OrderRoles::dbIdRole: {
            return QVariant::fromValue(order.m_id);
        }
        case OrderRoles::isAssignedRole:{
            if(order.driverId() == 0) return QVariant::fromValue(QString::fromStdString("Not Assigned"));
            return QVariant::fromValue(QString::fromStdString("Assigned"));
        }

        default: {
            return {};
        }
    }
}

QHash<int, QByteArray> EmployeeOrderModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[OrderRoles::CustomerFirstNameRole] = "CustomerFirstName";
    roles[OrderRoles::CustomerSecondNameRole] = "CustomerSecondName";
    roles[OrderRoles::CustomerEmailRole] = "CustomerEmail";
    roles[OrderRoles::DescriptionRole] = "OrderDescription";
    roles[OrderRoles::PriceRole] = "OrderPrice";
    roles[OrderRoles::FromAddressRole] = "OrderFromAddress";
    roles[OrderRoles::ToAddressRole] = "OrderToAddress";
    roles[OrderRoles::OrderSendingDateRole] = "OrderSendingDate";
    roles[OrderRoles::OrderItemNameRole] = "OrderItemName";
    roles[OrderRoles::OrderItemLengthRole] = "OrderItemLength";
    roles[OrderRoles::OrderItemHeightRole] = "OrderItemHeight";
    roles[OrderRoles::OrderItemWidthRole] = "OrderItemWidth";
    roles[OrderRoles::OrderTypeNameRole] = "OrderTypeName";
    roles[OrderRoles::DriverFirstNameRole] = "DriverFirstName";
    roles[OrderRoles::DriverSecondNameRole] = "DriverLastName";
    roles[OrderRoles::DriverEmailRole] = "DriverEmail";
    roles[OrderRoles::CarNumberRole] = "CarNumber";
    roles[OrderRoles::CarModelRole] = "CarModel";
    roles[OrderRoles::CompanyNameRole] = "CompanyName";
    roles[OrderRoles::CompanyRegistrationDateRole] = "CompanyRegistrationDate";
    roles[OrderRoles::ShippingSendingDateRole] = "ShippingSendingDate";
    roles[OrderRoles::ShippingArrivalDateRole] = "ShippingArrivalDate";
    roles[OrderRoles::isAssignedRole] = "IsAssigned";
    roles[OrderRoles::dbIdRole] = "dbId";
    return roles;
}
