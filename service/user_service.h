#ifndef USER_SERVICE_H
#define USER_SERVICE_H
#include "entity/user_entity.h"
#include "qlist.h"
class User_service
{
public:
    User_service();
    User_entity* getUser(QString account,QString password);
    User_entity getUser_k(int id);
    User_entity getUser_w(int id);
    QList<User_entity> getKitchenUsers(int shopId);
    QList<User_entity> getWaiterUsers(int shopId);
    bool updateUser_k(User_entity user);
    bool deleteUser_k(int id);
    bool addUser_k(User_entity user);
    bool updateUser_w(User_entity user);
    bool deleteUser_w(int id);
    bool addUser_w(User_entity user);

    bool addShop(User_entity user);
};

#endif // USER_SERVICE_H
