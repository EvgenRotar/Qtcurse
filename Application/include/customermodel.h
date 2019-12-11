#pragma once
#include <QAbstractListModel>
#include "customer.h"
#include "customerreader.h"

class CustomerModel : public QAbstractListModel
{
    Q_OBJECT
public:
    CustomerModel();
    static void registerMe(const std::string& moduleName);
    int rowCount(const QModelIndex& parent = {}) const override;
    QVariant data(const QModelIndex& index = {}, int role = Qt::DisplayRole) const override;

    QHash<int, QByteArray> roleNames() const override;

private:
    std::vector<Customer> m_customers;
    CustomerReader m_reader;

    enum CustomerRoles
    {
        CustomerFirstNameRole,
        CustomerSecondNameRole,
        CustomerEmailRole,
        OrderDescriptionRole,
        OrderPriceRole,
        OrderFromAddressRole,
        OrderToAddressRole,
        OrderSendingDateRole,
        OrderItemNameRole,
        OrderItemLengthRole,
        OrderItemHeightRole,
        OrderItemWidthRole,
        OrderTypeNameRole,
        DriverFirstNameRole,
        DriverLastNameRole,
        DriverEmailRole,
        CarNumberRole,
        CarModelRole,
        CompanyNameRole,
        CompanyRegistrationDateRole,
        ShippingSendingDateRole,
        ShippingArrivalDateRole
    };

    std::pair<bool,
              std::vector<Customer>> getOrdersByCustomerId(const int& customerId);

    std::pair<bool,
              std::vector<Customer>> getOrderByOrderId(const int& orderId);

    std::pair<bool,
              std::vector<Customer>> getOrdersByDriverId(const int& driverId);

    bool dosmth();

};

