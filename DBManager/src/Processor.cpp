#include "Processor.h"
#include "Manipulator.h"
#include "Selector.h"
#include "dbmapper.h"
#include <mutex>
#include <QSqlQuery>
#include <string>

namespace db
{
struct Processor::ProcessorPrivate
{
    Manipulator manipulator;
    Selector selector;
    void insertMockData();
    std::once_flag initialized;
};

void Processor::ProcessorPrivate::insertMockData()
{
    qInfo() << "Start Insert Data";

    qInfo() << "End Insert Data";
}


db::Processor::Processor()
    : m_d {new ProcessorPrivate {}}
{
    auto inserter = [this] {
        m_d->insertMockData();
    };
    std::call_once(m_d->initialized, inserter);
}

Processor::~Processor()
{
}

std::pair<DBTypes::DBResult, std::vector<DBTypes::DBEntry>> Processor::requestTableData(DBTypes::DBTables table)
{
    std::vector<QVariantList> result;
    const DBTypes::DBResult resultState {m_d->selector.selectAll(tableMapper.at(table), result)};
    return std::make_pair(resultState, std::move(result));
}

std::pair<DBTypes::DBResult, std::vector<DBTypes::DBEntry>> Processor::requestTableDataByCustomerId(const int& customerId)
{
    std::vector<QVariantList> result;
    const DBTypes::DBResult resultState {m_d->selector.selectAllByCustomerId(customerId, result)};
    return std::make_pair(resultState, std::move(result));
}

std::pair<DBTypes::DBResult, std::vector<DBTypes::DBEntry>> Processor::requestTableDataByOrderId(const int& orderId)
{
    std::vector<QVariantList> result;
    const DBTypes::DBResult resultState {m_d->selector.selectAllByOrderId(orderId, result)};
    return std::make_pair(resultState, std::move(result));
}

std::pair<DBTypes::DBResult, std::vector<DBTypes::DBEntry>> Processor::requestTableDataByDriverId(const int& driverId)
{
    std::vector<QVariantList> result;
    const DBTypes::DBResult resultState {m_d->selector.selectAllByDriverId(driverId, result)};
    return std::make_pair(resultState, std::move(result));
}

std::pair<DBTypes::DBResult, std::vector<DBTypes::DBEntry>> Processor::requestAllOrders()
{
    std::vector<QVariantList> result;
    const DBTypes::DBResult resultState {m_d->selector.selectAllOrders(result)};
    return std::make_pair(resultState, std::move(result));
}

std::pair<DBTypes::DBResult, std::vector<DBTypes::DBEntry>> Processor::requestUserByEmailPassword(const std::string& email,
                                                                                                  const std::string& password)
{
    std::vector<QVariantList> result;
    const DBTypes::DBResult resultState {m_d->selector.selectUserByEmailPassword(email, password, result)};
    return std::make_pair(resultState, std::move(result));
}

bool Processor::requestDeleteOrder(const int& id)
{
    return m_d->manipulator.deleteRow("order", id);
}

int Processor::requestAcceptOrder(const int& orderId, const int& driverId,
                                   const std::string& sendingDate, const std::string& arrivalDate)
{
    std::pair<DBTypes::DBResult, int> result {m_d->manipulator.insertRow("shipping", {{orderId, sendingDate.c_str(), arrivalDate.c_str(), driverId}})};
    if (result.first == DBTypes::DBResult::OK)
    {
        return result.second;
    }
    return 0;
}

bool Processor::requestFinishOrder(const int& orderId)
{
    return m_d->manipulator.deleteShippingRowByOrderId(orderId);;
}

int Processor::requestAddOrder(const int& orderType, const int& customerId,
                               const std::string& description, const int& price,
                               const std::string& fromAddress, const std::string& toAddress,
                               const std::string& sendingDate, const std::string& orderItemName,
                               const int& length, const int& width,
                               const int& height) {
    std::pair<DBTypes::DBResult, int> result {m_d->manipulator.insertRow("order", {{orderType, customerId, description.c_str(), price, fromAddress.c_str(), toAddress.c_str(), sendingDate.c_str()}})};
    if (result.first == DBTypes::DBResult::OK)
    {
        std::pair<DBTypes::DBResult, int> result1 {m_d->manipulator.insertRow("order_item", {{result.second, orderItemName.c_str(), length, width, height}})};
        if (result1.first == DBTypes::DBResult::OK) {
            return result.second;
        }
    }
    return 0;
}

}
