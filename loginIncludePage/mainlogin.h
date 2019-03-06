#ifndef MAINLOGIN_H
#define MAINLOGIN_H

#include <QWidget>
#include <waiter.h>
#include <kitchen.h>
#include "entity/user_entity.h"
#include "service/user_service.h"
#include "loginIncludePage/tip.h"
#include "administrator.h"
namespace Ui {
class MainLogin;
}

class MainLogin : public QWidget
{
    Q_OBJECT

public:
    explicit MainLogin(QWidget *parent = 0);
    ~MainLogin();
private slots:
    void on_pushButton_clicked();
    void showMainWindow();//打开主窗口
    void on_pushButton_register_clicked();

private:
    Ui::MainLogin *ui;
    Waiter *waiter;
    Kitchen *kitchen;
    Administrator* administrator;
    Tip * tip;

    void waiterLogin();
    void kitchenLogin();
    void administratorLogin();
signals:
    void loginSignalCloseMainWindow();
    void loginSignalShowMainWindow();
    void closeWindow();
    void loginWait();
};

#endif // MAINLOGIN_H
