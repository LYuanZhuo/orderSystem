#ifndef SALES_ENTITY_H
#define SALES_ENTITY_H
#include <qstring.h>

class Sales_entity
{
public:
    Sales_entity();
    QString getDate();
    void setDate(QString date);

    int getNum();
    void setNum(int num);

    double getSum();
    void setSum(double sum);
private:
    QString date;
    int num;
    double sum;
};

#endif // SALES_ENTITY_H
