#ifndef GLOBE_H
#define GLOBE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QPluginLoader>
#include <QDebug>
#include <QMessageBox>
#include <QSqlRecord>
#include <string>
using namespace std;


extern QSqlDatabase db;
extern string hostname;
extern string databaseName;
extern string databaseUsername;
extern string databasePassword;
extern int port;
extern QString id;



#endif // GLOBE_H
