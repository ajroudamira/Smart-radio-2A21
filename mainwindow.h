#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QMessageBox>
#include <QMainWindow>
#include<QPrinter>
#include<QPrintDialog>
#include"employe.h"
#include"statistique.h"
#include <QDebug>
#include <QMessageBox>
#include "QIntValidator"
#include <QDateEdit>
#include <QPlainTextEdit>
#include <QPrinter>
//#include <QPrinterInfo>
//#include <QPrintDialog>
#include <QTextStream>
#include <QPainter>
#include <QTextStream>
#include <QFileDialog>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <strstream>
#include <QSystemTrayIcon>
#include <QRegExpValidator>
#include <QDesktopServices>
#include <QUrl>
#include <QGuiApplication>
//#include <QQmlApplicationEngine>
#include <QTcpSocket>
//#include <QQuickItem>
#include <QSystemTrayIcon>
#include <QIntValidator>
#include<arduino.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajouter_clicked();

    void on_supprimer_clicked();

    void on_modifier_clicked();

    void on_tableView_2_clicked(const QModelIndex &index);

    void on_trieid_clicked();

    void on_trienom_clicked();

    void on_trielieu_clicked();

    void on_chercher_clicked();

    void on_PDF_2_clicked();

    void on_seconnecter_clicked();

    void on_seconnecter_2_clicked();
    void update_label();

  //  void on_Send_clicked();

  //  void on_pushButton_clicked();

    //void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    Employe E;
    statistique *s;
    QTcpSocket*mSocket;
    arduino A;
    QByteArray data;
};
#endif // MAINWINDOW_H
