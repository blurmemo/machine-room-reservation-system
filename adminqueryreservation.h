#ifndef ADMINQUERYRESERVATION_H
#define ADMINQUERYRESERVATION_H

#include <QWidget>
#include <QSqlTableModel>
#include "utils_db.h"
#include "utils_tablemodel.h"
#include "utils_inform.h"


namespace Ui {
class adminqueryreservation;
}

class adminqueryreservation : public QWidget
{
    Q_OBJECT

public:
    explicit adminqueryreservation(QWidget *parent = nullptr);
    ~adminqueryreservation();
private:
    void showTable();
    void updateReservationState(QString state);
    void queryReservationState(QString state);

private:
    Ui::adminqueryreservation *ui;
    QSqlTableModel *model;
    utils_db *utils = new utils_db;
    utils_tablemodel *utils_table = new utils_tablemodel;
    utils_inform *inform = new utils_inform;


private slots:
    void updateReservation();
    void query();
    void del();
    void back();
};

#endif // ADMINQUERYRESERVATION_H
