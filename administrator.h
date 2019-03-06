#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <QWidget>
#include "AdministratorInclude/canteen.h"
#include "AdministratorInclude/employee.h"
#include "AdministratorInclude/food_a.h"
#include "AdministratorInclude/order_a.h"
#include "AdministratorInclude/table_a.h"

namespace Ui {
class Administrator;
}

class Administrator : public QWidget
{
    Q_OBJECT

public:
    explicit Administrator(QWidget *parent = 0);
    ~Administrator();

signals:
    void signalShowMainWindow();
private slots:
    void on_pushButton_canteen_clicked();

    void on_pushButton_table_clicked();

    void on_pushButton_food_clicked();

    void on_pushButton_order_clicked();

    void on_pushButton_employee_clicked();

    void on_pushButton_exit_clicked();

private:
    Ui::Administrator *ui;
    Food_a* food;
    Table_a* table;
    Canteen* canteen;
    Employee* employee;
    Order_a* order;


    void setSelectStyle(int i);
    void deleteAll();

};

#endif // ADMINISTRATOR_H
