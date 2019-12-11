#pragma once
#include "dbtypes.h"

namespace db
{
static const std::map<DBTypes::DBTables, std::string> tableMapper {
    {DBTypes::DBTables::user, "user"},
    {DBTypes::DBTables::role, "role"},
    {DBTypes::DBTables::user_role, "user_role"},
    {DBTypes::DBTables::company, "company"},
    {DBTypes::DBTables::company_employee, "company_employee"},
    {DBTypes::DBTables::order_type, "order_type"},
    {DBTypes::DBTables::order, "order"},
    {DBTypes::DBTables::order_item, "order_item"},
    {DBTypes::DBTables::shipping, "shipping"},
    {DBTypes::DBTables::vehicle, "vehicle"},
    {DBTypes::DBTables::vehicle_driver, "vehicle_driver"}
};

static const std::map<std::string, std::string> tablesMapping = {
    {"user", "first_name, last_name, email, password"},
    {"role", "name"},
    {"user_role", "user_id, role_id"},
    {"company", "name, registration_date"},
    {"company_employee", "company_id, employee_id, pay"},
    {"order_type", "name"},
    {"order", "type, customer_id, description, price, from_address, to_address, sending_date"},
    {"order_item", "order_id, name, length, width, height"},
    {"shipping", "order_id, sending_date, arrival_date, driver_id"},
    {"vehicle", "company_id, car_number, model"},
    {"vehicle_driver", "vehicle_id, driver_id, start_date, end_date"}
};
}
