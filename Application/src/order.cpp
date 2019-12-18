#include "order.h"

Order::Order(QString customerId,
        QString customerFirstName,
             QString customerSecondName,
             QString customerEmail,
                      QString description,
                    QString price,
                    QString fromAddress,
                    QString toAddress,
                    QString orderSendingDate,
                    QString orderItemName,
                      QString orderItemLength,
                    QString orderItemHeight,
                    QString orderItemWidth,
                    QString orderTypeName,
                    QString driverId,
                    QString driverFirstName,
                    QString driverSecondName,
                    QString driverEmail,
                    QString carNumber,
                    QString carModel,
                    QString companyName,
                    QString companyRegistrationDate,
                    QString shippingSendingDate,
                    QString shippingArrivalDate,
                    DBTypes::DBIndex id)
    : m_description {std::move(description)},
      m_price {std::move(price)},
      m_fromAddress {std::move(fromAddress)},
      m_toAddress {std::move(toAddress)},
      m_orderSendingDate {std::move(orderSendingDate)},
      m_orderItemName {std::move(orderItemName)},
      m_orderItemHeight {std::move(orderItemHeight)},
      m_orderItemWidth {std::move(orderItemWidth)},
      m_orderItemLength {std::move(orderItemLength)},
      m_orderTypeName {std::move(orderTypeName)},
      m_shippingSendingDate {std::move(shippingSendingDate)},
      m_shippingArrivalDate {std::move(shippingArrivalDate)},
      m_carNumber {std::move(carNumber)},
      m_carModel {std::move(carModel)},
      m_customerId {std::move(customerId)},
      m_companyName {std::move(companyName)},
      m_companyRegistrationDate {std::move(companyRegistrationDate)},
      m_driverId {std::move(driverId)},
      m_driverFirstName {std::move(driverFirstName)},
      m_driverSecondName {std::move(driverSecondName)},
      m_driverEmail {std::move(driverEmail)},
      m_customerFirstName {std::move(customerFirstName)},
      m_customerSecondName {std::move(customerSecondName)},
      m_customerEmail {std::move(customerEmail)},
      m_id {id}
{
}

QString Order::description() const
{
    return m_description;
}
QString Order::price() const
{
    return m_price;
}
QString Order::fromAddress() const
{
    return m_fromAddress;
}
QString Order::toAddress() const
{
    return m_toAddress;
}
QString Order::orderSendingDate() const
{
    return m_orderSendingDate;
}
QString Order::orderItemName() const
{
    return m_orderItemName;
}
QString Order::orderItemHeight() const
{
    return m_orderItemHeight;
}
QString Order::orderItemWidth() const
{
    return m_orderItemWidth;
}
QString Order::orderItemLength() const
{
    return m_orderItemLength;
}
QString Order::orderTypeName() const
{
    return m_orderTypeName;
}
QString Order::shippingSendingDate() const
{
    return m_shippingSendingDate;
}
QString Order::shippingArrivalDate() const
{
    return m_shippingArrivalDate;
}
QString Order::carNumber() const
{
    return m_carNumber;
}
QString Order::carModel() const
{
    return m_carModel;
}
QString Order::companyName() const
{
    return m_companyName;
}
QString Order::companyRegistrationDate() const
{
    return m_companyRegistrationDate;
}
QString Order::driverFirstName() const
{
    return m_driverFirstName;
}
QString Order::driverSecondName() const
{
    return m_driverSecondName;
}
QString Order::driverEmail() const
{
    return m_driverEmail;
}
QString Order::customerFirstName() const
{
    return m_customerFirstName;
}
QString Order::customerSecondName() const
{
    return m_customerSecondName;
}
QString Order::customerEmail() const
{
    return m_customerEmail;
}
QString Order::customerId() const
{
    return m_customerId;
}
QString Order::driverId() const
{
    return m_driverId;
}
