#include "orderreader.h"
#include "Processor.h"
#include "dbtypes.h"
#include <iterator>

using namespace DBTypes;

OrderReader::OrderReader()
    : m_dbProcessor {new db::Processor {}}
{
}

std::vector<Order> transformOrder(const std::vector<DBEntry>& source)
{
    std::vector<Order> target;
    std::transform(source.begin(), source.end(), std::back_inserter(target),
                   [](const DBEntry& entry) {
        return Order {entry[1].toString(),
                        entry[2].toString(),
                        entry[3].toString(),
                        entry[4].toString(),
                        entry[5].toString(),
                        entry[6].toString(),
                        entry[7].toString(),
                        entry[8].toString(),
                        entry[9].toString(),
                        entry[10].toString(),
                        entry[11].toString(),
                        entry[12].toString(),
                        entry[13].toString(),
                        entry[14].toString(),
                        entry[15].toString(),
                        entry[16].toString(),
                        entry[17].toString(),
                        entry[18].toString(),
                        entry[19].toString(),
                        entry[20].toString(),
                        entry[21].toString(),
                        entry[22].toString(),
                        entry[0].toInt()};
    });
    return target;
}

std::pair<bool, std::vector<Order>> OrderReader::requestOrdersBrowse()
{
    DBResult result;
    std::vector<DBEntry> entries;
    std::tie(result, entries) = m_dbProcessor->requestAllOrders();
    return std::make_pair(result == DBResult::OK,
                          transformOrder(entries));
}

bool OrderReader::deleteOrder(int id)
{
    return m_dbProcessor->requestDeleteOrder(id);
}

int OrderReader::acceptOrder(const int& orderId, const int& driverId,
                             const std::string& sendingDate, const std::string& arrivalDate)
{
    return m_dbProcessor->requestAcceptOrder(orderId, driverId, sendingDate, arrivalDate);

}

bool OrderReader::finishOrder(const int& orderId)
{
    return m_dbProcessor->requestFinishOrder(orderId);
}

int OrderReader::addOrder(const int& orderType, const int& customerId,
                               const std::string& description, const int& price,
                               const std::string& fromAddress, const std::string& toAddress,
                               const std::string& sendingDate, const std::string& orderItemName,
                               const int& length, const int& width,
                               const int& height)
{
    return m_dbProcessor->requestAddOrder(orderType, customerId, description, price, fromAddress, toAddress, sendingDate, orderItemName, length, width, height);
}

OrderReader::~OrderReader()
{
}
