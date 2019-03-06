#ifndef TABLEFOOD_LIST_H
#define TABLEFOOD_LIST_H

#include <QDialog>
#include "entity/orderfood_entity.h"
#include "entity/order_entity.h"
#include <QList>
#include <QTableWidgetItem>
namespace Ui {
class TableFood_list;
}

class TableFood_list : public QDialog
{
    Q_OBJECT

public:
    explicit TableFood_list(QWidget *parent = 0);
    ~TableFood_list();
    void init(int tableId);

private slots:
    void on_tableWidget_itemClicked(QTableWidgetItem *item);

private:
    Ui::TableFood_list *ui;
    QList<OrderFood_entity> list;
    Order_entity order;
    int tableId;
    double totalPrice=0;
    int totalNum=0;
    int foodNum = 0;

    void setList(QList<OrderFood_entity> list);
};

#endif // TABLEFOOD_LIST_H
