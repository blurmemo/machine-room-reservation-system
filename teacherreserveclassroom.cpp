#include "teacherreserveclassroom.h"
#include "ui_teacherreserveclassroom.h"
#include "teachermenu.h"

teacherreserveclassroom::teacherreserveclassroom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::teacherreserveclassroom)
{
    ui->setupUi(this);
    model = new QSqlTableModel(this, db);
    showTable();
}

teacherreserveclassroom::~teacherreserveclassroom()
{
    delete ui;
}

void teacherreserveclassroom::showTable()
{
    utils_table->setTableByFilteClassroomState(model, "classroom", "空置");
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setModel(model);
    ui->tableView->show();
}

void teacherreserveclassroom::reserveClassroom()
{
    int row = ui->tableView->currentIndex().row();
    QString classroomId = utils_table->getVal(model, row ,0);
    QString reserveTime = utils_table->getVal(model, row ,6);
    if(classroomId.isEmpty())
    {
        inform->info(this, "请先预约!");
        return;
    }
    QString submitTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    QString teacherName = utils->searchNameById(id);
    utils->addReservation(classroomId, id, teacherName, submitTime, reserveTime);
    utils->updateClassroomState(classroomId, reserveTime, "已预约");
    inform->info(this, "成功预约!");
    showTable();
}

void teacherreserveclassroom::back()
{
    this->hide();
    teachermenu *teacher = new teachermenu;
    teacher->show();
}
