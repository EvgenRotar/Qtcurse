#include "Manipulator.h"
#include <sstream>
#include "dbmapper.h"
#include <QSqlQuery>

using namespace DBTypes;

namespace db
{

std::pair<DBResult, int> Manipulator::insertRow(const std::string& tableName, const QVariantList& rowData)
{
    const std::string& query {generateInsertQuery(tableName, rowData.size())};
    const std::pair<DBResult, QSqlQuery>& result {m_executor.execute(query, rowData)};
    return std::make_pair(result.first,
                          result.second.lastInsertId().toInt());
}

bool Manipulator::deleteRow(const std::string& tableName, const int& id)
{
    const std::string& query {generateDeleteQuery(tableName, id)};
    const std::pair<DBResult, QSqlQuery>& result {m_executor.execute(query)};
    if (result.first == DBResult::OK) {
        return true;
    }
    return false;
}

bool Manipulator::deleteShippingRowByOrderId(const int& id)
{
    const std::string& query {generateDeleteQueryShippingByOrderId(id)};
    const std::pair<DBResult, QSqlQuery>& result {m_executor.execute(query)};
    if (result.first == DBResult::OK) {
        return true;
    }
    return false;
}

std::string Manipulator::generateDeleteQueryShippingByOrderId(const int& id) const
{
    std::string query = "DELETE FROM shipping where shipping.order_id = " + std::to_string(id);

    return query;
}


std::string Manipulator::generateBindString(size_t paramCount) const
{
    std::ostringstream bindings;
    std::fill_n(std::ostream_iterator<std::string>(bindings),
                paramCount,
                "?,");

    std::string bindString = bindings.str();
    bindString.pop_back(); // the last ","

    return bindString;
}

std::string Manipulator::generateInsertQuery(const std::string& tableName, size_t paramCount) const
{
    std::string query = "INSERT INTO \"" + tableName +  "\" (" + tablesMapping.at(tableName) + ")"
                        " VALUES (";

    query += generateBindString(paramCount);
    query += ")";

    return query;
}

std::string Manipulator::generateDeleteQuery(const std::string& tableName, const int& id) const
{
    std::string query = "DELETE FROM \"" + tableName + "\" where \"" + tableName + "\".id = " + std::to_string(id);


    return query;
}

}
