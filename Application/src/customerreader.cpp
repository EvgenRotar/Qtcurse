#include "customerreader.h"
#include "Processor.h"
#include "dbtypes.h"
#include <iterator>

using namespace DBTypes;

CustomerReader::CustomerReader()
    : m_dbProcessor {new db::Processor {}}
{
}

std::vector<Customer> transformDriver(const std::vector<DBEntry>& source)
{
    std::vector<Customer> target;
    std::transform(source.begin(), source.end(), std::back_inserter(target),
                   [](const DBEntry& entry) {
        return Customer {entry[14].toString(),
                        entry[15].toString(),
                        entry[16].toString(),
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
                        entry[1].toString(),
                        entry[2].toString(),
                        entry[3].toString(),
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

std::vector<Customer> transformCustomer(const std::vector<DBEntry>& source)
{
    std::vector<Customer> target;
    std::transform(source.begin(), source.end(), std::back_inserter(target),
                   [](const DBEntry& entry) {
        return Customer {entry[1].toString(),
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

std::pair<bool, std::vector<Customer>> CustomerReader::requestAllByCustomerIdBrowse(const int& customerId)
{
    DBResult result;
    std::vector<DBEntry> entries;
    std::tie(result, entries) = m_dbProcessor->requestTableDataByCustomerId(customerId);
    return std::make_pair(result == DBResult::OK,
                          transformCustomer(entries));
}

std::pair<bool, std::vector<Customer>> CustomerReader::requestAllByOrderIdBrowse(const int& orderId)
{
    DBResult result;
    std::vector<DBEntry> entries;
    std::tie(result, entries) = m_dbProcessor->requestTableDataByOrderId(orderId);
    return std::make_pair(result == DBResult::OK,
                          transformCustomer(entries));
}

std::pair<bool, std::vector<Customer>> CustomerReader::requestAllByDriverIdBrowse(const int& driverId)
{
    DBResult result;
    std::vector<DBEntry> entries;
    std::tie(result, entries) = m_dbProcessor->requestTableDataByDriverId(driverId);
    return std::make_pair(result == DBResult::OK,
                          transformDriver(entries));
}

CustomerReader::~CustomerReader()
{
}
