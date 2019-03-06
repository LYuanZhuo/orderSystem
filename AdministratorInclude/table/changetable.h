#ifndef CHANGETABLE_H
#define CHANGETABLE_H

#include <QDialog>
#include <entity/table_entity.h>
namespace Ui {
class ChangeTable;
}

class ChangeTable : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeTable(QWidget *parent = 0);
    ~ChangeTable();
    void init(int id);

private slots:
    void on_pushButton_clicked();

private:
    Ui::ChangeTable *ui;
    Table_entity* table;
    int id;
signals:


};

#endif // CHANGETABLE_H
