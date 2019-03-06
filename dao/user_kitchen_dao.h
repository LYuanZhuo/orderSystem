#ifndef USER_KITCHEN_DAO_H
#define USER_KITCHEN_DAO_H
#include "entity/user_entity.h"
#include <qlist.h>
class User_kitchen_dao
{
public:
    User_kitchen_dao();
    User_entity* getUser(QString account,QString password);
    User_entity getUser(int id);
    QList<User_entity> getAll(int shopId);
    bool updateUser(User_entity user);
    bool deleteUser(int id);
    bool addUser(User_entity user);

};

#endif // USER_KITCHEN_DAO_H
