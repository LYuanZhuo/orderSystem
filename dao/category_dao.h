#ifndef CATEGORY_DAO_H
#define CATEGORY_DAO_H
#include "entity/category_entity.h"
#include <qlist.h>
class Category_dao
{
public:
    Category_dao();
    QList<Category_entity> getAll(int shopId);
    Category_entity getCategoty(int id);
    bool addCategory(Category_entity category);
    bool deleteCategory(int id);
    bool updateCategory(Category_entity category);
};

#endif // CATEGORY_DAO_H
