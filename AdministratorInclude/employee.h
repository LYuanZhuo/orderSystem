#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <qlist.h>
#include "entity/user_entity.h"
#include "service/user_service.h"
#include <QWidget>
#include <QTableWidgetItem>

namespace Ui {
class Employee;
}

class Employee : public QWidget
{
    Q_OBJECT

public:
    explicit Employee(QWidget *parent = 0);
    ~Employee();
    void setWaiter();
    void setKitchen();
    void update_k();
    void update_w();


private slots:
    void on_pushButton_kitchen_clicked();

    void on_pushButton_waiter_clicked();

    void on_tableWidget_kitchen_itemClicked(QTableWidgetItem *item);


    void on_tableWidget_waiter_itemClicked(QTableWidgetItem *item);

private:
    Ui::Employee *ui;
    QList<User_entity> list_w;
    QList<User_entity> list_k;
    User_service service;

};

#endif // EMPLOYEE_H
