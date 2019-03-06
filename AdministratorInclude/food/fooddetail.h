#ifndef FOODDETAIL_H
#define FOODDETAIL_H

#include <QDialog>
#include "entity/food_entity.h"
#include <QEvent>
#include <QMouseEvent>
#include <QByteArray>
namespace Ui {
class FoodDetail;
}

class FoodDetail : public QDialog
{
    Q_OBJECT

public:
    explicit FoodDetail(QWidget *parent = 0);
    ~FoodDetail();
    void init(int id);
    bool eventFilter(QObject *, QEvent *);

private slots:
    void on_pushButton_ok_clicked();

    void on_pushButton_delete_clicked();

    void on_comboBox_activated(int index);

private:
    Ui::FoodDetail *ui;
    int id;
    int category;
    QString imagePath;
    Food_entity food;
    QByteArray imageByte;
};

#endif // FOODDETAIL_H
