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
#include<dialog.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int ret=A.connect_arduino(); // lancer la connexion à arduino
        switch(ret){
        case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
            break;
        case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
           break;
        case(-1):qDebug() << "arduino is not available";
        }
         QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
         //le slot update_label suite à la reception du signal readyRead (reception des données).

   //chat
     /*   mSocket=new QTcpSocket(this);
            mSocket->connectToHost("localhost",2000);
            if (mSocket->waitForConnected(3000))
            {
                ui->plainTextEdit->appendPlainText("se connecter correctement");
            }
            else
            {
                ui->plainTextEdit->appendPlainText("connected");
            }
        //    connect(mSocket,SIGNAL(readyRead()),this,SLOT(leer()));
            // fin chat
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
*/




}

MainWindow::~MainWindow()
{
    delete ui;
}




/*void MainWindow::on_seconnecter_clicked()
{ QTabWidget TabWidget;
    connect(ui->tabWidget, SIGNAL(clicked()), this, SLOT(viewData));
    QString username=ui->username2->text();
            QString password = ui->motdepasse2->text();
            if(username == "mohamed" && password == "8888")
            { QMessageBox::information(this, "Login", "Username and password is correct");
           //connect(ui->MainWindow->page_3, SIGNAL(on_connecter_clicked()), this, SLOT(viewData));
            ui->tabWidget->setCurrentIndex(1);
            }
               // hide(); mainwindow = new MainWindow(this); mainwindow->show(); }
                else if(username == "molka" && password == "22222")
            { QMessageBox::information(this, "Login", "Username and password is correct");
               ui->tabWidget->setCurrentIndex(2);
            }
                    //hide(); mainwindow = new MainWindow(this); mainwindow->show(); }
                    else if(username == "khalil" && password == "9999")
                    { QMessageBox::information(this, "Login", "Username and password is correct");
               ui->tabWidget->setCurrentIndex(3);
            }
                        //hide(); mainwindow = new MainWindow(this); mainwindow->show(); }
                        else if(username == "aziz" && password == "107")
                        { QMessageBox::information(this, "Login", "Username and password is correct");
               ui->tabWidget->setCurrentIndex(4);
            }
                            //hide(); mainwindow = new MainWindow(this); mainwindow->show(); }
                            else if(username == "ranim" && password == "545")
                            { QMessageBox::information(this, "Login", "Username and password is correct");
               ui->tabWidget->setCurrentIndex(5);
            }
                                //hide(); mainwindow = new MainWindow(this); mainwindow->show(); }
                                        else { QMessageBox::warning(this,"Login", "Username and password is not correct"); }
}

*/

void MainWindow::on_seconnecter_2_clicked()
{
    QString nom,prenom;
           nom=ui->username->text();
         prenom=ui->motdepasse->text();

           QSqlQuery qry;
           qry.prepare("select * from EMPLOYE where nom='"+nom+"'and prenom='"+prenom+"'");
         if(qry.exec())
                 {
              int i=0;
               while(qry.next())
               {

                  i++;
               }
               if(i==1)
               {
                   QMessageBox::information(nullptr,QObject::tr("login done"),
                                            QObject::tr("login succesfully \n"
                                                        "Click Cancel to exit."),QMessageBox::Cancel);


                   Dialog d;
                 d.setModal(true);
                   d.exec();
                   }


                 else
                    {
                         QMessageBox::critical(nullptr,QObject::tr("login failed"),
                                                 QObject::tr("FAILD TO connected ..........  \n"
                                                              "erreur erreur inaccesible \n"
                                                             "vous n etez pas en registrer dans notre base de donner"
                                                             "Click Cancel to exit."),QMessageBox::Cancel);}

}
}

QString ch="";
 void MainWindow::update_label()
{
     QSqlQuery query;
          QByteArray data="";
        //QByteArray nom ;
          QString nom="" ,prenom="";

         data=A.read_from_arduino();
          qDebug() <<  " data is " <<data;
          ch=ch+data;
          qDebug() <<  " ch is " <<ch;


         if(ch!="" && ch.length()==12)
            {
             if(ch==" F3 BD BB 97")
              {
              QString id="8888";
              query.prepare("SELECT* FROM EMPLOYE WHERE id='"+id+"'  ");
              qDebug() << query.exec();
              while (query.next())
              {
              nom =query.value(1).toString();
              prenom=query.value(2).toString();

              }
              qDebug() << nom;
              qDebug() << prenom;

              ui->username->setText(nom);
              ui->motdepasse->setText(prenom);

              QString message ="Bienvenue "+ nom;
              QByteArray br = message.toUtf8();
              A.write_to_arduino(br);
              }


             else if(ch==" A1 5B D2 1B")
             {
             QString id="545";
             query.prepare("SELECT* FROM EMPLOYE WHERE id='"+id+"'  ");
             qDebug() << query.exec();
             while (query.next())
             {
             nom =query.value(1).toString();
             prenom=query.value(2).toString();

             }
             qDebug() << nom;
             qDebug() << prenom;

             ui->username->setText(nom);
             ui->motdepasse->setText(prenom);

             QString message ="Bienvenue "+ nom;
             QByteArray br = message.toUtf8();
             A.write_to_arduino(br);
             }

             else
             {
                 QString message ="donne inaccessible";
                 QByteArray br = message.toUtf8();
                 A.write_to_arduino(br);
                 QMessageBox::critical(nullptr,QObject::tr("login failed"),
                                         QObject::tr("FAILED TO connected ..........  \n"
                                                      "acces denied \n"

                                                     "Click Cancel to exit."),QMessageBox::Cancel);
             }

            }

         if(ch.length()==12)
          {
          ch="";
          }
}


  /*void MainWindow::on_Send_clicked()
{
  QString from = ui->le_from->text();
          QString to = ui->le_to->text();
          QString subject = ui->le_subject->text();
          QString password =ui->le_password->text();
          QString textemail = ui->textedit->toPlainText();

         Smtp* smtp = new Smtp(from, password, "smtp.gmail.com",465);
          connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


             smtp->sendMail(from, to, subject, textemail);
   }*/
 // void MainWindow::mailSent(QString nettoyer)
  // {

      // if(nettoyer == "Message sent")
         //  QMessageBox::information( nullptr, tr( "email" ), tr( "Message sent.\n\n" ) );
      // ui->le_to->clear();
     //  ui->le_from->clear();
      // ui->le_subject->clear();
      // ui->textedit->clear();
     //  ui->le_password->clear();
//}

/*
void MainWindow::on_pushButton_clicked()
{
    mSocket->write(ui->lineEdit->text().toLatin1().data(),ui->lineEdit->text().size());

        ui->plainTextEdit_2->appendPlainText(ui->lineEdit->text());

        ui->lineEdit->clear();
}

void MainWindow::on_pushButton_2_clicked()
{
    mSocket->write(ui->lineEdit_2->text().toLatin1().data(),ui->lineEdit_2->text().size());

        ui->plainTextEdit->appendPlainText(ui->lineEdit_2->text());

        ui->lineEdit_2->clear();
}
*/
