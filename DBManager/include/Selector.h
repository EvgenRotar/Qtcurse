#pragma once
#include <QVariantList>
#include "dbtypes.h"
#include "Executor.h"

namespace db
{
class Selector
{
public:
    DBTypes::DBResult selectAll(const std::string& tableName,
                                std::vector<QVariantList>& returnData);

    DBTypes::DBResult selectAllByCustomerId(const int& customerId,
                                std::vector<QVariantList>& returnData);

    DBTypes::DBResult selectAllByOrderId(const int& orderId,
                                std::vector<QVariantList>& returnData);

    DBTypes::DBResult selectAllByDriverId(const int& driverId,
                                std::vector<QVariantList>& returnData);

    DBTypes::DBResult selectAllOrders(std::vector<QVariantList>& returnData);

    DBTypes::DBResult selectUserByEmailPassword(const std::string& email,
                                                const std::string& password,
                                std::vector<QVariantList>& returnData);

private:
    Executor m_executor;
    std::string generateQuery(const std::string& tableName) const;
    std::string generateQuerySelectAllByCustomerId(const int& customerId) const;
    std::string generateQuerySelectAllByOrderId(const int& orderId) const;
    std::string generateQuerySelectAllByDriverId(const int& driverId) const;
    std::string generateQuerySelectAllOrders() const;
    std::string generateQuerySelectUserByEmailPassword(const std::string& email, const std::string& password) const;
};
}
