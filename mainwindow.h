#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#include <QAbstractButton>
#include "utils_db.h"
#include "utils_inform.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    utils_db *utils = new utils_db;
    utils_inform *inform = new utils_inform;

private slots:
    void login();
    void adminMenu();
    void teacherMenu();
    void wrongMenu(QAbstractButton *btn);
    void clearBtn(QAbstractButton *btn);
};
#endif // MAINWINDOW_H
