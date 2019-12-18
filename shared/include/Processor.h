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

    bool requestDeleteOrder(const int& id);

    int requestAcceptOrder(const int& orderId, const int& driverId,
                                       const std::string& sendingDate, const std::string& arrivalDate);

    bool requestFinishOrder(const int& orderId);

    int requestAddOrder(const int& orderType, const int& customerId,
                                   const std::string& description, const int& price,
                                   const std::string& fromAddress, const std::string& toAddress,
                                   const std::string& sendingDate, const std::string& orderItemName,
                                   const int& length, const int& width,
                                   const int& height);
private:
    struct ProcessorPrivate;
    std::unique_ptr<ProcessorPrivate> m_d;
};
}
