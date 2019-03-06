#ifndef EDITEMPLOYEE_H
#define EDITEMPLOYEE_H

#include <QDialog>
#include "entity/user_entity.h"
#include "service/user_service.h"

namespace Ui {
class EditEmployee;
}

class EditEmployee : public QDialog
{
    Q_OBJECT

public:
    explicit EditEmployee(QWidget *parent = 0);
    ~EditEmployee();
    void init(int id,int type);

private slots:
    void on_pushButton_clicked();

private:
    Ui::EditEmployee *ui;
    User_entity user;
    int id;
    int type;
    User_service service;

};

#endif // EDITEMPLOYEE_H
