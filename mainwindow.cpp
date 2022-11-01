#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "equipement.h"
#include <QString>
#include <QPrinter>
#include <QPainter>
#include <QMessageBox>
#include <string>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(Equipement().afficher());

    ui->tableView_3->setModel(Equipement().afficher_r());
    QChartView *chartview = new QChartView(Equipement().Statistique(),ui->widget);
    chartview->resize(500,400);
    chartview->setRenderHint(QPainter::Antialiasing);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString id=ui->id_ajout->text();
    QString nom=ui->nom_ajout->text();
    QString etat=ui->etat_ajout->currentText();
    QString date=ui->Date_ajout->text();
    Equipement e(id,nom,etat,date);
    int test1=0,test2=0;
    int i=0;
    bool test=false;
    string ch=id.toStdString();
    while ((test1==0)&&(i<id.length()))
    {if (!isdigit(ch[i]))
    {
        test1=1;
    }
    i++;}
    i=0;
    string ch1=nom.toStdString();
    while ((test2==0)&&(i<nom.length()))
    {if (isdigit(ch1[i]))
    {
        test2=1;
    }
    i++;}
    if ((test1==0)&&(test2==0))
    {test = e.Ajouter();}
    if (test)
    {
ui->tableView->setModel(Equipement().afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout done"), QMessageBox::Cancel);



    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("OK"),
                                 QObject::tr(" Ajout impossible"), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QString id=ui->id_edit->text();
    QString nom=ui->nom_edit->text();
    QString etat=ui->etat_edit->currentText();
    QString date=ui->date_edit->text();
    Equipement e(id,nom,etat,date);
    string ch=id.toStdString();
    int test1=0,test2=0;
    bool test=false;
    int i=0;
    while ((test1==0)&&(i<id.length()))
    {if (!isdigit(ch[i]))
    {
        test1=1;
    }
    i++;}
    i=0;
    string ch1=nom.toStdString();
    while ((test2==0)&&(i<nom.length()))
    {if (isdigit(ch1[i]))
    {
        test2=1;
    }
    i++;}
    if ((test1==0)&&(test2==0))
     test = e.Modifier(id);
    if (test)
    {
ui->tableView->setModel(Equipement().afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Modification done"), QMessageBox::Cancel);



    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("OK"),
                                 QObject::tr(" Modification impossible"), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    QString id=ui->id_supp->text();
   Equipement e;
    e.id=id;
    bool test = e.Suppression(id);
    if (test)
    {
ui->tableView->setModel(Equipement().afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Suppression done"), QMessageBox::Cancel);



    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("OK"),
                                 QObject::tr(" Suppression impossible"), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    QString x=ui->recherche->text();
    ui->tableView->setModel(Equipement().rechercher(x));

}

void MainWindow::on_pushButton_5_clicked()
{
    ui->tableView->setModel(Equipement().afficher());
}

void MainWindow::on_pushButton_6_clicked()
{
     ui->tableView->setModel(Equipement().TrieID());
}

void MainWindow::on_pushButton_7_clicked()
{
     ui->tableView->setModel(Equipement().TrieNom());
}

void MainWindow::on_pushButton_8_clicked()
{
     ui->tableView->setModel(Equipement().TrieDate());
}

void MainWindow::on_pushButton_9_clicked()
{
    Equipement().Excel();
}

void MainWindow::on_pushButton_10_clicked()
{

    ui->tableView_2->setModel(Equipement().Mise_a_jour());
    ui->tableView->setModel(Equipement().afficher());
    ui->tableView_3->setModel(Equipement().afficher_r());
}

void MainWindow::on_pushButton_11_clicked()
{
    QString x=ui->rec->text();
    bool test= Equipement().reparer(x);
    ui->tableView_3->setModel(Equipement().afficher_r());
    ui->tableView->setModel(Equipement().afficher());
}

void MainWindow::on_pushButton_12_clicked()
{
    PrintWidget(ui->widget);

}
void MainWindow::PrintWidget(QWidget* widget) {

    QString pdf=ui->pdf->text();
    QPixmap pix(widget->size());
    QPainter painter(&pix);
    widget->render(&painter);
    painter.end();
    QPrinter printer(QPrinter::HighResolution);
    printer.setOrientation(QPrinter::Landscape);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(pdf); // will be in build folder

    painter.begin(&printer);
    double xscale = printer.pageRect().width() / double(pix.width());
    double yscale = printer.pageRect().height() / double(pix.height());
    double scale = qMin(xscale, yscale);
    painter.translate(printer.paperRect().x() + printer.pageRect().width() / 2,
                      printer.paperRect().y() + printer.pageRect().height() / 2);
    painter.scale(scale, scale);
    painter.translate(-widget->width() / 2, -widget->height() / 2);
    painter.drawPixmap(0, 0, pix);
    painter.end();











}
