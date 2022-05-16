#include "teachermanageclassrooms.h"
#include "ui_teachermanageclassrooms.h"
#include "teachermenu.h"


teachermanageclassrooms::teachermanageclassrooms(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::teachermanageclassrooms)
{
    ui->setupUi(this);
    model = new QSqlTableModel(this, db);
    showTable();
}

teachermanageclassrooms::~teachermanageclassrooms()
{
    delete ui;
}

void teachermanageclassrooms::showTable()
{
    queryClassroomByState(NULL);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setModel(model);
    ui->tableView->show();
}

void teachermanageclassrooms::query()
{
    QString queryCondition = ui->query_condition->currentText();
    queryCondition.compare("所有") == 0 ? queryCondition = NULL : NULL;
    queryClassroomByState(queryCondition);
    ui->query_condition->setCurrentIndex(0);
}

void teachermanageclassrooms::queryClassroomByState(QString state)
{
    utils_table->setTableByFilteClassroomState(model, "classroom", state);
}


void teachermanageclassrooms::back()
{
    this->hide();
    teachermenu *teacher = new teachermenu;
    teacher->show();
}
