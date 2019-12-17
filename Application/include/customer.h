#pragma once
#include <QString>
#include <QVariant>
#include "dbtypes.h"

class Customer
{
public:
    Customer() = default;

    Customer(QString customerFirstName, QString customerSecondName, QString customerEmail, QString orderDescription, QString orderPrice,
             QString orderFromAddress, QString orderToAddress, QString orderSendingDate, QString orderItemName,
             QString orderItemLength, QString orderItemHeight, QString orderItemWidth, QString orderTypeName,
             QString driverFirstName, QString driverLastName, QString driverEmail, QString carNumber,
             QString carModel, QString companyName, QString companyRegistrationDate, QString shippingSendingDate,
             QString shippingArrivalDate, DBTypes::DBIndex id);

    QString customerFirstName() const;
    QString customerSecondName() const;
    QString customerEmail() const;
    QString orderDescription() const;
    QString orderPrice() const;
    QString orderFromAddress() const;
    QString orderToAddress() const;
    QString orderSendingDate() const;
    QString orderItemName() const;
    QString orderItemLength() const;
    QString orderItemHeight() const;
    QString orderItemWidth() const;
    QString orderTypeName() const;
    QString driverFirstName() const;
    QString driverLastName() const;
    QString driverEmail() const;
    QString carNumber() const;
    QString carModel() const;
    QString companyName() const;
    QString companyRegistrationDate() const;
    QString shippingSendingDate() const;
    QString shippingArrivalDate() const;
    QString m_customerFirstName;
    QString m_customerSecondName;
    QString m_customerEmail;
    QString m_orderDescription;
    QString m_orderPrice;
    QString m_orderFromAddress;
    QString m_orderToAddress;
    QString m_orderSendingDate;
    QString m_orderItemName;
    QString m_orderItemLength;
    QString m_orderItemHeight;
    QString m_orderItemWidth;
    QString m_orderTypeName;
    QString m_driverFirstName;
    QString m_driverLastName;
    QString m_driverEmail;
    QString m_carNumber;
    QString m_carModel;
    QString m_companyName;
    QString m_companyRegistrationDate;
    QString m_shippingSendingDate;
    QString m_shippingArrivalDate;
    DBTypes::DBIndex m_id;
};

