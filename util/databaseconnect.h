#ifndef DATABASECONNECT_H
#define DATABASECONNECT_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

class DataBaseConnect
{
public:
    DataBaseConnect();
    static QSqlQuery *getConnect();
};

#endif // DATABASECONNECT_H
