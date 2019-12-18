#include "ordermodel.h"
#include <QQmlEngine>
#include <QDebug>

OrderModel::OrderModel()
{
    updateOrders();
}

int OrderModel::assignOrderTODriver(int orderId, int driverId){

}

int OrderModel::createNewOrder(QString description,
                               QString price,
                               QString fromAddress,
                               QString toAddress,
                               QString orderSendingDate,
                               QString orderItemName,
                               QString orderItemHeight,
                               QString orderItemWidth,
                               QString orderItemLength,
                               QString orderTypeName,
                               QString shippingSendingDate,
                               QString shippingArrivalDate,
                               QString carNumber,
                               QString carModel,
                               QString companyName,
                               int customerId)
{


}

void OrderModel::registerMe(const std::string& moduleName)
{
    qmlRegisterType<OrderModel>(moduleName.c_str(), 1, 0, "OrderModel");
}

int OrderModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent)
    return static_cast<int>(m_orders.size());
}

QVariant OrderModel::data(const QModelIndex& index, int role) const
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

QHash<int, QByteArray> OrderModel::roleNames() const
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

bool OrderModel::updateOrders()
{
    bool requestResult {false};
    std::vector<Order> ordersResult;

    std::tie(requestResult, ordersResult) = m_reader.requestOrdersBrowse();

    if (requestResult) {
        m_orders.swap(ordersResult);
        emit dataChanged(createIndex(0, 0), createIndex(m_orders.size(), 0));
    }
    emit QAbstractListModel::endResetModel();
    return requestResult;
}
