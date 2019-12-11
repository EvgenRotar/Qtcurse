#pragma once
#include <QAbstractListModel>
#include "order.h"
#include "orderreader.h"

class OrderModel : public QAbstractListModel
{
    Q_OBJECT
public:
    OrderModel();
    static void registerMe(const std::string& moduleName);
    int rowCount(const QModelIndex& parent = {}) const override;
    QVariant data(const QModelIndex& index = {}, int role = Qt::DisplayRole) const override;

    QHash<int, QByteArray> roleNames() const override;

private:
    std::vector<Order> m_orders;
    OrderReader m_reader;

    enum OrderRoles
    {
        DescriptionRole,
        PriceRole,
        FromAddressRole,
        ToAddressRole,
        OrderSendingDateRole,
        OrderItemNameRole,
        OrderItemHeightRole,
        OrderItemWidthRole,
        OrderItemLengthRole,
        OrderTypeNameRole,
        ShippingSendingDateRole,
        ShippingArrivalDateRole,
        CarNumberRole,
        CarModelRole,
        CompanyNameRole,
        CompanyRegistrationDateRole,
        DriverFirstNameRole,
        DriverSecondNameRole,
        DriverEmailRole,
        CustomerFirstNameRole,
        CustomerSecondNameRole,
        CustomerEmailRole
    };

    bool updateOrders();

};
