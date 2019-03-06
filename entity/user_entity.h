#ifndef USER_ENTITY_H
#define USER_ENTITY_H
#include <QString>

class User_entity
{
public:
    User_entity();

    QString getName();
    void setName(QString name);

    QString getAccount();
    void setAccount(QString account);

    QString getPassword();
    void setPassword(QString password);

    int getId();
    void setId(int id);

    int getShopId();
    void setShopId(int shopId);
private:
    QString name;
    QString account;
    QString password;
    int id;
    int shopId;

};

#endif // USER_ENTITY_H
