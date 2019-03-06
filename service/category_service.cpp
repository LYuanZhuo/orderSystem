#include "category_service.h"
#include <dao/category_dao.h>
Category_service::Category_service()
{

}
QList<Category_entity> Category_service::getAll(int shopId){
    Category_dao dao;
    return dao.getAll(shopId);
}

Category_entity Category_service::getCategoty(int id){
    Category_dao dao;
    return dao.getCategoty(id);
}
bool Category_service::addCategory(Category_entity category){
    Category_dao dao;
    return dao.addCategory(category);
}
bool Category_service::deleteCategory(int id){
    Category_dao dao;
    return dao.deleteCategory(id);
}
bool Category_service::updateCategory(Category_entity category){
    Category_dao dao;
    return dao.updateCategory(category);
}
