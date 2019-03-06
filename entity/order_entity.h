#ifndef ORDER_ENTITY_H
#define ORDER_ENTITY_H
#include <QString>
class Order_entity
{

public:
    Order_entity();

    int getId();
    void setId(int id);

    int getTableId();
    void setTableId(int tableId);

    int getShopId();
    void setShopId(int shopId);

    int getPersonNum();
    void setPersonNum(int personNum);

    QString getOrderNum();
    void setOrderNum(QString orderNum);

    bool getIsPay();
    void setIsPay(bool isPay);

    double getPrice();
    void setPrice(double price);

    QString getTime();
    void setTime(QString time);

    QString getPayTime();
    void setPayTime(QString payTime);

    QString getTableName();
    void setTableName(QString tableName);

private:
    int id;
    int tableId;
    QString tableName;
    int shopId;
    int personNum;
    QString orderNum;
    bool isPay;
    double price;
    QString time;
    QString payTime;

};

#endif // ORDER_ENTITY_H
