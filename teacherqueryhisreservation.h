#ifndef TEACHERQUERYHISRESERVATION_H
#define TEACHERQUERYHISRESERVATION_H

#include <QWidget>
#include <QSqlTableModel>
#include "utils_db.h"
#include "utils_tablemodel.h"
#include "utils_inform.h"

namespace Ui {
class teacherqueryhisreservation;
}

class teacherqueryhisreservation : public QWidget
{
    Q_OBJECT

public:
    explicit teacherqueryhisreservation(QWidget *parent = nullptr);
    ~teacherqueryhisreservation();

private:
    Ui::teacherqueryhisreservation *ui;
    QSqlTableModel *model;
    utils_db *utils = new utils_db;
    utils_tablemodel *utils_table = new utils_tablemodel;
    utils_inform *inform = new utils_inform;


private:
    void showTable();

private slots:
    void updateReservedTime();
    void updateReservedClassroomId();
    void del();
    void back();
    void addClassroomIdinCombox();
    void addTimeinCombox();
};

#endif // TEACHERQUERYHISRESERVATION_H
