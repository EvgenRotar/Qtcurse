#include "user.h"

User::User(QString firstName, QString secondName, QString email, QString password, QString role, DBTypes::DBIndex id)
    : m_email {std::move(email)},
      m_password {std::move(password)},
      m_firstName {std::move(firstName)},
      m_secondName {std::move(secondName)},
      m_role {std::move(role)},
      m_id {id}
{
}

QString User::firstName() const
{
    return m_firstName;
}
QString User::secondName() const
{
    return m_secondName;
}
QString User::email() const
{
    return m_email;
}
QString User::password() const
{
    return m_password;
}
QString User::role() const
{
    return m_role;
}
