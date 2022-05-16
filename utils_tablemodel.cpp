#include "utils_tablemodel.h"

utils_tablemodel::utils_tablemodel()
{

}

void utils_tablemodel::setTableByFilterUser(QSqlTableModel *model, QString name, QString filter)
{
    model->setTable(name);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    userTableStyle(model);
    if(!filter.isNull())
    {
        ;
    }
    model->select();
}


void utils_tablemodel::setTableByFilteClassroomState(QSqlTableModel *model, QString name, QString filter)
{
    model->setTable(name);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    classroomTableStyle(model);
    if(!filter.isNull())
    {
        model->setFilter(QObject::tr("state = '%1'").arg(filter));
    }
    model->select();
}

void utils_tablemodel::setTableByFilterTeacherId(QSqlTableModel *model, QString name, QString filter)
{
    model->setTable(name);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    reserveTableStyle(model);
    if(!filter.isNull())
    {
        model->setFilter(QObject::tr("teacherId = '%1'").arg(filter));
    }
    model->select();
}

void utils_tablemodel::setTableByFilteReservationState(QSqlTableModel *model, QString name, QString filter)
{
    model->setTable(name);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    reserveTableStyle(model);
    if(!filter.isNull())
    {
        model->setFilter(QObject::tr("state = '%1'").arg(filter));
    }
    model->select();
}

QString utils_tablemodel::getVal(QSqlTableModel *model, int row, int col)
{
    return model->data(model->index(row,col)).toString();
}

void utils_tablemodel::reserveTableStyle(QSqlTableModel *model)
{
    model->setHeaderData(0, Qt::Horizontal, model->tr("教室号"));
    model->setHeaderData(1, Qt::Horizontal, model->tr("教师工号"));
    model->setHeaderData(2, Qt::Horizontal, model->tr("教师姓名"));
    model->setHeaderData(3, Qt::Horizontal, model->tr("提交时间"));
    model->setHeaderData(4, Qt::Horizontal, model->tr("预约时间"));
    model->setHeaderData(5, Qt::Horizontal, model->tr("当前状态"));
}

void utils_tablemodel::classroomTableStyle(QSqlTableModel *model)
{
    model->setHeaderData(0, Qt::Horizontal, model->tr("教室号"));
    model->setHeaderData(1, Qt::Horizontal, model->tr("教室名称"));
    model->setHeaderData(2, Qt::Horizontal, model->tr("教室类型"));
    model->setHeaderData(3, Qt::Horizontal, model->tr("最大容纳量"));
    model->setHeaderData(4, Qt::Horizontal, model->tr("空调数量"));
    model->setHeaderData(5, Qt::Horizontal, model->tr("监控数量"));
    model->setHeaderData(6, Qt::Horizontal, model->tr("预约时间"));
    model->setHeaderData(7, Qt::Horizontal, model->tr("当前状态"));
}

void utils_tablemodel::userTableStyle(QSqlTableModel *model)
{
    model->setHeaderData(0, Qt::Horizontal, model->tr("用户名"));
    model->setHeaderData(1, Qt::Horizontal, model->tr("密码"));
}



