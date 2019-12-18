#include "Selector.h"
#include "Executor.h"
#include <QSqlQuery>
#include <QSqlRecord>

using namespace DBTypes;

namespace db
{
DBResult Selector::selectAll(const std::string& tableName, std::vector<QVariantList>& returnData)
{
    const std::string query {generateQuery(tableName)};
    DBResult result;
    QSqlQuery resultQuery;
    std::tie(result, resultQuery) = m_executor.execute(query);

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
    }
    return result;
}

DBResult Selector::selectAllByCustomerId(const int& customerId, std::vector<QVariantList>& returnData)
{
    const std::string query {generateQuerySelectAllByCustomerId(customerId)};
    DBResult result;
    QSqlQuery resultQuery;
    std::tie(result, resultQuery) = m_executor.execute(query);

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
    }
    return result;
}

DBResult Selector::selectAllByOrderId(const int& orderId, std::vector<QVariantList>& returnData)
{
    const std::string query {generateQuerySelectAllByOrderId(orderId)};
    DBResult result;
    QSqlQuery resultQuery;
    std::tie(result, resultQuery) = m_executor.execute(query);

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
    }
    return result;
}

DBResult Selector::selectAllByDriverId(const int& driverId, std::vector<QVariantList>& returnData)
{
    const std::string query {generateQuerySelectAllByDriverId(driverId)};
    DBResult result;
    QSqlQuery resultQuery;
    std::tie(result, resultQuery) = m_executor.execute(query);

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
    }
    return result;
}

DBResult Selector::selectAllOrders(std::vector<QVariantList>& returnData)
{
    const std::string query {generateQuerySelectAllOrders()};
    DBResult result;
    QSqlQuery resultQuery;
    std::tie(result, resultQuery) = m_executor.execute(query);

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
    }
    return result;
}

DBResult Selector::selectUserByEmailPassword(const std::string& email,
                                            const std::string& password,
                            std::vector<QVariantList>& returnData)
{
    const std::string query {generateQuerySelectUserByEmailPassword(email, password)};
    DBResult result;
    QSqlQuery resultQuery;
    std::tie(result, resultQuery) = m_executor.execute(query);

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
    }
    return result;
}

std::string Selector::generateQuerySelectUserByEmailPassword(const std::string& email, const std::string& password) const
{
    std::string query = "select first_name, last_name, email, password, role.name as role_name from user"
                        " join user_role on user.id = user_role.user_id"
                        " join role on user_role.role_id = role.id"
                        " where email = '" + email + "' and password = '" + password + "'";
    return query;
}

std::string Selector::generateQuerySelectAllOrders() const
{
    std::string query = "SELECT \"order\".id, \"order\".description, \"order\".price, \"order\".from_address, \"order\".to_address, \"order\".sending_date as order_sending_date,"
                        " order_item.name as order_item_name, order_item.height, order_item.width, order_item.length, order_type.name as order_type_name,"
                        " shipping.sending_date as shipping_sending_date, shipping.arrival_date as shipping_arrival_date, vehicle.car_number, vehicle.model as car_model,"
                        " company.name as company_name, company.registration_date as company_registration_date,"
                        " dr.id as driver_id, dr.first_name as driver_first_name, dr.last_name as driver_last_name, dr.email as driver_email,"
                        " user.id as customer_id, user.first_name as customer_first_name, user.last_name as customer_last_name, user.email as customer_email"
                 " from \"order\""
                 " join order_type on \"order\".type = order_type.id"
                 " join order_item on \"order\".id = order_item.order_id"
                 " left join shipping on \"order\".id = shipping.order_id"
                 " join user on \"order\".customer_id = user.id"
                 " left join user dr on dr.id = shipping.driver_id"
                 " left join vehicle_driver on dr.id = vehicle_driver.driver_id"
                 " left join vehicle on vehicle_driver.vehicle_id = vehicle.id"
                 " left join company on vehicle.company_id = company.id";
    return query;
}

std::string Selector::generateQuery(const std::string& tableName) const
{
    std::string query = "SELECT rowid, * FROM " + tableName;
    return query;
}

