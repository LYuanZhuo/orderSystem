#ifndef KITCHEN_H
#define KITCHEN_H

#include <QWidget>
#include "waiterIncludePage/order.h"
#include "entity/foodneed_entity.h"
#include <qtimer.h>
namespace Ui {
class Kitchen;
}

class Kitchen : public QWidget
{
    Q_OBJECT

public:
    explicit Kitchen(QWidget *parent = 0);
    ~Kitchen();
    void update(int status);
private slots:
    void on_tableWidget_itemClicked(QTableWidgetItem *item);

    void on_pushButton_flash_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_pushButton_quitLogin_clicked();

    void on_spinBox_valueChanged(int arg1);

    void flash();

private:
    Ui::Kitchen *ui;
    QList<FoodNeed_entity> list;
    void setList(QList<FoodNeed_entity> list);
    void setList1(QList<FoodNeed_entity> list);
    int status = 1;
    int flashSec = 20;
    QTimer *qTimer;
signals:
    void signalShowMainWindow();
};

#endif // KITCHEN_H
