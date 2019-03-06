#include "category_dao.h"
#include "global_variable.h"
#include <QVariant>
Category_dao::Category_dao()
{

}
QList<Category_entity> Category_dao::getAll(int shopId){

    QSqlQuery* query = Global_variable::query;
    QString sql = "select * from category where shopId = "+QString::number(shopId);
    query->exec(sql);
    QList<Category_entity> list;
    while(query->next()){
        Category_entity category;
        category.setId(query->value("id").toInt());
        category.setName(query->value("name").toString());
        category.setShopId(query->value("shopId").toInt());
        list.append(category);
    }
    return list;
}

Category_entity Category_dao::getCategoty(int id)
{
    QSqlQuery* query = Global_variable::query;
    QString sql = "select * from category where id = "+QString::number(id);
    query->exec(sql);
    Category_entity category;
    category.setId(-1);
    if(query->next()){
        category.setId(query->value("id").toInt());
        category.setName(query->value("name").toString());
        category.setShopId(query->value("shopId").toInt());
    }
    return category;
}

bool Category_dao::addCategory(Category_entity category){
    QSqlQuery* query = Global_variable::query;
    QString sql = "insert into category (name,shopId) values(?,?)";
    query->prepare(sql);
    query->bindValue(0,category.getName());
    query->bindValue(1,category.getShopId());
    return query->exec();
}
bool Category_dao::updateCategory(Category_entity category){
    QSqlQuery* query = Global_variable::query;
    QString sql = "update category set name=? where id=?";
    query->prepare(sql);
    query->bindValue(0,category.getName());
    query->bindValue(1,category.getId());
    return query->exec();
}
bool Category_dao::deleteCategory(int id){
    QSqlQuery* query = Global_variable::query;
    QString sql = "delete from category where id=?";
    query->prepare(sql);
    query->bindValue(0,id);
    return query->exec();
}
