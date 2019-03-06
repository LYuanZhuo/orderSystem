#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "login.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void closeMainWindow();
    void showMainWindow();
private slots:

    void on_pushButton_waiter_clicked();

    void on_pushButton_kitchen_clicked();

    void on_pushButton_manager_clicked();

private:
    Ui::MainWindow *ui;
    login *l;

};

#endif // MAINWINDOW_H
