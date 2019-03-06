#ifndef ORDERTHEFOOD_H
#define ORDERTHEFOOD_H

#include <QDialog>
#include <entity/food_entity.h>
#include <entity/order_entity.h>
#include <entity/orderfood_entity.h>
namespace Ui {
class OrderTheFood;
}

class OrderTheFood : public QDialog
{
    Q_OBJECT

public:
    explicit OrderTheFood(QWidget *parent = 0);
    ~OrderTheFood();
    void init(int foodId,int tableId);

private slots:
    void on_spinBox_valueChanged(int arg1);

    void on_pushButton_clicked();

private:
    Ui::OrderTheFood *ui;
    Food_entity food;
    Order_entity order;
};

#endif // ORDERTHEFOOD_H
