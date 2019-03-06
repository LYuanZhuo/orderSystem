#ifndef ORDERFOOD_ENTITY_H
#define ORDERFOOD_ENTITY_H
#include <QString>

class OrderFood_entity
{
public:
    OrderFood_entity();
private:

    int orderId;
    int foodId;
    QString foodName;
    int num;
    double price;
    double totalPrice;
public:

    int getOrderId();
    void setOrderId(int orderId);

    int getFoodId();
    void setFoodId(int foodId);

    QString getFoodName();
    void setFoodName(QString foodName);

    int getNum();
    void setNum(int num);

    double getPrice();
    void setPrice(double price);

    double getTotalPrice();
    void setTotalPrice(double totalPrice);
};

#endif // ORDERFOOD_ENTITY_H
