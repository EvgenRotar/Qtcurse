#include "Processor.h"
#include "Manipulator.h"
#include "Selector.h"
#include "dbmapper.h"
#include <mutex>

namespace db
{
struct Processor::ProcessorPrivate
{
    Manipulator manipulator;
    Selector selector;
#ifdef INSERT_TEST_DATA
    void insertMockData();
    std::once_flag initialized;
#endif
};

#ifdef INSERT_TEST_DATA
void Processor::ProcessorPrivate::insertMockData()
{
    qInfo() << "Start Insert Data";
    manipulator.insertRow("user", {{"Evgeny", "Rotar", "evgen@mail.com", "admin"}});
    manipulator.insertRow("user", {{"Anna", "Glushenko", "anna@mail.com", "admin"}});
    manipulator.insertRow("user", {{"Lexa", "Tsimbalist", "lexa@mail.com", "user"}});
    manipulator.insertRow("user", {{"Semen", "Petrenko", "sema@mail.com", "user"}});
    manipulator.insertRow("role", {{"customer"}});
    manipulator.insertRow("role", {{"driver"}});
    manipulator.insertRow("user_role", {{"1","1"}});
    manipulator.insertRow("user_role", {{"2","1"}});
    manipulator.insertRow("user_role", {{"3","2"}});
    manipulator.insertRow("user_role", {{"4","2"}});
    manipulator.insertRow("company", {{"Semens","2017-03-01"}});
    manipulator.insertRow("company", {{"Lexas","2018-01-01"}});
    manipulator.insertRow("company_employee", {{"1","3","70"}});
    manipulator.insertRow("company_employee", {{"2","4","50"}});
    manipulator.insertRow("order_type", {{"Xrypkiy"}});
    manipulator.insertRow("order_type", {{"Ne xrypkiy"}});
    manipulator.insertRow("order", {{"1","1","vezem","100","from address1","to address2","2019-02-02"}});
    manipulator.insertRow("order", {{"2","1","vezti bistro","200","from address2","to address3","2019-03-03"}});
    manipulator.insertRow("order_item", {{"1","meat","12","13","14"}});
    manipulator.insertRow("order_item", {{"2","glass","15","16","17"}});
    manipulator.insertRow("shipping", {{"1","2019-06-06","2019-07-07","3"}});
    manipulator.insertRow("shipping", {{"2","2019-08-08","2019-09-09","4"}});
    manipulator.insertRow("vehicle", {{"1","1234","mers"}});
    manipulator.insertRow("vehicle", {{"2","4321","bmw"}});
    manipulator.insertRow("vehicle_driver", {{"1","3","2017-04-04","2020-10-10"}});
    manipulator.insertRow("vehicle_driver", {{"2","4","2018-04-03","2021-09-09"}});
    qInfo() << "End Insert Data";
}
#endif

db::Processor::Processor()
    : m_d {new ProcessorPrivate {}}
{
#ifdef INSERT_TEST_DATA
    auto inserter = [this] {
        m_d->insertMockData();
    };
    std::call_once(m_d->initialized, inserter);
#endif
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

}
