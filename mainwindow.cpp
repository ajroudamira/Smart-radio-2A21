#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include "invite.h"
#include "QIntValidator"
#include "QMainWindow"
#include "QObject"
#include <QPainter>
#include<QPdfWriter>
#include<QDesktopServices>
#include<QUrl>
#include<QWidget>
#include<QString>
#include <QPagedPaintDevice>
#include <QtCore>
#include<QtGui>
#include <fstream>
#include "arduino.h"
#include "qrcodegen.hpp"
using namespace qrcodegen;
MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  A.connect_arduino(); //pour connecter le pc à arduino
  ui->le_CIN->setValidator(new QIntValidator(100, 99999999, this));//controle de saisie:lezem num wmayfoutich 8 chiffres
  ui->le_Num_tel->setValidator(new QIntValidator(100, 99999999, this));//c'comme comme
  ui->tab_invite->setModel(I.afficher());
  QRegularExpression rx("^[A-Za-z]+$");
  QValidator *validator = new QRegularExpressionValidator(rx, this);
  ui->le_nom->setMaxLength(15);
  ui->le_prenom->setMaxLength(15);
  ui->le_nom->setValidator(validator);//controle de saisie aal nom w prenom lezm ykoun des lettres maj ou min diff de chiffres w symboles max 15
  ui->le_prenom->setValidator(validator);
  ui->letat_civil->addItem("célibataire");//les etats mtaa etat_civil
  ui->letat_civil->addItem("marié(e)");
  ui->letat_civil->addItem("divorcé(e)");
  ui->tab_invite->setModel(I.afficher());
  QBarSet *set0 = new QBarSet("Prog 1"); //les echelles mte3i
  QBarSet *set1 = new QBarSet("Prog 2");
  QBarSet *set2 = new QBarSet("Prog 3");
  QBarSet *set3 = new QBarSet("Prog 4");
  QBarSet *set4 = new QBarSet("Prog 5");
  *set0<<30<<40<<10<<20<<10<<60;
  *set1<<10<<30<<42<<15<<81<<75;
  *set2<<80<<100<<70<<13<<60<<20;
  *set3<<30<<10<<80<<70<<60<<45;
  *set4<<100<<40<<70<<30<<16<<42;
  QBarSeries *series =new QBarSeries();//bech naaml chart jdida//QBarSeries class presents a series of data as vertical bars grouped by category.
  series->append(set0);
  series->append(set1);
  series->append(set2);//Adds a new bar set with label and values to the index
  series->append(set3);
  series->append(set4);
  QChart *chart =new QChart();
  chart->addSeries(series);
  chart->setTitle("Statistiques des invités"); //titre mtaa chart ...
  chart->setAnimationOptions(QChart::SeriesAnimations);
  QStringList categories; //categories 3ibara aal axe des abscisses
  categories <<"Sep-Nov"<<"Dec-Fev"<<"Mars-May"<<"Juin-Aou"; //
  QBarCategoryAxis *axis =new QBarCategoryAxis();//ajouter des données
  axis->append(categories);
  chart->createDefaultAxes(); //creation mtaa l'axe des ordonnees
  chart->setAxisX(axis,series);
  QChartView *chartView = new QChartView (chart);
  chartView->setParent(ui->horizentalframe); //bech najem naccedi liha hedheka aalh aayettelha mel ui
  chart->legend()->setVisible(true);
  chart->legend()->setAlignment(Qt::AlignBottom);
  chartView->setRenderHint(QPainter::Antialiasing); //les echelles ywalliw louta


  QPieSeries *series1 = new QPieSeries();
  series1->setHoleSize(0.35);
  series1->append("Prog1", 56.4);
  QPieSlice *slice = series1->append("Prog2",30);
  slice->setExploded();
  slice->setLabelVisible();
  series1->append("Prog3", 6); //kol partie 9addeh tekhou % 100
  series1->append("Prog4", 4);
  series1->append("Prog5", 3.6);
  QChart * chart1 = new QChart();
  chart1->addSeries(series1);
  chart1->setAnimationOptions(QChart::SeriesAnimations);
  chart1->setTitle("Graphe des invités");//titre
  chart1->setTheme(QChart::ChartThemeBlueCerulean);//naamel theme
  QChartView *chartview = new QChartView(chart1);
  chartview->setRenderHint(QPainter::Antialiasing);//les echelles ellouta
  chartview->setParent(ui->Donutchart);//bech najem naccedi liha hedheka aalh aayettelha mel ui
  chart1->legend()->setVisible(true);
  chart1->legend()->setAlignment(Qt::AlignBottom);
  chartView->setRenderHint(QPainter::Antialiasing);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
  int check=0;
  bool test1=false;
  int CIN=ui->le_CIN->text().toInt();
  int Num_tel=ui->le_Num_tel->text().toInt();
  QString nom=ui->le_nom->text();
  QString prenom=ui->le_prenom->text();
  QString date_de_naissance=ui->le_date_de_naissance->text();
  QString etat_civil=ui->letat_civil->currentText();
  QString adresse=ui->ladresse->text();
  QString date_event=ui->date_event->text();
  invite I(CIN,Num_tel,nom,prenom,date_de_naissance,etat_civil,adresse,date_event);
  string ch=date_de_naissance.toStdString();
