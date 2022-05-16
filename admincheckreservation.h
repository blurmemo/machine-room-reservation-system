#ifndef ADMINCHECKRESERVATION_H
#define ADMINCHECKRESERVATION_H

#include <QWidget>
#include <QSqlTableModel>
#include "utils_db.h"
#include "utils_tablemodel.h"
#include "utils_inform.h"

namespace Ui {
class admincheckreservation;
}

class admincheckreservation : public QWidget
{
    Q_OBJECT

public:
    explicit admincheckreservation(QWidget *parent = nullptr);
    ~admincheckreservation();

private:
    Ui::admincheckreservation *ui;
    QSqlTableModel *model;
    utils_db *utils = new utils_db;
    utils_tablemodel *utils_table = new utils_tablemodel;
    utils_inform *inform = new utils_inform;

private:
    void showTable();
    void check(QString state);

private slots:
    void pass();
    void cancel();
    void back();
};

#endif // ADMINCHECKRESERVATION_H
