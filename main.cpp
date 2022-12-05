#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include<QMainWindow>
#include<QWidget>
#include <QDebug>
#include <QtWidgets/QApplication>
#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
void basics()
{
    QFile file ("test.txt");//bech naaml file essmou keka bech n7ot fih liste des invités absents
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    basics();
    Connection c;
    c.createconnect();
    MainWindow w;
    w.show();
    return a.exec();
}
