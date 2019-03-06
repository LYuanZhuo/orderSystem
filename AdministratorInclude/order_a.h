#ifndef ORDER_A_H
#define ORDER_A_H

#include <QWidget>
#include "service/order_service.h"
#include "global_variable.h"
#include "service/table_service.h"
#include "waiterIncludePage/orderIncludePage/dateselect.h"
#include "waiterIncludePage/orderIncludePage/orderdetail.h"
#include <QDate>
#include <QTableWidgetItem>
#pragma execution_character_set("utf-8")
namespace Ui {
class Order_a;
}

class Order_a : public QWidget
{
    Q_OBJECT

public:
    explicit Order_a(QWidget *parent = 0);
    ~Order_a();
private slots:
    void on_pushButton_allOrder_clicked();

    void on_pushButton_unOkOrder_clicked();

    void on_pushButton_okOrder_clicked();

    void on_pushButton_clicked();

    void setDate(QString date);

    void on_tableWidget_itemClicked(QTableWidgetItem *item);

    void init();

    void update();
private:
    Ui::Order_a *ui;
    QList<Order_entity> order_list;
    QString date;
    int orderType = 1;

    void setOrder();
    void setSelectStyle(int i);
};

#endif // ORDER_A_H
