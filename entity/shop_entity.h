#ifndef SHOP_ENTITY_H
#define SHOP_ENTITY_H
#include "QString"
class Shop_entity
{
public:
    Shop_entity();
    int getId();
    void setId(int id);

    QString getShopName();
    void setShopName(QString shopName);

    QString getAccount();
    void setAccount(QString account);

    QString getPassword();
    void setPassword(QString password);
private:
    int id;
    QString shopName;
    QString account;
    QString password;

};

#endif // SHOP_ENTITY_H
