#ifndef CATEGORY_SERVICE_H
#define CATEGORY_SERVICE_H
#include <qlist.h>
#include "entity/category_entity.h"
class Category_service
{
public:
    Category_service();
    QList<Category_entity> getAll(int shopId);
    Category_entity getCategoty(int id);
    bool addCategory(Category_entity category);
    bool deleteCategory(int id);
    bool updateCategory(Category_entity category);
};

#endif // CATEGORY_SERVICE_H
