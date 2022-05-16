#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QString path = QDir::currentPath();QApplication::addLibraryPath(path+QString("/plugins"));QPluginLoader loader(path+QString("/plugins/sqldrivers/qsqlite.dll"));
    a.addLibraryPath("./plugins");
    MainWindow w;
    w.show();
    return a.exec();
}
