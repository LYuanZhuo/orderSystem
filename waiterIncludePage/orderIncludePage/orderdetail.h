#ifndef ORDERDETAIL_H
#define ORDERDETAIL_H

#include <QDialog>
#include <entity/order_entity.h>
#include "entity/orderfood_entity.h"
#include <QList>
#include <QTableWidgetItem>
namespace Ui {
class OrderDetail;
}

class OrderDetail : public QDialog
{
    Q_OBJECT

public:
    explicit OrderDetail(QWidget *parent = 0);
    ~OrderDetail();
    void setOrderFoods();
    void init(int orderId);
private slots:

    void on_pushButton_pay_clicked();
    void on_pushButton_edit_clicked();


private:
    Ui::OrderDetail *ui;
    int orderId;
    QString tableName;
    double totalPrice;
    QList<OrderFood_entity> orderFood_list;
    Order_entity order;

};

#endif // ORDERDETAIL_H
