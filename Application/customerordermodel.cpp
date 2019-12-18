#include "customerordermodel.h"
#include <QQmlEngine>
#include <QDebug>

CustomerOrderModel::CustomerOrderModel()
{
    updateOrders();
}

void CustomerOrderModel::updateOrders(){
   //QList<Order> CustomerOrders = m_reader.getCustomerOrders(m_ActiveCustomerId);
    QList<Order> CustomerOrders = m_reader.getAssignedToEmployeeOrders(3);
    m_orders = CustomerOrders;
    emit QAbstractListModel::endResetModel();
}

void CustomerOrderModel::setActiveCustomer(int custId){
    m_ActiveCustomerId = custId;
    updateOrders();
}

int CustomerOrderModel::getActiveCustomer(){
   return m_ActiveCustomerId;
}


int CustomerOrderModel::createNewOrder(int orderType,int customerId,
                                       QString description, QString price,
                                       QString fromAddress, QString toAddress,
                                       QString sendingDate, QString orderItemName,
                                       QString length, QString width,
                                       QString height)
{

    updateOrders();
}

void CustomerOrderModel::registerMe(const std::string& moduleName)
{
    qmlRegisterType<CustomerOrderModel>(moduleName.c_str(), 1, 0, "CustomerOrderModel");
}

int CustomerOrderModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent)
    return static_cast<int>(m_orders.size());
}

QVariant CustomerOrderModel::data(const QModelIndex& index, int role) const
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
        default: {
            return {};
        }
    }
}

QHash<int, QByteArray> CustomerOrderModel::roleNames() const
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
    return roles;
}
