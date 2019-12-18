#ifndef SERVICEACCESSOR_H
#define SERVICEACCESSOR_H
#include <QObject>
#include "usersservice.h"

class serviceaccessor : public QObject
{
    Q_OBJECT
public:
    explicit serviceaccessor(QObject *parent = nullptr);
    Q_INVOKABLE int registerUser(QString firstname,QString secondname,QString email,QString password);
    Q_INVOKABLE int tryLogIn(QString email, QString passwod);
    Q_INVOKABLE QString getUserRights(int userId);
private:
        std::unique_ptr<usersservice> m_userService;
};

#endif // SERVICEACCESSOR_H
