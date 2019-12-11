#pragma once
#include <vector>
#include <memory>
#include "user.h"

namespace db
{
class Processor;
}
class UserReader
{
public:
    UserReader();

    std::pair<bool,
              std::vector<User>> requestUsersBrowse();

    std::pair<bool,
              std::vector<User>> requestUserByEmailAndPasswordBrowse(const std::string& email, const std::string& password);

    ~UserReader();

private:
    std::unique_ptr<db::Processor> m_dbProcessor;
};

