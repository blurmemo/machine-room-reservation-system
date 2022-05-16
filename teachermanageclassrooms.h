#ifndef TEACHERMANAGECLASSROOMS_H
#define TEACHERMANAGECLASSROOMS_H

#include <QWidget>
#include <QSqlTableModel>
#include "utils_tablemodel.h"
#include "utils_db.h"


namespace Ui {
class teachermanageclassrooms;
}

class teachermanageclassrooms : public QWidget
{
    Q_OBJECT

public:
    explicit teachermanageclassrooms(QWidget *parent = nullptr);
    ~teachermanageclassrooms();

private:
    void showTable();
    void queryClassroomByState(QString state);

private:
    Ui::teachermanageclassrooms *ui;
    QSqlTableModel *model;
    utils_tablemodel *utils_table = new utils_tablemodel;


private slots:
    void query();
    void back();
};

#endif // TEACHERMANAGECLASSROOMS_H
