#ifndef USER_WAITER_DAO_H
#define USER_WAITER_DAO_H
#include "entity/user_entity.h"
#include "qlist.h"
class User_waiter_dao
{
public:
    User_waiter_dao();
    User_entity* getWaiterUser(QString account,QString password);
    User_entity getUser(int id);
    QList<User_entity> getAll(int shopId);
    bool updateUser(User_entity user);
    bool deleteUser(int id);
    bool addUser(User_entity user);
};

#endif // USER_WAITER_DAO_H
