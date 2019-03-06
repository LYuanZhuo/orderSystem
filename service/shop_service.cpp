#include "shop_service.h"
#include "dao/shop_dao.h"
Shop_service::Shop_service()
{

}
QString Shop_service::getShopName(int id){
    Shop_dao dao;
    return dao.getShopName(id);
}

User_entity* Shop_service::getShop(QString account, QString password){
    Shop_dao dao;
    return dao.getShop(account,password);
}
