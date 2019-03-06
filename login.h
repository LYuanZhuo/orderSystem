#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "loginIncludePage/mainlogin.h"
#include "loginIncludePage/tip.h"

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();

private:
    Ui::login *ui;
    MainLogin *mainLogin;
    Tip *tip;
signals:
    void loginSignalCloseMainWindow();
    void loginSignalShowMainWindow();
private slots:
    void closeMainWindow();//关闭主窗口
    void showMainWindow();//打开主窗口
    void closeWindow();//关闭当前窗口
    void loginWait();//转到stackwidget的加载中的子页面


};

#endif // LOGIN_H
