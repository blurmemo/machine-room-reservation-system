#ifndef UTILS_TABLEMODEL_H
#define UTILS_TABLEMODEL_H

#include <QSqlTableModel>

class utils_tablemodel
{
public:
    utils_tablemodel();

public:
    void setTableByFilteClassroomState(QSqlTableModel *model, QString name, QString filter);
    void setTableByFilterTeacherId(QSqlTableModel *model, QString name, QString filter);
    QString getVal(QSqlTableModel *model, int row, int col);
    void reserveTableStyle(QSqlTableModel *model);
    void classroomTableStyle(QSqlTableModel *model);
    void userTableStyle(QSqlTableModel *model);
    void setTableByFilterUser(QSqlTableModel *model, QString name, QString filter);
    void setTableByFilteReservationState(QSqlTableModel *model, QString name, QString filter);
};

#endif // UTILS_TABLEMODEL_H
