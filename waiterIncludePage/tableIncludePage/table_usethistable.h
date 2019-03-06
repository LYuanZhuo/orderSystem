#ifndef TABLE_USETHISTABLE_H
#define TABLE_USETHISTABLE_H

#include <QDialog>
#include <entity/table_entity.h>
namespace Ui {
class table_usethistable;
}

class table_usethistable : public QDialog
{
    Q_OBJECT

public:
    explicit table_usethistable(QWidget *parent = 0);
    ~table_usethistable();
    void init(int tableId);

private slots:
    void on_pushButton_clicked();
signals:
    void signalUpdate();
private:
    Ui::table_usethistable *ui;
    int tableId;
    Table_entity *table;
};

#endif // TABLE_USETHISTABLE_H
