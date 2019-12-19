#include <QAbstractListModel>
#include "order.h"
#include "orderreader.h"

class CustomerOrderModel : public QAbstractListModel
{
    Q_OBJECT
public:
    CustomerOrderModel();
    Q_PROPERTY(int activeCustomer READ getActiveCustomer WRITE setActiveCustomer)
    int getActiveCustomer();
    void setActiveCustomer(int custId);

    Q_INVOKABLE int createNewOrder(int orderType,int customerId,
                                   QString description, QString price,
                                   QString fromAddress, QString toAddress,
                                   QString sendingDate, QString orderItemName,
                                   QString length, QString width,
                                   QString height);
    static void registerMe(const std::string& moduleName);
    int rowCount(const QModelIndex& parent = {}) const override;
    QVariant data(const QModelIndex& index = {}, int role = Qt::DisplayRole) const override;

    QHash<int, QByteArray> roleNames() const override;

private:
    QList<Order> m_orders;
    OrderReader m_reader;
    int m_ActiveCustomerId;
    void updateOrders();

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
