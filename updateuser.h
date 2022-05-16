#ifndef UPDATEUSER_H
#define UPDATEUSER_H

#include <QWidget>
#include <QSqlTableModel>
#include "utils_db.h"
#include "utils_tablemodel.h"
#include "utils_inform.h"


namespace Ui {
class updateuser;
}

class updateuser : public QWidget
{
    Q_OBJECT

public:
    explicit updateuser(QWidget *parent = nullptr);
    ~updateuser();

private:
    Ui::updateuser *ui;
    QSqlTableModel *model;
    utils_db *utils = new utils_db;
    utils_tablemodel *utils_table = new utils_tablemodel;
    utils_inform *inform = new utils_inform;

private:
    void showUser();

private:
    void refresh();

private slots:
    void add();
    void del();
    void up();
    void back();

};

#endif // UPDATEUSER_H
