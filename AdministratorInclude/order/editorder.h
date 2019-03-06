#ifndef EDITORDER_H
#define EDITORDER_H

#include <QDialog>
#include "entity/order_entity.h"
#include "service/table_service.h"
#include "service/order_service.h"
#include "qlist.h"
namespace Ui {
class EditOrder;
}

class EditOrder : public QDialog
{
    Q_OBJECT

public:
    explicit EditOrder(QWidget *parent = 0);
    ~EditOrder();
    void init(int id);

private slots:
    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::EditOrder *ui;
    int id;
    int tableId;
    Order_entity order;
    QList<Table_entity> list;
    Order_service order_service;
    Table_service table_service;

    void setTables();

};

#endif // EDITORDER_H
