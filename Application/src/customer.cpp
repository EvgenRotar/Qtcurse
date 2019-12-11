#include "customer.h"

Customer::Customer(QString customerFirstName, QString customerSecondName, QString customerEmail, QString orderDescription, QString orderPrice,
                   QString orderFromAddress, QString orderToAddress, QString orderSendingDate, QString orderItemName,
                   QString orderItemLength, QString orderItemHeight, QString orderItemWidth, QString orderTypeName,
                   QString driverFirstName, QString driverLastName, QString driverEmail, QString carNumber,
                   QString carModel, QString companyName, QString companyRegistrationDate, QString shippingSendingDate,
                   QString shippingArrivalDate, DBTypes::DBIndex id)
    : m_customerFirstName {std::move(customerFirstName)},
      m_customerSecondName {std::move(customerSecondName)},
      m_customerEmail {std::move(customerEmail)},
      m_orderDescription {std::move(orderDescription)},
      m_orderPrice {std::move(orderPrice)},
      m_orderFromAddress {std::move(orderFromAddress)},
      m_orderToAddress {std::move(orderToAddress)},
      m_orderSendingDate {std::move(orderSendingDate)},
      m_orderItemName {std::move(orderItemName)},
      m_orderItemLength {std::move(orderItemLength)},
      m_orderItemHeight {std::move(orderItemHeight)},
      m_orderItemWidth {std::move(orderItemWidth)},
      m_orderTypeName {std::move(orderTypeName)},
      m_driverFirstName {std::move(driverFirstName)},
      m_driverLastName {std::move(driverLastName)},
      m_driverEmail {std::move(driverEmail)},
      m_carNumber {std::move(carNumber)},
      m_carModel {std::move(carModel)},
      m_companyName {std::move(companyName)},
      m_companyRegistrationDate {std::move(companyRegistrationDate)},
      m_shippingSendingDate {std::move(shippingSendingDate)},
      m_shippingArrivalDate {std::move(shippingArrivalDate)},
      m_id {id}
{
}

QString Customer::customerFirstName() const
{
    return m_customerFirstName;
}
QString Customer::customerSecondName() const
{
    return m_customerSecondName;
}
QString Customer::customerEmail() const
{
    return m_customerEmail;
}
QString Customer::orderDescription() const
{
    return m_orderDescription;
}
QString Customer::orderPrice() const
{
    return m_orderPrice;
}
QString Customer::orderFromAddress() const
{
    return m_orderFromAddress;
}
QString Customer::orderToAddress() const
{
    return m_orderToAddress;
}
QString Customer::orderSendingDate() const
{
    return m_orderSendingDate;
}
QString Customer::orderItemName() const
{
    return m_orderItemName;
}
QString Customer::orderItemLength() const
{
    return m_orderItemLength;
}
QString Customer::orderItemHeight() const
{
    return m_orderItemHeight;
}
QString Customer::orderItemWidth() const
{
    return m_orderItemWidth;
}
QString Customer::orderTypeName() const
{
    return m_orderTypeName;
}
QString Customer::driverFirstName() const
{
    return m_driverFirstName;
}
QString Customer::driverLastName() const
{
    return m_driverLastName;
}
QString Customer::driverEmail() const
{
    return m_driverEmail;
}
QString Customer::carNumber() const
{
    return m_carNumber;
}
QString Customer::carModel() const
{
    return m_carModel;
}
QString Customer::companyName() const
{
    return m_companyName;
}
QString Customer::companyRegistrationDate() const
{
    return m_companyRegistrationDate;
}
QString Customer::shippingSendingDate() const
{
    return m_shippingSendingDate;
}
QString Customer::shippingArrivalDate() const
{
    return m_shippingArrivalDate;
}
