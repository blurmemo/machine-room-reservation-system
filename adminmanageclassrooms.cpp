#include "adminmanageclassrooms.h"
#include "ui_adminmanageclassrooms.h"
#include "adminmenu.h"

adminmanageclassrooms::adminmanageclassrooms(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminmanageclassrooms)
{
    ui->setupUi(this);
    model = new QSqlTableModel(this, db);
    showTable();
}

adminmanageclassrooms::~adminmanageclassrooms()
{
    delete ui;
}

void adminmanageclassrooms::showTable()
{
    queryClassroomByState(NULL);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setModel(model);
    ui->tableView->show();
}

void adminmanageclassrooms::query()
{
    QString queryCondition = ui->query_condition->currentText();
    queryCondition.compare("所有") == 0 ? queryCondition = NULL : NULL;
    queryClassroomByState(queryCondition);
    ui->query_condition->setCurrentIndex(0);
}

void adminmanageclassrooms::queryClassroomByState(QString state)
{
    utils_table->setTableByFilteClassroomState(model, "classroom", state);
}

void adminmanageclassrooms::set()
{
    QString setCondition = ui->set_condition->currentText();
    setClassroomByState(setCondition);
    ui->set_condition->setCurrentIndex(0);
    showTable();
}

void adminmanageclassrooms::setClassroomByState(QString setCondition)
{
    int row = ui->tableView->currentIndex().row();
    QString classroomId = utils_table->getVal(model, row, 0);
    QString reserveTime = utils_table->getVal(model, row, 6);
    bool ok = utils->updateClassroomState(classroomId, reserveTime, setCondition);
    inform->info_warn(ok, this, "修改成功", "操作失败");
}

void adminmanageclassrooms::setReservedAll()
{
    bool ok = utils->setAllClassroomsReserve();
    inform->info_warn(ok, this, "成功一键设置已预约!", "操作有误!");
    showTable();
}

void adminmanageclassrooms::setEmptyAll()
{
    bool ok = utils->setAllClassroomsEmpty();
    inform->info_warn(ok, this, "成功一键设置空置!", "操作有误!");
    showTable();
}

void adminmanageclassrooms::del()
{
    int row = ui->tableView->currentIndex().row();
    QString classroomId = utils_table->getVal(model, row, 0);
    QString reserveTime = utils_table->getVal(model, row, 6);
    if(classroomId.isNull())
    {
        inform->info(this, "请先选择你要删除的信息!");
        return;
    }
    bool ok = utils->delClassroom(classroomId, reserveTime);
    inform->info_warn(ok, this, "成功删除，如需添加请到后台增加!", "操作有误!");
    showTable();
}

void adminmanageclassrooms::back()
{
    this->hide();
    adminmenu *ad = new adminmenu;
    ad->show();
}
