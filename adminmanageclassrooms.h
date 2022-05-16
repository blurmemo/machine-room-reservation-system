#ifndef ADMINMANAGECLASSROOMS_H
#define ADMINMANAGECLASSROOMS_H

#include <QWidget>
#include <QSqlTableModel>
#include "utils_db.h"
#include "utils_tablemodel.h"
#include "utils_inform.h"

namespace Ui {
class adminmanageclassrooms;
}

class adminmanageclassrooms : public QWidget
{
    Q_OBJECT

public:
    explicit adminmanageclassrooms(QWidget *parent = nullptr);
    ~adminmanageclassrooms();

private:
    void showTable();
    void setClassroomByState(QString state);
    void queryClassroomByState(QString state);

private:
    Ui::adminmanageclassrooms *ui;
    QSqlTableModel *model;
    utils_db *utils = new utils_db;
    utils_tablemodel *utils_table = new utils_tablemodel;
    utils_inform *inform = new utils_inform;

private slots:
    void query();
    void set();
    void setReservedAll();
    void setEmptyAll();
    void del();
    void back();
};

#endif // ADMINMANAGECLASSROOMS_H
