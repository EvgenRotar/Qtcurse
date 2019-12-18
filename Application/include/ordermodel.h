#pragma once
#include <QAbstractListModel>
#include "order.h"
#include "orderreader.h"

class OrderModel : public QAbstractListModel
{
    Q_OBJECT
public:
    OrderModel();

    Q_INVOKABLE int createNewOrder(QString description,
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
                                   int customerId);//TBD
    Q_INVOKABLE int assignOrderTODriver(int orderId, int driverId);

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

};
