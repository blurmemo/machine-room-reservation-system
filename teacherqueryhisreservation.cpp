#include "teacherqueryhisreservation.h"
#include "ui_teacherqueryhisreservation.h"
#include "teachermenu.h"

teacherqueryhisreservation::teacherqueryhisreservation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::teacherqueryhisreservation)
{
    ui->setupUi(this);
    model = new QSqlTableModel(this, db);
    showTable();
}

teacherqueryhisreservation::~teacherqueryhisreservation()
{
    delete ui;
}

void teacherqueryhisreservation::showTable()
{
    utils_table->setTableByFilterTeacherId(model, "admin_reservation", id);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setModel(model);
    ui->tableView->show();
}


void teacherqueryhisreservation::updateReservedTime()
{
    int row = ui->tableView->currentIndex().row();
    QString upDateTime = ui->update_time_value->currentText();
    QString classroomId = utils_table->getVal(model, row ,0);
    QString reserveTime = utils_table->getVal(model, row ,4);
    QString state = utils_table->getVal(model, row ,5);
    if(classroomId.isEmpty())
    {
        inform->info(this, "请先选择要修改的预约!");
        return;
    }
    bool ok = false;
    if(state.contains("待审核"))
    {
        ok = utils->teacherUpdatehisReserveTime(classroomId, reserveTime, upDateTime, "待审核");
        inform->info_warn(ok, this, "修改预约时间成功!", "修改失败!");
    } else
    {
        inform->warn(this, "当前已审核, 不能修改!");
    }
    ui->update_time_value->setCurrentIndex(0);
    showTable();
}

void teacherqueryhisreservation::addClassroomIdinCombox()
{
    ui->update_classroom_id_value->clear();
    ui->update_classroom_id_value->addItem("请选择");
    int row = ui->tableView->currentIndex().row();
    QString reserveTime = utils_table->getVal(model, row ,4);
    QStringList ids = utils->queryALLClassroomIdByTimeandState(reserveTime, "空置");
    ui->update_classroom_id_value->addItems(ids);
}

void teacherqueryhisreservation::addTimeinCombox()
{
    ui->update_time_value->clear();
    ui->update_time_value->addItem("请选择");
    int row = ui->tableView->currentIndex().row();
    QString id = utils_table->getVal(model, row ,0);
    QStringList reserveTimes = utils->queryAbleReserveTimeByClassroomId(id, "空置");
    ui->update_time_value->addItems(reserveTimes);
}

void teacherqueryhisreservation::updateReservedClassroomId()
{
    int row = ui->tableView->currentIndex().row();
    QString classroomId = utils_table->getVal(model, row ,0);
    QString reserveTime = utils_table->getVal(model, row ,4);
    QString state = utils_table->getVal(model, row ,5);
    QString upClassroomId = ui->update_classroom_id_value->currentText();
    if(classroomId.isEmpty())
    {
        QMessageBox::information(this ,tr("提示") , tr("请先选择要修改的预约!"));
        return;
    }
    bool ok = false;
    if(state.contains("待审核"))
    {
        ok = utils->teacherUpdatehisReserveClassroom(classroomId, reserveTime, upClassroomId, "待审核");
        inform->info_warn(ok, this, "修改预约教室号成功!", "修改失败!");
    } else
    {
        inform->warn(this, "当前已审核, 不能修改!");
    }
    showTable();
}

void teacherqueryhisreservation::del()
{
    int row = ui->tableView->currentIndex().row();
    QString classroomId = utils_table->getVal(model, row ,0);
    QString reserveTime = utils_table->getVal(model, row ,4);
    if(classroomId.isEmpty())
    {
        inform->info(this, "请先选择要删除的预约!");
        return;
    }
    bool ok = utils->teacherDelSingleReservatiom(id, classroomId, reserveTime);
    utils->updateClassroomState(classroomId, reserveTime, "空置");
    inform->info_warn(ok, this, "撤销预约成功!", "撤销失败!");
    showTable();
}

void teacherqueryhisreservation::back()
{
    this->hide();
    teachermenu *teacher = new teachermenu;
    teacher->show();
}
