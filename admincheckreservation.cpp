#include "admincheckreservation.h"
#include "ui_admincheckreservation.h"
#include "adminmenu.h"


admincheckreservation::admincheckreservation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::admincheckreservation)
{
    ui->setupUi(this);
    model = new QSqlTableModel(this, db);
    showTable();
}

admincheckreservation::~admincheckreservation()
{
    delete ui;
}

void admincheckreservation::showTable()
{
    utils_table->setTableByFilteClassroomState(model, "admin_reservation", "待审核");
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setModel(model);
    ui->tableView->show();
}

void admincheckreservation::check(QString state)
{
    int row = ui->tableView->currentIndex().row();
    QString classroomId = utils_table->getVal(model, row, 0);
    QString teacherId = utils_table->getVal(model, row, 1);
    QString reserveTime = utils_table->getVal(model, row, 4);
    bool ok = utils->uppdateAdmin_ReservationTableState(classroomId, teacherId, reserveTime, state);
    inform->info_warn(ok, this, "完成审核", "操作失败");
}

void admincheckreservation::pass()
{
    check(ui->pass->text());
    showTable();
}

void admincheckreservation::cancel()
{
    check(ui->pass->text());
    showTable();
}

void admincheckreservation::back()
{
    this->hide();
    adminmenu *admin = new adminmenu;
    admin->show();
}
