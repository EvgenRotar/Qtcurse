#pragma once
#include "dbtypes.h"
#include <memory>

namespace db
{
class Processor
{
public:
    Processor();
    ~Processor();
    std::pair<DBTypes::DBResult,
              std::vector<DBTypes::DBEntry>> requestTableData(DBTypes::DBTables table);

    std::pair<DBTypes::DBResult,
              std::vector<DBTypes::DBEntry>> requestTableDataByCustomerId(const int& customerId);

    std::pair<DBTypes::DBResult,
              std::vector<DBTypes::DBEntry>> requestTableDataByOrderId(const int& orderId);

    std::pair<DBTypes::DBResult,
              std::vector<DBTypes::DBEntry>> requestTableDataByDriverId(const int& driverId);

    std::pair<DBTypes::DBResult,
              std::vector<DBTypes::DBEntry>> requestAllOrders();

    std::pair<DBTypes::DBResult,
              std::vector<DBTypes::DBEntry>> requestUserByEmailPassword(const std::string& email,
                                                                        const std::string& password);



private:
    struct ProcessorPrivate;
    std::unique_ptr<ProcessorPrivate> m_d;
};
}
