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

private:
    std::unique_ptr<db::Processor> m_dbProcessor;
};

