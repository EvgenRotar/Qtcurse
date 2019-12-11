#include "customermodel.h"
#include <QQmlEngine>
#include <QDebug>

CustomerModel::CustomerModel()
{
    dosmth();
    if (true) {
        qWarning() << "created customer model";
    }
}

void CustomerModel::registerMe(const std::string& moduleName)
{
    qmlRegisterType<CustomerModel>(moduleName.c_str(), 1, 0, "CustomerModel");
}

int CustomerModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent)
    return static_cast<int>(m_customers.size());
}

QVariant CustomerModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid() || index.row() > rowCount(index)) {
        return {};
    }

    const Customer& customer = m_customers.at(index.row());

    switch (role) {
        case CustomerRoles::CustomerFirstNameRole: {
            return QVariant::fromValue(customer.customerFirstName());
        }
        case CustomerRoles::CustomerSecondNameRole: {
            return QVariant::fromValue(customer.customerSecondName());
        }
        case CustomerRoles::CustomerEmailRole: {
            return QVariant::fromValue(customer.customerEmail());
        }
        case CustomerRoles::OrderDescriptionRole: {
            return QVariant::fromValue(customer.orderDescription());
        }
        case CustomerRoles::OrderPriceRole: {
            return QVariant::fromValue(customer.orderPrice());
        }
        case CustomerRoles::OrderFromAddressRole: {
            return QVariant::fromValue(customer.orderFromAddress());
        }
        case CustomerRoles::OrderToAddressRole: {
            return QVariant::fromValue(customer.orderToAddress());
        }
        case CustomerRoles::OrderSendingDateRole: {
            return QVariant::fromValue(customer.orderSendingDate());
        }
        case CustomerRoles::OrderItemNameRole: {
            return QVariant::fromValue(customer.orderItemName());
        }
        case CustomerRoles::OrderItemLengthRole: {
            return QVariant::fromValue(customer.orderItemLength());
        }
        case CustomerRoles::OrderItemHeightRole: {
            return QVariant::fromValue(customer.orderItemHeight());
        }
        case CustomerRoles::OrderItemWidthRole: {
            return QVariant::fromValue(customer.orderItemWidth());
        }
        case CustomerRoles::OrderTypeNameRole: {
            return QVariant::fromValue(customer.orderTypeName());
        }
        case CustomerRoles::DriverFirstNameRole: {
            return QVariant::fromValue(customer.driverFirstName());
        }
        case CustomerRoles::DriverLastNameRole: {
            return QVariant::fromValue(customer.driverLastName());
        }
        case CustomerRoles::DriverEmailRole: {
            return QVariant::fromValue(customer.driverEmail());
        }
        case CustomerRoles::CarNumberRole: {
            return QVariant::fromValue(customer.carNumber());
        }
        case CustomerRoles::CarModelRole: {
            return QVariant::fromValue(customer.carModel());
        }
        case CustomerRoles::CompanyNameRole: {
            return QVariant::fromValue(customer.companyName());
        }
        case CustomerRoles::CompanyRegistrationDateRole: {
            return QVariant::fromValue(customer.companyRegistrationDate());
        }
        case CustomerRoles::ShippingSendingDateRole: {
            return QVariant::fromValue(customer.shippingSendingDate());
        }
        case CustomerRoles::ShippingArrivalDateRole: {
            return QVariant::fromValue(customer.shippingArrivalDate());
        }
        default: {
            return {};
        }
    }
}

QHash<int, QByteArray> CustomerModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[CustomerRoles::CustomerFirstNameRole] = "CustomerFirstName";
    roles[CustomerRoles::CustomerSecondNameRole] = "CustomerSecondName";
    roles[CustomerRoles::CustomerEmailRole] = "CustomerEmail";
    roles[CustomerRoles::OrderDescriptionRole] = "OrderDescription";
    roles[CustomerRoles::OrderPriceRole] = "OrderPrice";
    roles[CustomerRoles::OrderFromAddressRole] = "OrderFromAddress";
    roles[CustomerRoles::OrderToAddressRole] = "OrderToAddress";
    roles[CustomerRoles::OrderSendingDateRole] = "OrderSendingDate";
    roles[CustomerRoles::OrderItemNameRole] = "OrderItemName";
    roles[CustomerRoles::OrderItemLengthRole] = "OrderItemLength";
    roles[CustomerRoles::OrderItemHeightRole] = "OrderItemHeight";
    roles[CustomerRoles::OrderItemWidthRole] = "OrderItemWidth";
    roles[CustomerRoles::OrderTypeNameRole] = "OrderTypeName";
    roles[CustomerRoles::DriverFirstNameRole] = "DriverFirstName";
    roles[CustomerRoles::DriverLastNameRole] = "DriverLastName";
    roles[CustomerRoles::DriverEmailRole] = "DriverEmail";
    roles[CustomerRoles::CarNumberRole] = "CarNumber";
    roles[CustomerRoles::CarModelRole] = "CarModel";
    roles[CustomerRoles::CompanyNameRole] = "CompanyName";
    roles[CustomerRoles::CompanyRegistrationDateRole] = "CompanyRegistrationDate";
    roles[CustomerRoles::ShippingSendingDateRole] = "ShippingSendingDate";
    roles[CustomerRoles::ShippingArrivalDateRole] = "ShippingArrivalDate";
    return roles;
}

bool CustomerModel::dosmth()
{
    bool requestResult {false};
    std::vector<Customer> customerResult;

    std::tie(requestResult, customerResult) = m_reader.requestAllByDriverIdBrowse(3);

    if (requestResult) {
        m_customers.swap(customerResult);
        emit dataChanged(createIndex(0, 0), createIndex(m_customers.size(), 0));
    }
    return true;
}
