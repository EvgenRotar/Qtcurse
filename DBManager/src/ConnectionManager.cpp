#include "ConnectionManager.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QStandardPaths>
#include <QDir>

using namespace DBTypes;
namespace db
{
namespace
{
    class DBCloser {
    public:
        void operator() (QSqlDatabase* db) {
            db->close();
            QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);
        }
    };
}

class ConnectionManager::DBManagerPrivate {
public:
    std::unique_ptr<QSqlDatabase, DBCloser> m_database;
    std::string m_dbPath;
    DBState m_state {DBState::OK};
    bool m_isValid {true};

    bool setUp();
    bool setUpWorkspace();
    bool setUpTables();

    void setIsValid(bool isValid);
};

ConnectionManager& ConnectionManager::instance()
{
    static ConnectionManager instance {};
    return instance;
}

std::string ConnectionManager::databasePath() const
{
    return m_d->m_dbPath;
}

DBState ConnectionManager::state() const
{
    return m_d->m_state;
}

bool ConnectionManager::DBManagerPrivate::setUp()
{
    const QString driver {"QSQLITE"};

    if (!QSqlDatabase::isDriverAvailable(driver))
    {
        m_state = DBState::ERROR_NO_DRIVER;
        qWarning() << "Driver " << driver << " is not available.";
        return false;
    }

    if (!setUpWorkspace())
    {
        m_state = DBState::ERROR_WORKSPACE;
        qCritical() << "Workspace setup failed!";
        return false;
    }

    auto* db = new QSqlDatabase {QSqlDatabase::addDatabase(driver)};
    m_database.reset(db);

    m_database->setDatabaseName(QString::fromStdString(m_dbPath));
//    m_database->setHostName();
//    m_database->setUserName();
//    m_database->setPassword();
//    m_database->setPort();

    qDebug() << "Database name: " << m_database->databaseName();

    if (!m_database->open())
    {
        m_state = DBState::ERROR_OPENING;
        qCritical() << "Error in opening DB " << m_database->databaseName()
                   << " reason: " <<  m_database->lastError().text();
        return false;
    }

    return setUpTables();
}

bool ConnectionManager::DBManagerPrivate::setUpWorkspace()
{
    const QString databaseName {"TestDB"};

    const QString location {QStandardPaths::writableLocation(QStandardPaths::AppDataLocation)};
    const QString fullPath {location + "/" + databaseName};

    m_dbPath = fullPath.toStdString();

    QDir dbDirectory {location};
    if (!dbDirectory.exists())
    {
        const bool creationResult {dbDirectory.mkpath(location)};
        qWarning() << "DB directory not exist, creating result: "
                   << creationResult;
    }

    qDebug() << "Data path: " << fullPath;

    return dbDirectory.exists();
}

