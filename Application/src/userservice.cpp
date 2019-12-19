#include "usersservice.h"
#include "Executor.h"
#include "dbtypes.h"
#include <iterator>
#include <QSqlQuery>
#include <QSqlRecord>
#include <vector>
#include <sstream>
#include "dbmapper.h"
#include <QQmlEngine>
#include <QDebug>
#include <iostream>

using namespace DBTypes;

usersservice::usersservice()
{
    insertRow("user", {{"Evgeny", "Rotar", "evgen@mail.com", "admin"}});
    insertRow("user", {{"Anna", "Glushenko", "anna@mail.com", "admin"}});
    insertRow("user", {{"Lexa", "Tsimbalist", "lexa@mail.com", "user"}});
    insertRow("user", {{"Semen", "Petrenko", "sema@mail.com", "user"}});
    insertRow("role", {{"admin"}});
    insertRow("role", {{"user"}});
    insertRow("user_role", {{"1","1"}});
    insertRow("user_role", {{"2","1"}});
    insertRow("user_role", {{"3","2"}});
    insertRow("user_role", {{"4","2"}});
    insertRow("company", {{"Semens","2017-03-01"}});
    insertRow("company", {{"Lexas","2018-01-01"}});
    insertRow("company_employee", {{"1","3","70"}});
    insertRow("company_employee", {{"2","4","50"}});
    insertRow("order_type", {{"Fragile"}});
    insertRow("order_type", {{"Not Fragile"}});
    insertRow("order", {{"1","1","vezem","100","from address1","to address2","2019-02-02"}});
    insertRow("order", {{"2","1","vezti bistro","200","from address2","to address3","2019-03-03"}});
    insertRow("order", {{"2","1","vezti bistro","200","from address2","to address3","2019-03-03"}});
    insertRow("order_item", {{"1","meat","12","13","14"}});
    insertRow("order_item", {{"2","glass","15","16","17"}});
    insertRow("order_item", {{"3","toys","15","16","17"}});
    insertRow("shipping", {{"1","2019-06-06","2019-07-07","3"}});
    insertRow("shipping", {{"2","2019-08-08","2019-09-09","4"}});
    insertRow("vehicle", {{"1","1234","mers"}});
    insertRow("vehicle", {{"2","4321","bmw"}});
    insertRow("vehicle_driver", {{"1","3","2017-04-04","2020-10-10"}});
    insertRow("vehicle_driver", {{"2","4","2018-04-03","2021-09-09"}});
}

std::string generateBindString(size_t paramCount)
{
    std::ostringstream bindings;
    std::fill_n(std::ostream_iterator<std::string>(bindings),
                paramCount,
                "?,");

    std::string bindString = bindings.str();
    bindString.pop_back(); // the last ","

    return bindString;
}

std::string generateInsertQuery(const std::string& tableName, size_t paramCount)
{
    std::string query = "INSERT INTO \"" + tableName +  "\" (" + tablesMapping.at(tableName) + ")"
                        " VALUES (";

    query += generateBindString(paramCount);
    query += ")";

    return query;
}

std::pair<DBResult, int> usersservice::insertRow(const std::string& tableName, const QVariantList& rowData)
{
    const std::string& query {generateInsertQuery(tableName, rowData.size())};
    const std::pair<DBResult, QSqlQuery>& result {m_executor.execute(query, rowData)};
    return std::make_pair(result.first,
                          result.second.lastInsertId().toInt());
}



std::string generateQuerySelectUserByEmailPassword(const std::string& email, const std::string& password)
{
    std::string query = "select user.id, first_name, last_name, email, password, role.name as role_name from user"
                        " join user_role on user.id = user_role.user_id"
                        " join role on user_role.role_id = role.id"
                        " where email = '" + email + "' and password = '" + password + "'";
 return query;
}

std::string generateQuerySelectUserById(const int& id)
{
    std::string query = " select user.id, first_name, last_name, email, password, role.name as role_name from user"
                        " join user_role on user.id = user_role.user_id"
                        " join role on user_role.role_id = role.id"
                        " where user.id = " + std::to_string(id);
    return query;
}

std::string generateInsertUserQuery()
{
    std::string query = "INSERT INTO \"user\" (first_name, last_name, email, password)"
                        " VALUES (";

    query += generateBindString({4});
    query += ")";

    return query;
}

std::string generateInsertUserRoleQuery()
{
    std::string query = "INSERT INTO user_role (user_id, role_id)"
                        " VALUES (";

    query += generateBindString({2});
    query += ")";

    return query;
}


std::vector<User> mapUser(const std::vector<DBEntry>& source)
{
    std::vector<User> target;
    std::transform(source.begin(), source.end(), std::back_inserter(target),
                   [](const DBEntry& entry) {
        return User {entry[1].toString(),
                        entry[2].toString(),
                        entry[3].toString(),
                        entry[4].toString(),
                        entry[5].toString(),
                        entry[0].toInt()};
    });
    return target;
}

int usersservice::registerNewUser(User user) {
    DBResult result;
    DBResult result1;

    std::vector<DBEntry> entries;

    const std::string query {generateInsertUserQuery()};
    QSqlQuery resultQuery;
    std::tie(result, resultQuery) = m_executor.execute(query, {user.firstName(), user.secondName(), user.email(), user.password()});

    if (result == DBResult::OK)
    {
        int insertUserId = resultQuery.lastInsertId().toInt();

        const std::string query1 {generateInsertUserRoleQuery()};
        QSqlQuery resultQuery1;
        std::tie(result1, resultQuery1) = m_executor.execute(query1, {insertUserId, 1});
        if (result1 == DBResult::OK) {
            return insertUserId;
        }
    }
    return 0;
}

User usersservice::tryLogIn(QString email, QString password) {
    DBResult result;
    std::vector<DBEntry> entries;

    const std::string query {generateQuerySelectUserByEmailPassword(email.toStdString(), password.toStdString())};
    qWarning() << query.c_str();
    QSqlQuery resultQuery;
    std::tie(result, resultQuery) = m_executor.execute(query);

    std::vector<QVariantList> returnData;
    if (result == DBResult::OK)
    {
        while (resultQuery.next())
        {
            const QSqlRecord& resultRecord = resultQuery.record();
            QVariantList result;
            for (int i = 0; i < resultRecord.count(); ++i)
            {
                result.push_back(resultRecord.value(i));
            }
            returnData.push_back(std::move(result));
        }
        if (!returnData.empty()){
            return mapUser(std::move(returnData)).at(0);
        }
    }
    User u1;
    u1.m_id=0;
    return u1;
}

User usersservice::getUserById(int id) {
    DBResult result;
    std::vector<DBEntry> entries;

    const std::string query {generateQuerySelectUserById(id)};
    QSqlQuery resultQuery;
    std::tie(result, resultQuery) = m_executor.execute(query);

    std::vector<QVariantList> returnData;
    if (result == DBResult::OK)
    {
        while (resultQuery.next())
        {
            const QSqlRecord& resultRecord = resultQuery.record();
            QVariantList result;
            for (int i = 0; i < resultRecord.count(); ++i)
            {
                result.push_back(resultRecord.value(i));
            }
            returnData.push_back(std::move(result));
        }
        if (!returnData.empty()){
            return mapUser(std::move(returnData)).at(0);
        }
    }
    User u1;
    u1.m_id=0;
    return u1;
}

