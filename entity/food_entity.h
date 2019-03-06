#ifndef FOOD_ENTITY_H
#define FOOD_ENTITY_H
#include <QString>
#include <qbytearray.h>
class Food_entity
{
public:
    Food_entity();

    QString getName();
    void setName(QString name);

    double getPrice();
    void setPrice(double price);

    QString getImageAddress();
    void setImageAddress(QString imageAddress);

    int getId();
    void setId(int id);

    bool getIsOnSale();
    void setOnSale(bool onSale);

    double getSaleRate();
    void setSaleRate(double saleRate);

    int getCategoryId();
    void setCategoryId(int categoryId);

    int getShopId();
    void setShopId(int shopId);

    double getSalePrice();
    void setSalePrice(double salePrice);

    QByteArray getImage();
    void setImage(QByteArray imageByte);


private:
    int id;
    QString name;
    double price;
    QString imageAddress;
    bool isOnSale;
    double saleRate;
    double salePrice;
    int categoryId;
    int shopId;
    QByteArray imageByte;
};

#endif // FOOD_ENTITY_H
