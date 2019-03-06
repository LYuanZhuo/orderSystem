#ifndef WAITER_H
#define WAITER_H

#include <QWidget>
#include "waiterIncludePage/table.h"
#include "waiterIncludePage/food.h"
#include "waiterIncludePage/order.h"
#include "entity/user_entity.h"
namespace Ui {
class Waiter;
}

class Waiter : public QWidget
{
    Q_OBJECT

public:
    explicit Waiter(QWidget *parent = 0);
    ~Waiter();
    void init();
private slots:
    void on_pushButton_table_clicked();

    void on_pushButton_food_clicked();

    void on_pushButton_order_clicked();

    void on_pushButton_exitLogin_clicked();

private:
    Ui::Waiter *ui;
    table *tablePage;
    Food *foodPage;
    Order *orderPage;
    User_entity *user;

    void setSelectStyle(int i);
    void deleteAll();
signals:
    void waiterSignalShowMainWindow();
    void signalUpdateTable();
    void signalUpdateOrder();
    void signalUpdateFood();
};

#endif // WAITER_H
