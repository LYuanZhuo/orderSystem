#include "food_dao.h"
#include <qvariant.h>
#include <qdebug.h>
#include <qfile.h>
#include <QBuffer>
#include <QPixmap>
Food_dao::Food_dao()
{

}

QList<Food_entity> getFoods(QString sql){
    QSqlQuery *query = Global_variable::query;
    query->exec(sql);
    QList<Food_entity> list;
    while(query->next()){
    Food_entity food;
    food.setId(query->value("id").toInt());
    food.setImage(query->value("image").toByteArray());
    food.setCategoryId(query->value("categoryId").toInt());
    food.setName(query->value("name").toString());
    food.setOnSale(query->value("isOnSale").toBool());
    food.setPrice(query->value("price").toDouble());
    food.setSaleRate(query->value("saleRate").toDouble());
    food.setShopId(query->value("shopId").toInt());
    food.setSalePrice(query->value("salePrice").toDouble());
    list.append(food);
    }
    return list;
}

QList<Food_entity> Food_dao::getAll(int shopId){

    QString sql = "select * from food where shopId = "+QString::number(shopId);
     return getFoods(sql);
}
QList<Food_entity> Food_dao::getCategoryFoods(int id){

    QString sql = "select * from food where categoryId = "+QString::number(id);
    return getFoods(sql);
}

QList<Food_entity> Food_dao::search(QString keyword){
    QString sql = "select * from food where name like '%"+keyword+"%'";
    return getFoods(sql);
}

Food_entity Food_dao::getFood(int id){
    qDebug()<<id;
    QString sql = "select * from food where id = "+QString::number(id);
    if(getFoods(sql).size()>0) return getFoods(sql)[0];
    else{
        Food_entity food;
        food.setId(-1);
        return food;
    }
}

bool Food_dao::addFood(Food_entity food){
    QString sql = "insert into food (name,price,shopId,isOnSale,categoryId,salePrice,saleRate,image) values(?,?,?,?,?,?,?,?)";
    QSqlQuery* query = Global_variable::query;
    query->prepare(sql);

    //QByteArray data;
    //QFile* file=new QFile(food.getImageAddress()); //file为二进制数据文件名
    //file->open(QIODevice::ReadOnly);
    //data = file->readAll();
    //file->close();
   // QVariant var(data);


//    QPixmap image(food.getImageAddress());
//    QByteArray bytes;
//    QBuffer buffer(&bytes);
//    buffer.open(QIODevice::WriteOnly);
//    image.save(&buffer, "jpg");
//    QVariant imageData(bytes);

//      QPixmap pixmap(food.getImageAddress());
//      QBuffer buffer;
//      buffer.open(QIODevice::ReadWrite);
//      pixmap.save(&buffer,"jpg");
//      QByteArray pixArray;
//      pixArray.append(buffer.data());




    query->bindValue(0,food.getName());
    query->bindValue(1,food.getPrice());
    query->bindValue(2,food.getShopId());
    query->bindValue(3,food.getIsOnSale());
    query->bindValue(4,food.getCategoryId());
    query->bindValue(5,food.getSalePrice());
    query->bindValue(6,food.getSaleRate());
    query->bindValue(7,food.getImage());
    return query->exec();
}
bool Food_dao::updateFood(Food_entity food){
    QString sql = "update food set name=?,price=?,isOnSale=?,categoryId=?,salePrice=?,saleRate=?,image=? where id=?";
    QSqlQuery* query = Global_variable::query;
    query->prepare(sql);

    query->bindValue(0,food.getName());
    query->bindValue(1,food.getPrice());
    query->bindValue(2,food.getIsOnSale());
    query->bindValue(3,food.getCategoryId());
    query->bindValue(4,food.getSalePrice());
    query->bindValue(5,food.getSaleRate());
    query->bindValue(6,food.getImage());
    query->bindValue(7,food.getId());
    return query->exec();
}
bool Food_dao::deleteFood(int id){
    QSqlQuery *query = Global_variable::query;
    QString sql = "delete from food where id = ?";
    query->prepare(sql);
    query->bindValue(0,id);
    return query->exec();
}


