#ifndef USERSSERVICE_H
#define USERSSERVICE_H
#include "user.h"
#include <QString>
#include <vector>
#include <memory>
#include "Executor.h"

using namespace db;

class usersservice
{
public:
    usersservice();

    int registerNewUser(User user); //Return id of new user

    User tryLogIn(QString email,QString password); //Just like browse user by email and password
                                                   //if not found return null
    User getUserById(int id);

    std::pair<DBTypes::DBResult, int> insertRow(const std::string& tableName, const QVariantList& rowData);

private:
    Executor m_executor;
};
#endif // USERSSERVICE_H
