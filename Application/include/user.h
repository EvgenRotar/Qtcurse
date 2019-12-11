#pragma once
#include <QString>
#include <QVariant>
#include "dbtypes.h"

class User
{
public:
    User() = default;
    User(QString firstName, QString secondName, QString email, QString password, DBTypes::DBIndex id);
    QString firstName() const;
    QString secondName() const;
    QString email() const;
    QString password() const;
    QString role() const;

private:
    QString m_email;
    QString m_firstName;
    QString m_secondName;
    QString m_password;
    QString m_role;
    DBTypes::DBIndex m_id;
};
