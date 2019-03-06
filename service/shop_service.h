#ifndef SHOP_SERVICE_H
#define SHOP_SERVICE_H
#include <QString>
#include "entity/user_entity.h"
class Shop_service
{
public:
    Shop_service();
    QString getShopName(int id);
    User_entity* getShop(QString account, QString password);
};

#endif // SHOP_SERVICE_H
