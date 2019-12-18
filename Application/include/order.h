#pragma once
#include <QString>
#include <QVariant>
#include "dbtypes.h"

class Order
{
public:
    Order() = default;
    Order(QString description, QString price, QString fromAddress, QString toAddress,
          QString orderSendingDate, QString orderItemName, QString orderItemHeight, QString orderItemWidth,
          QString orderItemLength, QString orderTypeName, QString shippingSendingDate, QString shippingArrivalDate,
          QString carNumber, QString carModel, QString companyName, QString companyRegistrationDate, QString driverId,
          QString driverFirstName, QString driverSecondName, QString driverEmail, QString custimerId, QString customerFirstName,
          QString customerSecondName, QString customerEmail, DBTypes::DBIndex id);

    QString description() const;
    QString price() const;
    QString fromAddress() const;
    QString toAddress() const;
    QString orderSendingDate() const;
    QString orderItemName() const;
    QString orderItemHeight() const;
    QString orderItemWidth() const;
    QString orderItemLength() const;
    QString orderTypeName() const;
    QString shippingSendingDate() const;
    QString shippingArrivalDate() const;
    QString carNumber() const;
    QString carModel() const;
    QString companyName() const;
    QString companyRegistrationDate() const;
    QString driverId() const;
    QString driverFirstName() const;
    QString driverSecondName() const;
    QString driverEmail() const;
    QString customerId() const;
    QString customerFirstName() const;
    QString customerSecondName() const;
    QString customerEmail() const;
    QString m_description;
    QString m_price;
    QString m_fromAddress;
    QString m_toAddress;
    QString m_orderSendingDate;
    QString m_orderItemName;
    QString m_orderItemHeight;
    QString m_orderItemWidth;
    QString m_orderItemLength;
    QString m_orderTypeName;
    QString m_shippingSendingDate;
    QString m_shippingArrivalDate;
    QString m_carNumber;
    QString m_carModel;
    QString m_companyName;
    QString m_companyRegistrationDate;
    QString m_driverFirstName;
    QString m_driverSecondName;
    QString m_driverEmail;
    QString m_customerFirstName;
    QString m_customerSecondName;
    QString m_customerEmail;
    QString m_customerId;
    QString m_driverId;
    DBTypes::DBIndex m_id;
};
