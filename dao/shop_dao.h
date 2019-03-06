#ifndef SHOP_DAO_H
#define SHOP_DAO_H
#include <QString>
#include <entity/user_entity.h>
class Shop_dao
{
public:
    Shop_dao();
    QString getShopName(int id);
    User_entity* getShop(QString account,QString password);
    bool addShop(User_entity user);
};

#endif // SHOP_DAO_H
