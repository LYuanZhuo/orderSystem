#ifndef ORDER_H
#define ORDER_H

#include <QDialog>
#include "service/order_service.h"
#include "global_variable.h"
#include "service/table_service.h"
#include "orderIncludePage/dateselect.h"
#include "orderIncludePage/orderdetail.h"
#include <QDate>
#include <QTableWidgetItem>
namespace Ui {
class Order;
}

class Order : public QDialog
{
    Q_OBJECT

public:
    explicit Order(QWidget *parent = 0);
    ~Order();

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
    Ui::Order *ui;
    QList<Order_entity> order_list;
    QString date;
    int orderType = 1;

    void setOrder();
    void setSelectStyle(int i);
};

#endif // ORDER_H
