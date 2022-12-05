#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

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
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_tableView_2_activated(const QModelIndex &index);
    void on_ajouter_clicked();

    void on_supprimer_clicked();

    void on_modifier_clicked();

    void on_tableView_2_clicked(const QModelIndex &index);

    void on_trieid_clicked();

    void on_trienom_clicked();

    void on_trielieu_clicked();

    void on_chercher_clicked();

    void on_PDF_2_clicked();


private:
    Ui::Dialog *ui;


    Employe E;
    statistique *s;
};

#endif // DIALOG_H