std::string Selector::generateQuerySelectAllByCustomerId(const int& id) const
{
    std::string query = "SELECT user.id, user.first_name, user.last_name, user.email,"
                        " \"order\".description, \"order\".price, \"order\".from_address, \"order\".to_address, \"order\".sending_date as order_sending_date,"
                        " order_item.name as order_item_name, order_item.length, order_item.height, order_item.width, order_type.name as order_type_name,"
                        " a.first_name as driver_first_name, a.last_name as driver_last_name, a.email as driver_email,"
                        " vehicle.car_number, vehicle.model as car_model, company.name as company_name, company.registration_date as company_registration_date,"
                        " shipping.sending_date as shipping_sending_date, shipping.arrival_date as shipping_arrival_date"
                 " FROM user"
                 " join \"order\" on user.id = \"order\".customer_id"
                 " join order_item on \"order\".id = order_item.order_id"
                 " left join shipping on shipping.order_id = \"order\".id"
                 " join order_type on order_type.id = \"order\".type"
                 " join vehicle_driver on vehicle_driver.driver_id = shipping.driver_id"
                 " join vehicle on vehicle_driver.vehicle_id = vehicle.id"
                 " join company on vehicle.company_id = company.id"
                 " join user a on a.id = shipping.driver_id"
                 " where user.id = " + std::to_string(id);
    return query;
}

std::string Selector::generateQuerySelectAllByOrderId(const int& id) const
{
    std::string query = "SELECT user.id, user.first_name, user.last_name, user.email,"
                        " \"order\".description, \"order\".price, \"order\".from_address, \"order\".to_address, \"order\".sending_date as order_sending_date,"
                        " order_item.name as order_item_name, order_item.length, order_item.height, order_item.width, order_type.name as order_type_name,"
                        " a.first_name as driver_first_name, a.last_name as driver_last_name, a.email as driver_email,"
                        " vehicle.car_number, vehicle.model as car_model, company.name as company_name, company.registration_date as company_registration_date,"
                        " shipping.sending_date as shipping_sending_date, shipping.arrival_date as shipping_arrival_date"
                 " FROM user"
                 " join \"order\" on user.id = \"order\".customer_id"
                 " join order_item on \"order\".id = order_item.order_id"
                 " left join shipping on shipping.order_id = \"order\".id"
                 " join order_type on order_type.id = \"order\".type"
                 " join vehicle_driver on vehicle_driver.driver_id = shipping.driver_id"
                 " join vehicle on vehicle_driver.vehicle_id = vehicle.id"
                 " join company on vehicle.company_id = company.id"
                 " join user a on a.id = shipping.driver_id"
                 " where \"order\".id = " + std::to_string(id);
    return query;
}

std::string Selector::generateQuerySelectAllByDriverId(const int& id) const
{
    std::string query = "SELECT user.id, user.first_name, user.last_name, user.email,"
                        " \"order\".description, \"order\".price, \"order\".from_address, \"order\".to_address, \"order\".sending_date as order_sending_date,"
                        " order_item.name as order_item_name, order_item.length, order_item.height, order_item.width, order_type.name as order_type_name,"
                        " ct.first_name as customer_first_name, ct.last_name as customer_last_name, ct.email as customer_email,"
                        " vehicle.car_number, vehicle.model as car_model, company.name as company_name, company.registration_date as company_registartion_date,"
                        " shipping.sending_date as shipping_sending_date, shipping.arrival_date as shipping_arrival_date"
                 " from user"
                 " join company_employee on user.id = company_employee.employee_id"
                 " join company on company_employee.company_id = company.id"
                 " join vehicle on company.id = vehicle.company_id"
                 " join vehicle_driver on user.id = vehicle_driver.driver_id"
                 " join shipping on user.id = shipping.driver_id"
                 " join \"order\" on shipping.order_id = \"order\".id"
                 " join order_item on \"order\".id = order_item.order_id"
                 " join order_type on \"order\".type = order_type.id"
                 " join user ct on ct.id = \"order\".customer_id"
                 " where user.id = " + std::to_string(id);
    return query;
}
}
