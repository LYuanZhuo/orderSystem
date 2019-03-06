#ifndef DATESELECT_H
#define DATESELECT_H

#include <QDialog>

namespace Ui {
class DateSelect;
}

class DateSelect : public QDialog
{
    Q_OBJECT

public:
    explicit DateSelect(QWidget *parent = 0);
    ~DateSelect();
signals:
    void signalDate(QString date);
private slots:

    void on_calendarWidget_clicked(const QDate &date);

private:
    Ui::DateSelect *ui;

};

#endif // DATESELECT_H
