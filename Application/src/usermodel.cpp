#include "usermodel.h"
#include <QQmlEngine>
#include <QDebug>

UserModel::UserModel()
{
    const bool updateResult {updateUsers()};

    if (!updateResult) {
        qWarning() << "Update users failed!";
    }
}

void UserModel::registerMe(const std::string& moduleName)
{
    qmlRegisterType<UserModel>(moduleName.c_str(), 1, 0, "UserModel");
}

int UserModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent)
    return static_cast<int>(m_users.size());
}

QVariant UserModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid() || index.row() > rowCount(index)) {
        return {};
    }

    const User& user = m_users.at(index.row());

    switch (role) {
        case UserRoles::NameRole: {
            return QVariant::fromValue(user.firstName());
        }
        case UserRoles::SurnameRole: {
            return QVariant::fromValue(user.secondName());
        }
        case UserRoles::EmailRole: {
            return QVariant::fromValue(user.email());
        }
        case UserRoles::PasswordRole: {
            return QVariant::fromValue(user.password());
        }
        case UserRoles::RoleRole: {
            return QVariant::fromValue(user.role());
        }
        default: {
            return {};
        }
    }
}

QHash<int, QByteArray> UserModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[UserRoles::NameRole] = "firstname";
    roles[UserRoles::SurnameRole] = "surname";
    roles[UserRoles::EmailRole] = "email";
    roles[UserRoles::PasswordRole] = "password";
    roles[UserRoles::RoleRole] = "role";
    return roles;
}

bool UserModel::updateUsers()
{
    bool requestResult {false};
    std::vector<User> usersResult;

    std::tie(requestResult, usersResult) = m_reader.requestUsersBrowse();

    if (requestResult) {
        m_users.swap(usersResult);
        emit dataChanged(createIndex(0, 0), createIndex(m_users.size(), 0));
    }

    return requestResult;
}
