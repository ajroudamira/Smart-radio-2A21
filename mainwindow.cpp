#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "crud.h"
#include <QMessageBox>
#include <QSqlQuery>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableau->setModel(c.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
int sem1=ui->sem1->text().toInt();
int sem2=ui->sem2->text().toInt();
int sem3=ui->sem3->text().toInt();
int sem4=ui->sem4->text().toInt();
int sem5=ui->sem5->text().toInt();
int sem6=ui->sem6->text().toInt();
int sem7=ui->sem7->text().toInt();
int sem8=ui->sem8->text().toInt();
QString jourdiff=ui->jourdiff->text();
QString name=ui->le_nom->text();
QString id=ui->le_nom_2->text();
QString difname=ui->le_nom_3->text();
CRUD C(name,id,difname,jourdiff,sem1,sem2,sem3,sem4,sem5,sem6,sem7,sem8);
bool test=C.ajouter();
if(!test){
    ui->tableau->setModel(c.afficher());

    QMessageBox::information(nullptr, QObject::tr(" OK"),
                QObject::tr("Ajout Effectué.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else{
    QMessageBox::critical(nullptr, QObject::tr(" OK"),
                QObject::tr("Ajout Non Effectué.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}

}



void MainWindow::on_supprimer_clicked()
{       QString id=ui->Supression->text();
bool test=c.supprimer(id);
if(test){
    ui->tableau->setModel(c.afficher());
    QMessageBox::information(nullptr, QObject::tr(" OK"),
                QObject::tr("Suppression Effectué.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}
else
    QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                QObject::tr("Suppression Non Effectué.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_tableau_activated(const QModelIndex &index)
{
    QString id=ui->tableau->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("select * from PROGRAMME where ID='"+id+"'");
    if(query.exec()){
        while(query.next())
        {
            ui->sem1->setText(query.value(4).toString());
            ui->sem2->setText(query.value(5).toString());
            ui->sem3->setText(query.value(6).toString());
            ui->sem4->setText(query.value(7).toString());
            ui->sem5->setText(query.value(8).toString());
            ui->sem6->setText(query.value(9).toString());
            ui->sem7->setText(query.value(10).toString());
            ui->sem8->setText(query.value(11).toString());
            ui->jourdiff->setText(query.value(3).toString());
            ui->le_nom->  setText(query.value(0).toString());
            ui->le_nom_2->setText(query.value(1).toString());
            ui->le_nom_3->setText(query.value(2).toString());
        }

    }

}

void MainWindow::on_pb_modif_clicked()
{int sem1=ui->sem1->text().toInt();
int sem2=ui->sem2->text().toInt();
int sem3=ui->sem3->text().toInt();
int sem4=ui->sem4->text().toInt();
int sem5=ui->sem5->text().toInt();
int sem6=ui->sem6->text().toInt();
int sem7=ui->sem7->text().toInt();
int sem8=ui->sem8->text().toInt();
QString jourdiff=ui->jourdiff->text();
QString name=ui->le_nom->text();
QString id=ui->le_nom_2->text();
QString difname=ui->le_nom_3->text();
CRUD C(name,id,difname,jourdiff,sem1,sem2,sem3,sem4,sem5,sem6,sem7,sem8);
bool test=C.modifier();

    if(test){
        ui->tableau->setModel(c.afficher());

        QMessageBox::information(nullptr, QObject::tr(" OK"),
                    QObject::tr("Modification Effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else{
        QMessageBox::critical(nullptr, QObject::tr(" OK"),
                    QObject::tr("Modification Non Effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    }

}
