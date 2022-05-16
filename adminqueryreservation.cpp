#include "adminqueryreservation.h"
#include "ui_adminqueryreservation.h"
#include "adminmenu.h"

adminqueryreservation::adminqueryreservation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminqueryreservation)
{
    ui->setupUi(this);
    model = new QSqlTableModel(this, db);
    showTable();
}

adminqueryreservation::~adminqueryreservation()
{
    delete ui;
}

void adminqueryreservation::showTable()
{
    utils_table->setTableByFilterTeacherId(model, "admin_reservation", NULL);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setModel(model);
    ui->tableView->show();
}

void adminqueryreservation::updateReservation()
{
    QString setCondition = ui->set_condition->currentText();
    updateReservationState(setCondition);
    ui->set_condition->setCurrentIndex(0);
    showTable();
}

void adminqueryreservation::updateReservationState(QString setCondition)
{
    int row = ui->tableView->currentIndex().row();
    QString classroomId = utils_table->getVal(model, row, 0);
    QString teacherId = utils_table->getVal(model, row, 1);
    QString reserveTime = utils_table->getVal(model, row, 4);
    setCondition.compare("不通过") == 0 ? utils->updateClassroomState(classroomId, reserveTime, "空置") : false;
    bool ok = utils->uppdateAdmin_ReservationTableState(classroomId, teacherId, reserveTime, setCondition);
    inform->info_warn(ok, this, "修改成功", "操作失败");
}

void adminqueryreservation::query()
{
    QString queryCondition = ui->query_condition->currentText();
    queryCondition.compare("所有预约") == 0 ? queryCondition = NULL : NULL;
    queryReservationState(queryCondition);
    ui->query_condition->setCurrentIndex(0);
}

void adminqueryreservation::queryReservationState(QString state)
{
    utils_table->setTableByFilteReservationState(model, "admin_reservation", state);
}


void adminqueryreservation::del()
{
    int row = ui->tableView->currentIndex().row();
    QString classroomId = utils_table->getVal(model, row, 0);
    QString teacherId = utils_table->getVal(model, row, 1);
    utils->delAdminCheckedReservation(classroomId, teacherId);
    showTable();
}

void adminqueryreservation::back()
{
    this->hide();
    adminmenu *admin = new adminmenu;
    admin->show();
}
