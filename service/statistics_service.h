#ifndef STATISTICS_SERVICE_H
#define STATISTICS_SERVICE_H
#include <qlist.h>
#include <entity/sales_entity.h>

class Statistics_service
{
public:
    Statistics_service();
    QList<Sales_entity> getSales(int shopId);
    QList<int> getTables(int shopId);

};

#endif // STATISTICS_SERVICE_H
