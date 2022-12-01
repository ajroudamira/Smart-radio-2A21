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
#include "exportexcel.h"
#include <QPieSeries>
#include <QtCharts>
#include<qdesktopservices.h>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QPieSlice>
#include <QPieSeries>
#include <QChartView>
#include <qrcodegen.hpp>
#include "scenario1arduino.h"


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
     int ret=a.connect_arduino();
                           switch(ret)
                           {
                           case (0): qDebug() << "arduino is available and connected to : " << a.getarduino_port_name();
                           break;
                           case (1) :qDebug () << "arduino is available but not connected to :" << a.getarduino_port_name ();
                           break;
                           case (-1): qDebug() << "arduino is not available";

                           }

                          QObject:: connect (a.getserial(),SIGNAL (readyRead()), this, SLOT (update())); // permet de lancer //le slot update label suite à la reception du signal readyRead (reception des données).

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

      QString text =" details des sponsors \n :"+ ui->tabsponsor->model()->data(ui->tabsponsor->model()->index(ui->tabsponsor->currentIndex().row(),0)).toString()
                   +" \n"+ui->tabsponsor->model()->data(ui->tabsponsor->model()->index(ui->tabsponsor->currentIndex().row(),1)).toString()
                   +"\n "+ui->tabsponsor->model()->data(ui->tabsponsor->model()->index(ui->tabsponsor->currentIndex().row(),2)).toString()
                   +"\n "+ui->tabsponsor->model()->data(ui->tabsponsor->model()->index(ui->tabsponsor->currentIndex().row(),3)).toString()
                   +" \n"+ui->tabsponsor->model()->data(ui->tabsponsor->model()->index(ui->tabsponsor->currentIndex().row(),4)).toString()
                   +" \n"+ui->tabsponsor->model()->data(ui->tabsponsor->model()->index(ui->tabsponsor->currentIndex().row(),5)).toString();
           //text="user data";
           using namespace qrcodegen;
             // Create the QR Code object
             QrCode qr = QrCode::encodeText( text.toUtf8().data(), QrCode::Ecc::MEDIUM );
             qint32 sz = qr.getSize();
             QImage im(sz,sz, QImage::Format_RGB32);
               QRgb black = qRgb(  0,  0,  0);
               QRgb white = qRgb(255,255,255);
             for (int y = 0; y < sz; y++)
               for (int x = 0; x < sz; x++)
                 im.setPixel(x,y,qr.getModule(x, y) ? black : white );
             ui->qrcode_2->setPixmap( QPixmap::fromImage(im.scaled(150,150,Qt::KeepAspectRatio,Qt::FastTransformation),Qt::MonoOnly) );






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
    Li->setWindowTitle("Localisation Sans Wifi");
    Li->show();
}

void MainWindow::on_pb_geo_2_clicked()
{
    l=new locawifi(this);
    l->setWindowTitle("Localisation En Ligne");
    l->show();
}





void MainWindow::on_pb_stat_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
           model->setQuery("select * from sponsor where montant >= 2000");
           float dispo1=model->rowCount();

           model->setQuery("select * from sponsor where montant <2000");
           float dispo=model->rowCount();

           float total=dispo1+dispo;
               QString a=QString("Les Contrat Premium  " +QString::number((dispo1*100)/total,'f',2)+"%" );
               QString b=QString("Les Contrats Simples  "+QString::number((dispo*100)/total,'f',2)+"%" );
               QPieSeries *series = new QPieSeries();
               series->append(a,dispo1);
               series->append(b,dispo);
           if (dispo1!=0)
           {QPieSlice *slice = series->slices().at(0);
               slice->setLabelVisible();
               slice->setPen(QPen());}
           if ( dispo!=0)
           {
               QPieSlice *slice1 = series->slices().at(1);
               slice1->setLabelVisible();
           }

           QChart *chart = new QChart();
           chart->addSeries(series);
           chart->setTitle("Les Gains De Productivité ");
           QChartView *chartView = new QChartView(chart);
           chartView->setRenderHint(QPainter::Antialiasing);
           chartView->resize(1000,500);
           chartView->show();
}

/*void MainWindow::update_label(){
    d=a.read_from_arduino();
    QString s="SELECT * FROM ARDUINO WHERE PASSWORD='"+d+"'";
    QSqlQuery query;

    query.prepare(s);
    query.exec();
      while (query.next()){};
      if(query.value(1)==NULL)
{a.write_to_arduino("MOT DE PASSE INCORRECTE");
      }
      else{
          QByteArray s1="BIENVENUE "+query.value(0).toByteArray();
          a.write_to_arduino(s1);
      }
}*/
/*void MainWindow:: ChercherFromArduino()

 {

     d = a.read_from_arduino();
     qDebug() << d;
     if (d!=" ")
     {
         QSqlQuery *query=new QSqlQuery;
         query->prepare("select * FROM SPONSOR WHERE MATRI LIKE '%"+d+"%';");
         if(query->exec()){
           ui->recher_edit->setText(d);
           S.recherche(ui->tabsponsor,d);
           if (ui->recher_edit->text().isEmpty())
           {
               ui->tabsponsor->setModel(S.afficher());
           }
         }else{
qDebug() << d;
         }

     }
}*/
 QByteArray ch="";

void MainWindow::update()
{

    QByteArray don="";

        don=a.read_from_arduino();
        QByteArray d="";
        qDebug() <<"dd"<<ch<<*don;

        if(*don=='1')
            ch=ch+'1';
        else if(*don=='2')
            ch=ch+'2';
        else if(*don=='3')
            ch=ch+'3';
        else if(*don=='4')
            ch=ch+'4';
        else if(*don=='5')
            ch=ch+'5';
        else if(*don=='6')
            ch=ch+'6';
        else if(*don=='7')
            ch=ch+'7';
        else if(*don=='8')
            ch=ch+'8';
        else if(*don=='9')
            ch=ch+'9';
        else if(*don=='0')
            ch=ch+'0';

int s=0;
        QByteArray am="WRONG";
QString matri;
        if(don=="*")
        {

            QSqlQuery query;
            QString test=QString(ch);
            int count=0;
            query.prepare("SELECT * FROM sponsor WHERE matri= ?");
            query.addBindValue(matri);
            if(query.exec() )
            {
                while (query.next())
                {
                    count ++;
                }
                if(count==1)
                {
                    //msgBox.setText("numero deja existe");
                    //msgBox.exec();
                    s=1;
                }

            }
            else
                s=-1;










        if(s)
        {
            qDebug() <<"testing"<<test;
            QString nom,prenom;
            query.prepare("select * from sponsor where matri='"+test+"' ");
            if(query.exec())
            {
                while(query.next())
                {
                     nom=(query.value(1).toString());

                }
            query.exec();
            QString tt=nom+"  ";
            QByteArray z=tt.toUtf8();
            a.write_to_arduino(z);
        }}
        else
            {
        a.write_to_arduino("WRONG\n");
            }

        ch="";


    }

}
