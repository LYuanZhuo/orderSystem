#include "user_service.h"
#include "dao/user_waiter_dao.h"
#include "dao/user_kitchen_dao.h"
#include "dao/shop_dao.h"
#include <global_variable.h>
#include <qdebug.h>
User_service::User_service()
{

}

User_entity* User_service::getUser(QString account, QString password){
    User_entity *user = NULL;
    int login = Global_variable::loginType;
    if(login==1){
        User_waiter_dao dao;
        user =  dao.getWaiterUser(account,password);
    }else if(login==2){
        User_kitchen_dao dao1;
        user = dao1.getUser(account,password);
    }else if(login==3){
        Shop_dao dao2;
        user = dao2.getShop(account,password);
    }
    return user;
}

QList<User_entity> User_service::getKitchenUsers(int shopId){
    User_kitchen_dao dao;
    return dao.getAll(shopId);
}

QList<User_entity> User_service::getWaiterUsers(int shopId){
    User_waiter_dao dao;
    return dao.getAll(shopId);
}

User_entity User_service::getUser_k(int id){
    User_kitchen_dao dao;
    return dao.getUser(id);
}

User_entity User_service::getUser_w(int id){
    User_waiter_dao dao;
    return dao.getUser(id);
}

bool User_service::addUser_k(User_entity user){
    User_kitchen_dao dao;
    return dao.addUser(user);
}

bool User_service::addUser_w(User_entity user){
    User_waiter_dao dao;
    return dao.addUser(user);
}

bool User_service::updateUser_k(User_entity user){
    User_kitchen_dao dao;
    return dao.updateUser(user);
}

bool User_service::updateUser_w(User_entity user){
    User_waiter_dao dao;
    return dao.updateUser(user);
}

bool User_service::deleteUser_k(int id){
    User_kitchen_dao dao;
    return dao.deleteUser(id);
}
bool User_service::deleteUser_w(int id){
    User_waiter_dao dao;
    return dao.deleteUser(id);
}
bool User_service::addShop(User_entity user){
    Shop_dao dao;
    User_waiter_dao dao1;
    User_kitchen_dao dao2;
    bool b = dao.addShop(user);
    User_entity *u = dao.getShop(user.getAccount(),user.getPassword());
    user.setShopId(u->getShopId());
    delete u;
    return b&&dao1.addUser(user)&& dao2.addUser(user);
}
