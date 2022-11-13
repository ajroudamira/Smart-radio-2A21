#include "localisation.h"
#include "ui_localisation.h"
#include "sponsor.h"
#include <QPrinter>
#include <QPrintDialog>
#include <QPagedPaintDevice>
#include<QPixmap>
#include<QString>
#include<QSqlQuery>
#include<QPainter>
#include <QLineEdit>
#include <QLabel>
#include <QMessageBox>
#include <QSqlDatabase>
#include<QSqlQuery>

Localisation::Localisation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Localisation)
{
    ui->setupUi(this);
}

Localisation::~Localisation()
{
    delete ui;
}

void Localisation::on_pb_maps_clicked()
{
    int matri = ui->le_dest->text().toInt();

             QString id_string= QString::number(matri);
             QSqlQuery query;
             query.prepare("select * from sponsor where matri='"+id_string+"'");

                    if(query.exec()){

                        while(query.next())
                        { ui->textEdit->setText(query.value(2).toString());


                            if  (ui->textEdit->toPlainText()== "Kairouan")
                                        {ui->label_pic->clear();

                                  QPixmap pix("C:/Users/Jammoussi Yasmine/Documents/untitled/kairouan.png");
                                 int w = ui->label_pic->width();
                                 int h = ui->label_pic->height();
                                  ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
                                         }
                            else if(ui->textEdit->toPlainText()=="Sousse")
                              { ui->label_pic->clear();
                                  QPixmap pix("C:/Users/Jammoussi Yasmine/Documents/untitled/sousse.png");
                                  int w = ui->label_pic->width();
                                  int h = ui->label_pic->height();
                                   ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


                              }
                              else if(ui->textEdit->toPlainText()=="Bizerte")
                                 {ui->label_pic->clear();
                                     QPixmap pix("C:/Users/Jammoussi Yasmine/Documents/untitled/bizerte.png");
                                     int w = ui->label_pic->width();
                                     int h = ui->label_pic->height();
                                      ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

                                 }
                              else if(ui->textEdit->toPlainText()=="Nabeul")
                                 {ui->label_pic->clear();
                                     QPixmap pix("C:/Users/Jammoussi Yasmine/Documents/untitled/nabeul.png");
                                     int w = ui->label_pic->width();
                                     int h = ui->label_pic->height();
                                      ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


                                 }
                              else if(ui->textEdit->toPlainText()=="Jendouba")
                                 {ui->label_pic->clear();
                                     QPixmap pix("C:/Users/Jammoussi Yasmine/Documents/untitled/jendouba.png");
                                     int w = ui->label_pic->width();
                                     int h = ui->label_pic->height();
                                      ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


                                 }
                              else if(ui->textEdit->toPlainText()=="Siliana")
                                 {ui->label_pic->clear();
                                     QPixmap pix("C:/Users/Jammoussi Yasmine/Documents/untitled/siliana.png");
                                     int w = ui->label_pic->width();
                                     int h = ui->label_pic->height();
                                      ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


                                 }
                            else if(ui->textEdit->toPlainText()=="Tunis")
                              { ui->label_pic->clear();
                                  QPixmap pix("C:/Users/Jammoussi Yasmine/Documents/untitled/tunis.png");
                                  int w = ui->label_pic->width();
                                  int h = ui->label_pic->height();
                                   ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


                              }
                              else if(ui->textEdit->toPlainText()=="Ariana")
                                 {ui->label_pic->clear();
                                     QPixmap pix("C:/Users/Jammoussi Yasmine/Documents/untitled/ariana.png");
                                     int w = ui->label_pic->width();
                                     int h = ui->label_pic->height();
                                      ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

                                 }
                              else if(ui->textEdit->toPlainText()=="Beja")
                                 {ui->label_pic->clear();
                                     QPixmap pix("C:/Users/Jammoussi Yasmine/Documents/untitled/beja.png");
                                     int w = ui->label_pic->width();
                                     int h = ui->label_pic->height();
                                      ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


                                 }
                              else if(ui->textEdit->toPlainText()=="Ben Arous")
                                 {ui->label_pic->clear();
                                     QPixmap pix("C:/Users/Jammoussi Yasmine/Documents/untitled/benarous.png");
                                     int w = ui->label_pic->width();
                                     int h = ui->label_pic->height();
                                      ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


                                 }
                              else if(ui->textEdit->toPlainText()=="Gabes")
                                 {ui->label_pic->clear();
                                     QPixmap pix("C:/Users/Jammoussi Yasmine/Documents/untitled/gabes.png");
                                     int w = ui->label_pic->width();
                                     int h = ui->label_pic->height();
                                      ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


                                 }

                            if  (ui->textEdit->toPlainText()== "Gafsa")
                                        {ui->label_pic->clear();

                                  QPixmap pix("C:/Users/Jammoussi Yasmine/Documents/untitled/gafsa.png");
                                 int w = ui->label_pic->width();
                                 int h = ui->label_pic->height();
                                  ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
                                         }
                            else if(ui->textEdit->toPlainText()=="Jendouba")
                              { ui->label_pic->clear();
                                  QPixmap pix("C:/Users/Jammoussi Yasmine/Documents/untitled/jendouba.png");
                                  int w = ui->label_pic->width();
                                  int h = ui->label_pic->height();
                                   ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


                              }
                              else if(ui->textEdit->toPlainText()=="Kasserine")
                                 {ui->label_pic->clear();
                                     QPixmap pix("C:/Users/Jammoussi Yasmine/Documents/untitled/kasserine.png");
                                     int w = ui->label_pic->width();
                                     int h = ui->label_pic->height();
                                      ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

                                 }
                              else if(ui->textEdit->toPlainText()=="Kebili")
                                 {ui->label_pic->clear();
                                     QPixmap pix("C:/Users/Jammoussi Yasmine/Documents/untitled/kebili.png");
                                     int w = ui->label_pic->width();
                                     int h = ui->label_pic->height();
                                      ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


                                 }
                              else if(ui->textEdit->toPlainText()=="Mahdia")
                                 {ui->label_pic->clear();
                                     QPixmap pix("C:/Users/Jammoussi Yasmine/Documents/untitled/mahdia.png");
                                     int w = ui->label_pic->width();
                                     int h = ui->label_pic->height();
                                      ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


                                 }
                              else if(ui->textEdit->toPlainText()=="Manouba")
                                 {ui->label_pic->clear();
                                     QPixmap pix("C:/Users/Jammoussi Yasmine/Documents/untitled/manouba.png");
                                     int w = ui->label_pic->width();
                                     int h = ui->label_pic->height();
                                      ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


                                 }
                            else if(ui->textEdit->toPlainText()=="Medenine")
                              { ui->label_pic->clear();
                                  QPixmap pix("C:/Users/Jammoussi Yasmine/Documents/untitled/medenine.png");
                                  int w = ui->label_pic->width();
                                  int h = ui->label_pic->height();
                                   ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


                              }
                              else if(ui->textEdit->toPlainText()=="Monastir")
                                 {ui->label_pic->clear();
                                     QPixmap pix("C:/Users/Jammoussi Yasmine/Documents/untitled/monastir.png");
                                     int w = ui->label_pic->width();
                                     int h = ui->label_pic->height();
                                      ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

                                 }
                              else if(ui->textEdit->toPlainText()=="Sfax")
                                 {ui->label_pic->clear();
                                     QPixmap pix("C:/Users/Jammoussi Yasmine/Documents/untitled/sfax.png");
                                     int w = ui->label_pic->width();
                                     int h = ui->label_pic->height();
                                      ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


                                 }
                              else if(ui->textEdit->toPlainText()=="Sidi Bouzid")
                                 {ui->label_pic->clear();
                                     QPixmap pix("C:/Users/Jammoussi Yasmine/Documents/untitled/sidibouzid.png");
                                     int w = ui->label_pic->width();
                                     int h = ui->label_pic->height();
                                      ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


                                 }
                              else if(ui->textEdit->toPlainText()=="Tataouine")
                                 {ui->label_pic->clear();
                                     QPixmap pix("C:/Users/Jammoussi Yasmine/Documents/untitled/tataouine.png");
                                     int w = ui->label_pic->width();
                                     int h = ui->label_pic->height();
                                      ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));}
                              else if(ui->textEdit->toPlainText()=="Zaghouan")
                                    {ui->label_pic->clear();
                                       QPixmap pix("C:/Users/Jammoussi Yasmine/Documents/untitled/zaghouan.png");
                                        int w = ui->label_pic->width();
                                        int h = ui->label_pic->height();
                                         ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
                                         }
                                      else if(ui->textEdit->toPlainText()=="Tozeur")
                                         {ui->label_pic->clear();
                                             QPixmap pix("C:/Users/Jammoussi Yasmine/Documents/untitled/tozeur.png");
                                             int w = ui->label_pic->width();
                                             int h = ui->label_pic->height();
                                              ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


                        }
                          }
}
}
