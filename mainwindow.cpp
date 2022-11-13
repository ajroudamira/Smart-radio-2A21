#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sponsor.h>
#include "dialog.h"
#include <QIntValidator>
#include <QMessageBox>
#include<QObject>
#include<QString>
#include<QSqlQuery>
#include <QtDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QPrinter>
#include <QPrintDialog>
#include <QPagedPaintDevice>
#include<QPixmap>
#include "localisation.h"
#include "ui_localisation.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_matri->setValidator (new QIntValidator(0, 99999, this));
    ui->ds_montant->setValidator (new QIntValidator(700, 999999, this));
    ui->le_nom->setMaxLength(15);
     ui->te_duree->setMaxLength(2);
    ui->tabsponsor->setModel(S.afficher());
    QRegularExpression rx("^[A-Za-z]+$");
     QValidator *validator = new QRegularExpressionValidator(rx, this);
     ui->le_nom->setValidator(validator);
     ui->le_matrisupp->setValidator (new QIntValidator(0, 99999, this));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int matri=ui->le_matri->text().toInt();
     QString nom=ui->le_nom->text();
     QString ad=ui->le_ad->currentText();
     QString email=ui->le_email->text();
     int montant=ui->ds_montant->text().toInt();
     QString duree=ui->te_duree->text();
     duree=duree+"s";
      Sponsor S(matri,montant,duree,nom,ad,email);
bool test=S.ajouter();

if(S.verifieremail(email)==0 )
{test=false;
    QMessageBox::critical(nullptr, QObject::tr("not ok"),
                       QObject::tr("ad.email incorrecte.\n"

                                   "Click Cancel to exit."), QMessageBox::Cancel);}
 if (montant<700 )
       {test=false;
 QMessageBox::critical(nullptr, QObject::tr("not ok"),
             QObject::tr("montant inferieur a 700.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);}
         if(test)
 {    ui->tabsponsor->setModel(S.afficher());
     QMessageBox::information(nullptr, QObject::tr("ok"),
                                    QObject::tr("ajout effectue.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);

}
 else
     QMessageBox::critical(nullptr, QObject::tr("not ok"),
                 QObject::tr("ajout non effectue.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_tabsponsor_clicked(const QModelIndex &index)
{
    ui->le_matri->setText(ui->tabsponsor->model()->data(ui->tabsponsor->model()->index(index.row(),0)).toString());
    ui->le_nom->setText(ui->tabsponsor->model()->data(ui->tabsponsor->model()->index(index.row(),1)).toString());
    ui->le_ad->setCurrentText(ui->tabsponsor->model()->data(ui->tabsponsor->model()->index(index.row(),2)).toString());
     ui->le_email->setText(ui->tabsponsor->model()->data(ui->tabsponsor->model()->index(index.row(),3)).toString());
     ui->ds_montant->setText(ui->tabsponsor->model()->data(ui->tabsponsor->model()->index(index.row(),4)).toString());
      ui->te_duree->setText(ui->tabsponsor->model()->data(ui->tabsponsor->model()->index(index.row(),5)).toString());
}
void MainWindow::on_pb_supp_clicked()
{
    int matri=ui->le_matrisupp->text().toInt();
     bool test=S.supprimer(matri);

     if (test)
     {
         ui->tabsponsor->setModel(S.afficher());
     QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("suppression effectué.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
     }
     else
     QMessageBox::critical(nullptr, QObject::tr("not OK"),
                         QObject::tr("suppression failed.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

}









void MainWindow::on_trienom_clicked()
{
  ui->tabsponsor->setModel(S.trienom());
}

void MainWindow::on_triead_clicked()
{
    ui->tabsponsor->setModel(S.triead());
}

void MainWindow::on_triemontant_clicked()
{
     ui->tabsponsor->setModel(S.triemontant());
}

void MainWindow::on_pb_modif_clicked()
{
    int matri=ui->le_matri->text().toInt();
       QString nom=ui->le_nom->text();
       QString ad=ui->le_ad->currentText();
       QString email=ui->le_email->text();
       int montant=ui->ds_montant->text().toInt();
       QString duree=ui->te_duree->text();
       duree=duree+"s";
       Sponsor S(matri,montant,duree,nom,ad,email);
       bool test=S.modifier();

           if(test){
               ui->tabsponsor->setModel(S.afficher());
                       QMessageBox::information(nullptr, QObject::tr("OK"),
                                   QObject::tr("modification effectué.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);

           }
           else
               QMessageBox::critical(nullptr, QObject::tr("not OK"),
                           QObject::tr("modification failed.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_recher_edit_textChanged(const QString &arg1)
{
    QString rech = ui->recher_edit->text();
                 S.recherche(ui->tabsponsor,rech);
                 if (ui->recher_edit->text().isEmpty())
                 {
                     ui->tabsponsor->setModel(S.afficher());
                 }

}

void MainWindow::on_pb_pdf_clicked()
{
S.telechargerPDF();

        QMessageBox::information(nullptr,QObject::tr("OK"),
                   QObject::tr("Téléchargement terminé"), QMessageBox::Cancel);



}

void MainWindow::on_pb_mail_clicked()
{//hide();
 Di = new dialog(this);
 Di->show();
}


void MainWindow::on_checkBoxnom_clicked()
{
  ui->tabsponsor->setModel(S.trienom());
}

void MainWindow::on_checkBoxmontant_clicked()
{
    ui->tabsponsor->setModel(S.triemontant());
}

void MainWindow::on_checkBoxad_clicked()
{
    ui->tabsponsor->setModel(S.triead());
}

void MainWindow::on_pb_geo_clicked()
{
    Li=new Localisation(this);
    Li->show();
}

void MainWindow::on_pb_geo_2_clicked()
{
    l=new locawifi(this);
    l->show();
}

void MainWindow::on_pb_calend_clicked()
{   ca=new calendrier(this);
    ca->show();

}
