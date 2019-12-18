#include "serviceaccessor.h"
#include "user.h"

serviceaccessor::serviceaccessor(QObject *parent) : m_userService {new usersservice{}}
{

}

int serviceaccessor::registerUser(QString firstname, QString secondname, QString email, QString password){
    User userToReg = User(firstname,secondname,email,password,"",0);
    int result = m_userService->registerNewUser(userToReg);
    return result;
}

int serviceaccessor::tryLogIn(QString email, QString passwod){
    User userResponse = m_userService->tryLogIn(email,passwod);
    return userResponse.m_id;
}

QString serviceaccessor::getUserRights(int userId){
    User userRespnse = m_userService->getUserById(userId);
    return userRespnse.role();
}