qDebug() << ch[2];
qDebug() << ch[5];
  if ((ch[2]=='/')&&(ch[5]=='/'))
          {check=1;}
string ad="@gmail.com";
string ch2=adresse.toStdString();
string ch3=ch2.substr(ch2.length()-10,10);

  if((check==1)&&(ch3==ad))
  test1=I.Ajouter();
  QMessageBox msgBox;
  if(test1)
{
  msgBox.setText("Ajout avec succes.");
  ui->tab_invite->setModel(I.afficher());
}
  else
  msgBox.setText("Echec d'ajout");
  msgBox.exec();
}

void MainWindow::on_pb_supprimer_clicked()
{
invite I1;I1.setCIN(ui->le_id_supp->text().toInt());
bool test=I1.supprimer(I1.getCIN());
QMessageBox msgBox;
if(test)
{
msgBox.setText("Suppression avec succes.");
ui->tab_invite->setModel(I.afficher());
}
else
msgBox.setText("Echec de Suppression");
msgBox.exec();
}
void MainWindow::on_pb_modifier_clicked()
{
    bool test=false;
    int check =0;
    int CIN=ui->le_CIN->text().toInt();
    int Num_tel=ui->le_Num_tel->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString date_de_naissance=ui->le_date_de_naissance->text();
    QString etat_civil=ui->letat_civil->currentText();
    QString adresse=ui->ladresse->text();
    QString date_event=ui->date_event->text();
    invite I(CIN,Num_tel,nom,prenom,date_de_naissance,etat_civil,adresse,date_event);
    string ch = date_de_naissance.toStdString();
    if ((ch[2]=='/')&&(ch[5]=='/'))
            {check=1;}

    if(check==1)
    test=I.modifier();
    QMessageBox msgBox;
    if(test)
    {
        ui->tab_invite->setModel(I.afficher());
        QMessageBox::information(nullptr, QObject::tr(" OK"),
        QObject::tr("Ajout Effectué.\n"
        "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    msgBox.setText("Echec de modification");
    msgBox.exec();

}
void MainWindow::on_pb_pdf_clicked()
{
       QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),"/home",QFileDialog::ShowDirsOnly|QFileDialog::DontResolveSymlinks);
                qDebug()<<dir;
                QPdfWriter pdf(dir+"/PdfList.pdf");
                                       QPainter painter(&pdf);
                                      int i = 4000;

                                      painter.drawPixmap(QRect(100,100,2000,2000),QPixmap("C:/Users/Admin/Desktop/logo.png"));
                                          //painter.drawText(900,650,"Tiny hues");
                                          //painter.drawPixmap(QRect(7600,100,2100,2700),QPixmap("C:/Users/Admin/Desktop/logo.png"));
                                           painter.setPen(Qt::red);
                                           painter.setFont(QFont("Time New Roman", 25));
                                           painter.drawText(3000,1450,"Liste Des Invites");
                                           painter.setPen(Qt::black);
                                           painter.setFont(QFont("Time New Roman", 15));
                                           painter.drawRect(100,100,9400,2500);
                                           painter.drawRect(100,3000,9400,500);
                                           painter.setFont(QFont("Time New Roman", 10));
                                           painter.drawText(300,3300,"CIN");
                                           painter.drawText(3000,3300,"Nom");
                                           painter.drawText(5600,3300,"Prenom");
                                           painter.drawText(8300,3300,"Adresse");
                                           painter.drawRect(100,3000,9400,10700);
                                           QTextDocument previewDoc;
                                           QString pdflist = QDate::currentDate().toString("'data_'MM_dd_yyyy'.txt'");
                                           QTextCursor cursor(&previewDoc);

                                           QSqlQuery query;
                                           query.prepare("select * from invite");
                                           query.exec();
                                           while (query.next())
                                           {
                                               painter.drawText(300,i,query.value(0).toString());
                                               painter.drawText(3000,i,query.value(2).toString());
                                               painter.drawText(5600,i,query.value(3).toString());
                                               painter.drawText(8300,i,query.value(6).toString());


                                              i = i +500;
                                           }
                                           int reponse = QMessageBox::question(this, "Générer PDF", " PDF Enregistré ! Voulez Vous Affichez Le PDF ?",
                                                                               QMessageBox::Yes|QMessageBox::No);
                                               if (reponse == QMessageBox::Yes)
                                               {
                                                   QDesktopServices::openUrl(QUrl::fromLocalFile(dir+"/PdfList.pdf"));

                                                   painter.end();
                                               }
                                               else
                                               {
                                                    painter.end();
      }
}
/*void MainWindow::on_pb_recherche_cin_clicked()
{
}*/
void MainWindow::on_pb_recherche_clicked()
{
    QString x=ui->rech->text();
    ui->tab_invite->setModel(invite().rechercherii(x));
}
void MainWindow::on_pb_tri_cin_clicked()
{
    ui->tab_invite->setModel(I.triCIN());
}
void MainWindow::on_pb_tri_adresse_clicked()
{
ui->tab_invite->setModel(I.triAdresse());
}

void MainWindow::on_pb_qr_code_clicked()
{
    QString numc= ui->qr->text();

            QSqlQuery qry;

            qry.prepare("select * from invite where CIN=:numc");

            qry.bindValue(":numc",numc);

            qry.exec();

           // QDate date_signification;

            QString nom,prenom,adresse,cin;

            while(qry.next()){

                nom=qry.value(2).toString();

               prenom=qry.value(3).toString();

               adresse=qry.value(6).toString();

               // cin==qry.value(4).toString();

            }

           // numcs=QString::number(numc);

            numc="numc: "+nom+" nom: "+prenom+" prenom: "+adresse+"adresse: ";

            QrCode qr = QrCode::encodeText(numc.toUtf8().constData(), QrCode::Ecc::HIGH);





            QImage im(qr.getSize(),qr.getSize(), QImage::Format_RGB888);

            // NOTE: For performance reasons my implementation only draws the foreground parts in supplied color.

            // It expects background to be prepared already (in white or whatever is preferred).

            for (int y = 0; y < qr.getSize(); y++) {

                for (int x = 0; x < qr.getSize(); x++) {

                    int color = qr.getModule(x, y);  // 0 for white, 1 for black



                    // You need to modify this part

                    if(color==0)

                        im.setPixel(x, y,qRgb(254, 254, 254));

                    else

                        im.setPixel(x, y,qRgb(0, 0, 0));

                }

            }

            im=im.scaled(200,200);

    ui->qrlabel->setPixmap(QPixmap::fromImage(im));
}

void MainWindow::on_pb_historique_clicked()
{
    QSqlQuery q,q1;
    fstream fichier;
    fichier.open("D:/fichier.txt",ios::out);//lowel howa el fichier theni droit d'accès
    if (fichier)
    {
        q.prepare("Select * from invite where date_event < sysdate");
        q.exec();
        while (q.next())
        {

            fichier << q.value(0).toString().toStdString() << "|" << q.value(1).toString().toStdString()<< "|" << "|" << q.value(2).toString().toStdString()<< "|" << "|" << q.value(3).toString().toStdString()<< "|" << "|" << q.value(4).toString().toStdString()<< endl;
        }
        q1.prepare("DELETE FROM INVITE WHERE DATE_EVENT < sysdate");
        q1.exec();
        ui->tab_invite->setModel(I.afficher());
    }
   else
        qDebug()<<"Impossible d'ouvrir le fichier";
}

void MainWindow::on_pb_arret_clicked()
{
    A.write_to_arduino("1");
    QSqlQuery q;
    int x=rand()%1000;
    q.prepare("INSERT INTO POINTAGE (id,datee) values (:id,sysdate)");
    q.bindValue(":id",x);
    q.exec();
}
