#include "userreader.h"
#include "Processor.h"
#include "dbtypes.h"
#include <iterator>

using namespace DBTypes;

UserReader::UserReader()
    : m_dbProcessor {new db::Processor {}}
{
}

std::vector<User> transformUser(const std::vector<DBEntry>& source)
{
    std::vector<User> target;
    std::transform(source.begin(), source.end(), std::back_inserter(target),
                   [](const DBEntry& entry) {
        return User {entry[1].toString(),
                        entry[2].toString(),
                        entry[3].toString(),
                        entry[4].toString(),
                        entry[5].toString(),
                        entry[0].toInt()};
    });
    return target;
}

std::pair<bool, std::vector<User>> UserReader::requestUsersBrowse()
{
    DBResult result;
    std::vector<DBEntry> entries;
    std::tie(result, entries) = m_dbProcessor->requestTableData(DBTables::user);
    return std::make_pair(result == DBResult::OK,
                          transformUser(entries));
}

std::pair<bool, std::vector<User>> UserReader::requestUserByEmailAndPasswordBrowse(const std::string& email, const std::string& password)
{
    DBResult result;
    std::vector<DBEntry> entries;
    std::tie(result, entries) = m_dbProcessor->requestUserByEmailPassword(email, password);
    return std::make_pair(result == DBResult::OK,
                          transformUser(entries));
}

UserReader::~UserReader()
{
}
