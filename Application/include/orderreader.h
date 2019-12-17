#pragma once
#include <vector>
#include <memory>
#include "order.h"

namespace db
{
class Processor;
}
class OrderReader
{
public:
    OrderReader();

    std::pair<bool,
              std::vector<Order>> requestOrdersBrowse();

    ~OrderReader();

    bool deleteOrder(int id);
    bool finishOrder(const int& orderId);
    int acceptOrder(const int& orderId, const int& driverId,
                                 const std::string& sendingDate, const std::string& arrivalDate);

    int addOrder(const int& orderType, const int& customerId,
                                   const std::string& description, const int& price,
                                   const std::string& fromAddress, const std::string& toAddress,
                                   const std::string& sendingDate, const std::string& orderItemName,
                                   const int& length, const int& width,
                                   const int& height);
private:
    std::unique_ptr<db::Processor> m_dbProcessor;
};

