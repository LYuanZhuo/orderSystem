#include "mainwindow.h"
#include <QApplication>
#include "global_variable.h"
#include "util/databaseconnect.h"

void init();
int main(int argc, char *argv[])
{
    init();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

}

void init(){
    Global_variable::query = DataBaseConnect::getConnect();
}
