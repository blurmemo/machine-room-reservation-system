#ifndef TEACHERRESERVECLASSROOM_H
#define TEACHERRESERVECLASSROOM_H

#include <QWidget>
#include <QSqlTableModel>
#include "utils_db.h"
#include "utils_tablemodel.h"
#include "utils_inform.h"


namespace Ui {
class teacherreserveclassroom;
}

class teacherreserveclassroom : public QWidget
{
    Q_OBJECT

public:
    explicit teacherreserveclassroom(QWidget *parent = nullptr);
    ~teacherreserveclassroom();

private:
    void showTable();
    QSqlTableModel *model;
    utils_db *utils = new utils_db;
    utils_tablemodel *utils_table = new utils_tablemodel;
    utils_inform *inform = new utils_inform;

private:
    Ui::teacherreserveclassroom *ui;


private slots:
    void reserveClassroom();
    void back();
};

#endif // TEACHERRESERVECLASSROOM_H
