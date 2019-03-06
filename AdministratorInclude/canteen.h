#ifndef CANTEEN_H
#define CANTEEN_H

#include <QWidget>
#include "service/statistics_service.h"
#include <qlist.h>
#include "entity/sales_entity.h"
#include <qtimer.h>
namespace Ui {
class Canteen;
}

class Canteen : public QWidget
{
    Q_OBJECT

public:
    explicit Canteen(QWidget *parent = 0);
    ~Canteen();
private slots:
    void updateShop();
private:
    Ui::Canteen *ui;

    void setList();

    QTimer *qtimer;
    QList<Sales_entity> list;
    Sales_entity sale;
    QList<int> tableInfo;
    Statistics_service service;
};

#endif // CANTEEN_H
