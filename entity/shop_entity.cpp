#include "shop_entity.h"

Shop_entity::Shop_entity()
{

}

int Shop_entity::getId(){
    return this->id;
}

void Shop_entity::setId(int id){
    this->id = id;
}

QString Shop_entity::getShopName(){
    return this->shopName;
}

void Shop_entity::setShopName(QString shopName){
    this->shopName = shopName;
}

QString Shop_entity::getAccount(){
    return this->account;
}

void Shop_entity::setAccount(QString account){
    this->account = account;
}

QString Shop_entity::getPassword(){
    return this->password;
}

void Shop_entity::setPassword(QString password){
    this->password = password;
}
