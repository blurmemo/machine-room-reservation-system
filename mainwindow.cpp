#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "adminmenu.h"
#include "teachermenu.h"
#include <QProcess>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->username_value->setFocus();
    ui->teacher->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::login()
{ 
    QString username = ui->username_value->text();
    QString password = ui->password_value->text();
    if(ui->admin->isChecked())
    {
        if(utils->queryUser(username, password, "admin"))
        {
            id = username;
            qDebug() << "系统管理员登录成功";
            adminMenu();
        }
        else{
            qDebug() << "账号或密码错误";
            wrongMenu(ui->admin);
        }
    }
    else if(ui->teacher->isChecked())
    {
        if(utils->queryUser(username, password, "teacher"))
        {
            id = username;
            qDebug() << "登录成功";
            teacherMenu();
        }
        else{
            qDebug() << "账号或密码错误";
            wrongMenu(ui->teacher);
        }
    }
    else {
        wrongMenu(ui->teacher);
    }
}



void MainWindow::adminMenu()
{
    this->hide();
    adminmenu *admin = new adminmenu;
    admin->show();
}

void MainWindow::teacherMenu()
{
    this->hide();
    teachermenu *teacher = new teachermenu;
    teacher->show();

}

void MainWindow::wrongMenu(QAbstractButton *btn)
{
    inform->warn(this, "用户名或密码错误!");
    clearBtn(btn);
    ui->username_value->clear();
    ui->password_value->clear();
    ui->username_value->setFocus();
    ui->teacher->setChecked(true);
}

void MainWindow::clearBtn(QAbstractButton *btn)
{

    btn->setAutoExclusive(false);
    btn->setChecked(false);
    btn->setAutoExclusive(true);
}






