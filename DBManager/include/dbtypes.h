#ifndef DBTYPES_H
#define DBTYPES_H
#include <QVariantList>

namespace DBTypes
{
enum class DBResult {
    OK,
    FAIL
};

enum class DBTables {
    user = 1,
    role = 2,
    user_role = 3,
    company = 4,
    company_employee = 5,
    order_type = 6,
    order = 7,
    order_item = 8,
    shipping = 9,
    vehicle = 10,
    vehicle_driver = 11
};

enum class DBState {
    OK,
    ERROR_NO_DRIVER,
    ERROR_WORKSPACE,
    ERROR_TABLES,
    ERROR_OPENING
};

using DBEntry = QVariantList;
using DBIndex = int;
}
#endif // DBTYPES_H
