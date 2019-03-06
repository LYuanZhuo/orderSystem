#ifndef TABLE_H
#define TABLE_H

#include <QWidget>
#include "entity/table_entity.h"
#include <QList>
#include <QTableWidgetItem>
namespace Ui {
class table;
}

class table : public QWidget
{
    Q_OBJECT

public:
    explicit table(QWidget *parent = 0);
    ~table();
private slots:

    void on_pushButton_allTable_clicked();

    void on_pushButton_freeTable_clicked();

    void on_pushButton_UsingTable_clicked();

    void on_pushButton_certain_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_tableWidget_itemClicked(QTableWidgetItem *item);

    void init();

private:
    Ui::table *ui;
    QList<Table_entity> table_list;//当前展示的所有桌子
    int tableKind = 1;//1代表全部，2代表空闲，3代表正在使用
    void setTableList();//设置需要展示的所有桌子
    void setSelectStyle(int i);
};

#endif // TABLE_H