bool ConnectionManager::DBManagerPrivate::setUpTables()
{
    bool result {true};

    std::vector<QSqlQuery> creationQueries = {
        QSqlQuery {
            "DROP TABLE if exists \"user\""
        },
        QSqlQuery {
            "DROP TABLE if exists role"
        },
        QSqlQuery {
            "DROP TABLE if exists user_role"
        },
        QSqlQuery {
            "DROP TABLE if exists company"
        },
        QSqlQuery {
            "DROP TABLE if exists company_employee"
        },
        QSqlQuery {
            "DROP TABLE if exists order_type"
        },
        QSqlQuery {
            "DROP TABLE if exists \"order\""
        },
        QSqlQuery {
            "DROP TABLE if exists order_item"
        },
        QSqlQuery {
            "DROP TABLE if exists shipping"
        },
        QSqlQuery {
            "DROP TABLE if exists vehicle"
        },
        QSqlQuery {
            "DROP TABLE if exists vehicle_driver"
        },
        QSqlQuery {
            "CREATE TABLE \"user\" ("
            "id integer PRIMARY KEY AUTOINCREMENT,"
            "first_name varchar(50)  NOT NULL,"
            "last_name varchar(50)  NOT NULL,"
            "email varchar(320)  NOT NULL UNIQUE,"
            "password text  NOT NULL"
            ")"
        },
        QSqlQuery {
            "CREATE TABLE role ("
            "id integer PRIMARY KEY AUTOINCREMENT,"
            "name varchar(20)  NOT NULL"
            ")"
        },
        QSqlQuery {
            "CREATE TABLE user_role ("
            "user_id int  NOT NULL,"
            "role_id int  NOT NULL,"
            "CONSTRAINT user_role_pk PRIMARY KEY (user_id,role_id),"
            "FOREIGN KEY (user_id) REFERENCES \"user\"(id),"
            "FOREIGN KEY (role_id) REFERENCES role(id)"
            ")"
        },
        QSqlQuery {
            "CREATE TABLE company ("
            "id integer PRIMARY KEY AUTOINCREMENT,"
            "name varchar(30)  NOT NULL,"
            "registration_date date  NOT NULL"
            ")"
        },
        QSqlQuery {
            "CREATE TABLE company_employee ("
            "company_id int  NOT NULL,"
            "employee_id int  NOT NULL,"
            "pay money  NOT NULL,"
            "CONSTRAINT company_employee_pk PRIMARY KEY (company_id,employee_id),"
            "FOREIGN KEY (company_id) REFERENCES company(id),"
            "FOREIGN KEY (employee_id) REFERENCES \"user\"(id)"
            ")"
        },
        QSqlQuery {
            "CREATE TABLE order_type ("
            "id integer PRIMARY KEY AUTOINCREMENT,"
            "name varchar(30) NOT NULL"
            ")"
        },
        QSqlQuery {
            "CREATE TABLE \"order\" ("
            "id integer PRIMARY KEY AUTOINCREMENT,"
            "type int  NOT NULL,"
            "customer_id int  NOT NULL,"
            "description text  NULL,"
            "price money  NOT NULL,"
            "from_address text  NOT NULL,"
            "to_address text  NOT NULL,"
            "sending_date timestamp  NOT NULL,"
            "FOREIGN KEY (customer_id) REFERENCES \"user\"(id),"
            "FOREIGN KEY (type) REFERENCES order_type (id)"
            ")"
        },
        QSqlQuery {
            "CREATE TABLE order_item ("
            "id integer PRIMARY KEY AUTOINCREMENT,"
            "order_id int NOT NULL,"
            "name varchar(30)  NOT NULL,"
            "length int  NOT NULL,"
            "width int  NOT NULL,"
            "height int  NOT NULL,"
            "FOREIGN KEY (order_id) REFERENCES \"order\"(id)"
            ")"
        },
        QSqlQuery {
            "CREATE TABLE shipping ("
            "id integer PRIMARY KEY AUTOINCREMENT,"
            "order_id int  NOT NULL,"
            "sending_date timestamp  NOT NULL,"
            "arrival_date timestamp  NULL,"
            "driver_id int  NOT NULL,"
            "FOREIGN KEY (order_id) REFERENCES \"order\"(id),"
            "FOREIGN KEY (driver_id) REFERENCES \"user\"(id)"
            ")"
        },
        QSqlQuery {
            "CREATE TABLE vehicle ("
            "id integer PRIMARY KEY AUTOINCREMENT,"
            "company_id int  NOT NULL,"
            "car_number varchar(10) NOT NULL,"
            "model varchar(20) NOT NULL,"
            "FOREIGN KEY (company_id) REFERENCES company(id)"
            ")"
        },
        QSqlQuery {
            "CREATE TABLE vehicle_driver ("
            "id integer PRIMARY KEY AUTOINCREMENT,"
            "vehicle_id int  NOT NULL,"
            "driver_id int  NOT NULL,"
            "start_date timestamp  NOT NULL,"
            "end_date timestamp  NULL,"
            "FOREIGN KEY (vehicle_id) REFERENCES vehicle(id),"
            "FOREIGN KEY (driver_id) REFERENCES \"user\"(id)"
            ")"
        }
    };

    for (auto& query : creationQueries)
    {
        if (!query.exec())
        {
            result = false;
            m_state = DBState::ERROR_TABLES;
            qWarning() << "Table creation failed. Reason: "
                       << query.lastError();
        }
        else
        {
            qWarning() << "Table successfully created! Query: \n" << query.lastQuery();
        }
    }

    return result;
}

void ConnectionManager::DBManagerPrivate::setIsValid(bool isValid)
{
    m_isValid = isValid;
}

bool ConnectionManager::isValid() const
{
    return m_d->m_isValid && m_d->m_database->isValid();
}

ConnectionManager::ConnectionManager()
    : m_d {new DBManagerPrivate {}}
{
    const bool setupResult {m_d->setUp()};
    m_d->setIsValid(setupResult);
}

ConnectionManager::~ConnectionManager()
{
}
}
