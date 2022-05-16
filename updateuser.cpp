#include "updateuser.h"
#include "ui_updateuser.h"
#include "adminmenu.h"

updateuser::updateuser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::updateuser)
{
    ui->setupUi(this);
    model = new QSqlTableModel(this, db);
    showUser();
}

updateuser::~updateuser()
{
    delete ui;
}

void updateuser::refresh()
{
    this->hide();
    updateuser *u = new updateuser;
    u->show();
}

void updateuser::showUser()
{
    utils_table->setTableByFilterUser(model, "user_teacher", NULL);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setModel(model);
    ui->tableView->show();
}

void updateuser::add()
{
    QString username = ui->username_value->text();
    QString password = ui->password_value->text();
    bool ok = utils->insertUser(username, password);
    inform->info_warn(ok, this, "添加成功!", "已存在该用户，请不要重复添加!");
    ui->username_value->clear();
    ui->password_value->clear();
    ui->username_value->setFocus();
    showUser();
}

void updateuser::del()
{
    int row = ui->tableView->currentIndex().row();
    QString username = utils_table->getVal(model, row ,0);
    bool ok = utils->deleteUser(username);
    inform->info_warn(ok, this, "删除成功!", "删除失败!");
    showUser();
}

void updateuser::up()
{
    int row = ui->tableView->currentIndex().row();
    QString username = utils_table->getVal(model, row ,0);
    QString password = ui->password_value->text();
    bool ok = utils->updateUser(username, password);
    inform->info_warn(ok, this, "修改成功!", "修改失败!");
    ui->password_value->clear();
    ui->username_value->setFocus();
    showUser();
}

void updateuser::back()
{
    this->hide();
    adminmenu *admin = new adminmenu;
    admin->show();
}
