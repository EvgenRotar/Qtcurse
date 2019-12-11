#pragma once
#include <vector>
#include <memory>
#include "customer.h"

namespace db
{
class Processor;
}
class CustomerReader
{
public:
    CustomerReader();

    std::pair<bool,
              std::vector<Customer>> requestAllByCustomerIdBrowse(const int& customerId);

    std::pair<bool,
              std::vector<Customer>> requestAllByOrderIdBrowse(const int& orderId);

    std::pair<bool,
              std::vector<Customer>> requestAllByDriverIdBrowse(const int& driverId);

    ~CustomerReader();

private:
    std::unique_ptr<db::Processor> m_dbProcessor;
};

