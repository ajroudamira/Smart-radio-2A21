#include "dialog.h"
#include "ui_dialog.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"employe.h"
#include<QIntValidator>
#include<QObject>
#include<QMainWindow>
#include<QSqlQuery>
#include <QDesktopServices>
#include<QPrinter>
#include<QPrintDialog>
#include <QPrintPreviewDialog>
#include <QPdfWriter>
#include <QPainter>
#include<QUrl>
#include<QDialog>
#include<smtp.h>
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
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->le_id->setValidator( new QIntValidator(0, 999999, this));
    ui->le_nom->setMaxLength(10);
    ui->le_prenom->setMaxLength(10);
    ui->tableView_2->setModel(E.afficher());
    QRegularExpression rx("^[A-Za-z]+$");//controle de saisie.

    QValidator *validator = new QRegularExpressionValidator(rx, this);
            ui->le_nom->setValidator(validator);
             ui->le_prenom->setValidator(validator);


             s = new statistique();
              s->setWindowTitle("statistique des employes");
              s->choix_bar();
               s->setMinimumSize(800,800);
             s->show();



}

Dialog::~Dialog()
{
    delete ui;
}











void Dialog::on_ajouter_clicked()
{
    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
   QString fonction=ui->le_fonction->currentText();
    QString lieu=ui->le_lieu->text();
    QString date_naissance=ui->la_date->text();
    QString motdepasse=ui->mdp->text();
     Employe E(id,nom,prenom,fonction,lieu,date_naissance,motdepasse);
     bool test=E.ajouter();
     if (test)
     {
         ui->tableView_2->setModel(E.afficher());
                 QMessageBox::information(nullptr, QObject::tr("OK"),
                             QObject::tr("ajout effectué.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);

     }
     else
         QMessageBox::critical(nullptr, QObject::tr("not OK"),
                     QObject::tr("ajout failed.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
}


void Dialog::on_supprimer_clicked()
{
    int id=ui->le_id->text().toInt();
    bool test=E.supprimer(id);
    if (test)
    {
        ui->tableView_2->setModel(E.afficher());
                QMessageBox::information(nullptr, QObject::tr("OK"),
                            QObject::tr("suppression effectué.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not OK"),
                    QObject::tr("suppression failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}



void Dialog::on_modifier_clicked()
{
    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString fonction=ui->le_fonction->currentText();
    QString lieu=ui->le_lieu->text();
    QString date_naissance=ui->la_date->text();
    QString motdepasse=ui->mdp->text();
     Employe E(id,nom,prenom,fonction,lieu,date_naissance,motdepasse);
    bool test=E.modifier();

        if(test){
            ui->tableView_2->setModel(E.afficher());
                    QMessageBox::information(nullptr, QObject::tr("OK"),
                                QObject::tr("modification effectué.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("not OK"),
                        QObject::tr("modification failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog::on_tableView_2_clicked(const QModelIndex &index)
{
    ui->le_id->setText(ui->tableView_2->model()->data(ui->tableView_2->model()->index(index.row(),0)).toString());
        ui->le_nom->setText(ui->tableView_2->model()->data(ui->tableView_2->model()->index(index.row(),1)).toString());
         ui->le_prenom->setText(ui->tableView_2->model()->data(ui->tableView_2->model()->index(index.row(),2)).toString());
       //  ui->le_fonction->setText(ui->tableView_2->model()->data(ui->tableView_2->model()->index(index.row(),3)).toString());
          ui->le_lieu->setText(ui->tableView_2->model()->data(ui->tableView_2->model()->index(index.row(),4)).toString());
            ui->mdp->setText(ui->tableView_2->model()->data(ui->tableView_2->model()->index(index.row(),5)).toString());
}


void Dialog::on_trieid_clicked()
{
  ui->tableView_2->setModel(E.trieid());
}


void Dialog::on_trienom_clicked()
{
     ui->tableView_2->setModel(E.trienom());
}


void Dialog::on_trielieu_clicked()
{
    ui->tableView_2->setModel(E.trielieu());
}





void Dialog::on_chercher_clicked()
{
    QString chercherbox=ui->chercheBox->currentText();

    if (chercherbox == "Nom")
     {
     QString nom_recherche=ui->recherche->text();
     ui->tableView_2->setModel(E.recherche(nom_recherche));
     }
    else if(chercherbox == "prenom")
     {
     QString prenom_recherche=ui->recherche->text();
     ui->tableView_2->setModel(E.recherche(prenom_recherche));
     }
    else if (chercherbox == "fonction")
     {
     QString fonction_recherche=ui->recherche->text();
     ui->tableView_2->setModel(E.recherche(fonction_recherche));
     }
}


void Dialog::on_PDF_2_clicked()
{
    QString ach=ui->le_id->text()+".pdf";
            QPdfWriter pdf("C:/Users/user/Desktop/gestion_employe/generer pdf/pdf.pdf"+ach);

                              QPainter painter(&pdf);
                             int i = 4000;
                                  painter.setPen(Qt::red);
                                  painter.setFont(QFont("Impact", 30));
                                  painter.drawText(2200,1400,"Liste des employes "+ui->le_id->text());
                                  painter.setPen(Qt::black);
                                  painter.setFont(QFont("impact", 50));
                                  painter.drawRect(0,3000,9600,500);
                                  painter.setFont(QFont("impact", 11));
                                  painter.drawText(200,3300,"id");
                                  painter.drawText(1200,3300,"Nom");
                                  painter.drawText(2400,3300,"prenom");
                                  painter.drawText(4200,3300,"fonction");
                                  painter.drawText(5300,3300,"lieu de travail");
                                  painter.drawText(6900,3300,"date de naissance");
                                   painter.drawText(8500,3300,"motdepasse");


                                  QSqlQuery query;
                                  query.prepare("select * from EMPLOYE");
                                  query.exec();
                                  painter.setFont(QFont("Arial",9));
                                  while (query.next())
                                  {
                                      painter.drawText(200,i,query.value(0).toString());
                                      painter.drawText(1200,i,query.value(1).toString());
                                      painter.drawText(2400,i,query.value(2).toString());
                                      painter.drawText(4000,i,query.value(3).toString());
                                      painter.drawText(6000,i,query.value(4).toString());
                                      painter.drawText(7000,i,query.value(5).toString());
                                      painter.drawText(8400,i,query.value(6).toString());
                                      painter.drawText(8400,i,query.value(7).toString());



                                     i = i + 500;
                                  }
                                  int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                                      if (reponse == QMessageBox::Yes)
                                      {
                                          QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/user/Desktop/gestion_employe/generer pdf/pdf.pdf"+ach));

                                          painter.end();
                                      }
                                      if (reponse == QMessageBox::No)
                                      {
                                           painter.end();
                                      }
}

