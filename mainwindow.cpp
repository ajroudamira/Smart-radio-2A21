#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "crud.h"
#include"metiers.h"
#include <QMessageBox>
#include <QSqlQuery>
#include<QMetaObject>
#include<QtEvents>
#include <QMediaPlayer>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{    QWidget::showFullScreen();

     ui->setupUi(this);
      ui->stop->setDisabled(true);
          ui->audio->setEnabled(true);
      ui->tableau->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableau->setModel(c.afficher());
    QDate date=QDate::currentDate();
     QString date1 = "12/12/2025";
     QDate date2 = QDate::fromString(date1,"dd/MM/yyyy");
    ui->dateTimeEdit->setDateRange(date,date2);
    // STATISTIQUE
     QSqlQuery q1,q2,q3,q4,q5,q6;
     int tot=0,c1=0,c2=0,c3=0,c4=0,c5=0;

     q1.prepare("SELECT * FROM PROGRAMME");
     q1.exec();

     q2.prepare("SELECT * FROM PROGRAMME WHERE DIFNAME='HAYTHEM GIRATT'");
     q2.exec();

     q3.prepare("SELECT * FROM PROGRAMME WHERE DIFNAME='MIGALO'");
     q3.exec();

     q4.prepare("SELECT * FROM PROGRAMME WHERE DIFNAME='YASSINE KHRAIEF'");
     q4.exec();

     q5.prepare("SELECT * FROM PROGRAMME WHERE DIFNAME='MOSEEB SASSI'");
     q5.exec();

     q6.prepare("SELECT * FROM PROGRAMME WHERE DIFNAME='RAFIK HELLICH'");
     q6.exec();


     while (q1.next()){tot++;}
     while (q2.next()){c1++;}
     while (q3.next()){c2++;}
     while (q4.next()){c3++;}
     while (q5.next()){c4++;}
     while (q6.next()){c5++;}
    /* c1=c1/tot;
     c2=c2/tot;
     c3=c3/tot;
     c4=c4/tot;
     c5=c5/tot;*/
    QBarSet *set1 = new QBarSet("HAYTHEM GIRATT");
    QBarSet *set2 = new QBarSet("MIGALO");
    QBarSet *set3 = new QBarSet("YASSINE KHRAIEF");
    QBarSet *set4 = new QBarSet("MOSEEB SASSI");
    QBarSet *set5 = new QBarSet("RAFIK HELLICHE");

    // Assign values for each bar
     *set1 << c1 ;
     *set2 << c2 ;
     *set3 << c3 ;
     *set4 << c4 ;
     *set5 << c5 ;

    // Add all sets of data to the chart as a whole
    // 1. Bar Chart
    QBarSeries *series = new QBarSeries();

    // 2. Stacked bar chart
    // QHorizontalStackedBarSeries *series = new QHorizontalStackedBarSeries();

    series->append(set1);
    series->append(set2);
    series->append(set3);
    series->append(set4);
    series->append(set5);

    // Used to define the bar chart to display, title
    // legend,
    QChart *chart = new QChart();

    // Add the chart
    chart->addSeries(series);

    // Set title
    chart->setTitle("STATISTIQUE");

    // Define starting animation
    // NoAnimation, GridAxisAnimations, SeriesAnimations
    chart->setAnimationOptions(QChart::AllAnimations);

    // Holds the category titles
    QStringList categories;
    categories << "STATISTIQUE";

    // Adds categories to the axes
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();

    // 1. Bar chart
    chart->setAxisX(axis, series);
    // 2. Stacked Bar chart

    // Define where the legend is displayed
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);


    // Used to display the chart
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

     chartView->setMinimumSize(1121,481);
    chartView->setParent(ui->tableau_2);


    // Used to change the palette
    QPalette pal = qApp->palette();

    // Apply palette changes to the application
    qApp->setPalette(pal);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{


QString name=ui->le_nom->text();
QString id=ui->le_nom_2->text();
QString difname=ui->Nomdiff->currentText();
QDateTime time=ui->dateTimeEdit->dateTime();
if(name.length()<11&&difname.length()<21&&id.length()<20){
if(!name.isEmpty()&&!id.isEmpty()&&!difname.isEmpty()){


CRUD C(name,id,difname,time);

bool test=C.ajouter();
if(test){
    ui->tableau->setModel(c.afficher());

    QMessageBox::information(nullptr, QObject::tr(" OK"),
                QObject::tr("Ajout Effectué.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

    // STATISTIQUE
     QSqlQuery q1,q2,q3,q4,q5,q6;
     int tot=0,c1=0,c2=0,c3=0,c4=0,c5=0;

     q1.prepare("SELECT * FROM PROGRAMME");
     q1.exec();

     q2.prepare("SELECT * FROM PROGRAMME WHERE DIFNAME='HAYTHEM GIRATT'");
     q2.exec();

     q3.prepare("SELECT * FROM PROGRAMME WHERE DIFNAME='MIGALO'");
     q3.exec();

     q4.prepare("SELECT * FROM PROGRAMME WHERE DIFNAME='YASSINE KHRAIEF'");
     q4.exec();

     q5.prepare("SELECT * FROM PROGRAMME WHERE DIFNAME='MOSEEB SASSI'");
     q5.exec();

     q6.prepare("SELECT * FROM PROGRAMME WHERE DIFNAME='RAFIK HELLICHE'");
     q6.exec();


     while (q1.next()){tot++;}
     while (q2.next()){c1++;}
     while (q3.next()){c2++;}
     while (q4.next()){c3++;}
     while (q5.next()){c4++;}
     while (q6.next()){c5++;}
     /*c1=c1/tot;
     c2=c2/tot;
     c3=c3/tot;
     c4=c4/tot;
     c5=c5/tot;*/
    QBarSet *set1 = new QBarSet("HAYTHEM GIRATT");
    QBarSet *set2 = new QBarSet("MIGALO");
    QBarSet *set3 = new QBarSet("YASSINE KHRAIEF");
    QBarSet *set4 = new QBarSet("MOSEEB SASSI");
    QBarSet *set5 = new QBarSet("RAFIK HELLICHE");

    // Assign values for each bar
     *set1 << c1 ;
     *set2 << c2 ;
     *set3 << c3 ;
     *set4 << c4 ;
     *set5 << c5 ;

    // Add all sets of data to the chart as a whole
    // 1. Bar Chart
    QBarSeries *series = new QBarSeries();

    // 2. Stacked bar chart
    // QHorizontalStackedBarSeries *series = new QHorizontalStackedBarSeries();

    series->append(set1);
    series->append(set2);
    series->append(set3);
    series->append(set4);
    series->append(set5);

    // Used to define the bar chart to display, title
    // legend,
    QChart *chart = new QChart();

    // Add the chart
    chart->addSeries(series);

    // Set title
    chart->setTitle("STATISTIQUE");

    // Define starting animation
    // NoAnimation, GridAxisAnimations, SeriesAnimations
    chart->setAnimationOptions(QChart::AllAnimations);

    // Holds the category titles
    QStringList categories;
    categories << "STATISTIQUE";

    // Adds categories to the axes
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();

    // 1. Bar chart
    chart->setAxisX(axis, series);

    // 2. Stacked Bar chart

    // Define where the legend is displayed
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);


    // Used to display the chart
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(1121,481);
    chartView->setParent(ui->tableau_2);


    // Used to change the palette
    QPalette pal = qApp->palette();



    // Apply palette changes to the application
    qApp->setPalette(pal);



}


else
    QMessageBox::critical(nullptr, QObject::tr(" OK"),
                QObject::tr("Ajout Non Effectué: ID Exsite Déja.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}

else
    QMessageBox::critical(nullptr, QObject::tr(" OK"),
                QObject::tr("Ajout Non Effectué: Un ou plusieurs cases sont vide.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}

else QMessageBox::critical(nullptr, QObject::tr(" OK"),
                           QObject::tr("Ajout Non Effectué: Vous avez écrit plus que le maximum d'une case.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);



}




void MainWindow::on_supprimer_clicked()
{       QString id=ui->Supression->text();
        if(!id.isEmpty()){
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
                            "Click Cancel to exit."), QMessageBox::Cancel);}
        else
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                        QObject::tr("Suppression Non Effectué : La case de suppression est vide.\n"
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
            ui->dateTimeEdit->setDateTime(query.value(3).toDateTime());
            ui->le_nom-> setText(query.value(0).toString());
            ui->Supression ->setText(query.value(0).toString());
            ui->le_nom_2->setText(query.value(1).toString());
            ui->Nomdiff->setCurrentText(query.value(2).toString());



        }

    }

}

void MainWindow::on_pb_modif_clicked()
{
QString name=ui->le_nom->text();
QString id=ui->le_nom_2->text();
QString difname=ui->Nomdiff->currentText();
QDateTime time=ui->dateTimeEdit->dateTime();
CRUD C(name,id,difname,time);
if(name.length()<11&&difname.length()<21&&id.length()<20){
if(!name.isEmpty()&&!id.isEmpty()&&!difname.isEmpty()){

bool test=C.modifier();
if(test){
    ui->tableau->setModel(c.afficher());

    QMessageBox::information(nullptr, QObject::tr(" OK"),
                QObject::tr("Ajout Effectué.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

    // STATISTIQUE
     QSqlQuery q1,q2,q3,q4,q5,q6;
     int tot=0,c1=0,c2=0,c3=0,c4=0,c5=0;

     q1.prepare("SELECT * FROM PROGRAMME");
     q1.exec();

     q2.prepare("SELECT * FROM PROGRAMME WHERE DIFNAME='HAYTHEM GIRATT'");
     q2.exec();

     q3.prepare("SELECT * FROM PROGRAMME WHERE DIFNAME='MIGALO'");
     q3.exec();

     q4.prepare("SELECT * FROM PROGRAMME WHERE DIFNAME='YASSINE KHRAIEF'");
     q4.exec();

     q5.prepare("SELECT * FROM PROGRAMME WHERE DIFNAME='MOSEEB SASSI'");
     q5.exec();

     q6.prepare("SELECT * FROM PROGRAMME WHERE DIFNAME='RAFIK HELLICHE'");
     q6.exec();


     while (q1.next()){tot++;}
     while (q2.next()){c1++;}
     while (q3.next()){c2++;}
     while (q4.next()){c3++;}
     while (q5.next()){c4++;}
     while (q6.next()){c5++;}
    /* c1=c1/tot;
     c2=c2/tot;
     c3=c3/tot;
     c4=c4/tot;
     c5=c5/tot;*/
    QBarSet *set1 = new QBarSet("HAYTHEM GIRATT");
    QBarSet *set2 = new QBarSet("MIGALO");
    QBarSet *set3 = new QBarSet("YASSINE KHRAIEF");
    QBarSet *set4 = new QBarSet("MOSEEB SASSI");
    QBarSet *set5 = new QBarSet("RAFIK HELLICHE");

    // Assign values for each bar
     *set1 << c1 ;
     *set2 << c2 ;
     *set3 << c3 ;
     *set4 << c4 ;
     *set5 << c5 ;

    // Add all sets of data to the chart as a whole
    // 1. Bar Chart
    QBarSeries *series = new QBarSeries();

    // 2. Stacked bar chart
    // QHorizontalStackedBarSeries *series = new QHorizontalStackedBarSeries();

    series->append(set1);
    series->append(set2);
    series->append(set3);
    series->append(set4);
    series->append(set5);

    // Used to define the bar chart to display, title
    // legend,
    QChart *chart = new QChart();

    // Add the chart
    chart->addSeries(series);

    // Set title
    chart->setTitle("STATISTIQUE");

    // Define starting animation
    // NoAnimation, GridAxisAnimations, SeriesAnimations
    chart->setAnimationOptions(QChart::AllAnimations);

    // Holds the category titles
    QStringList categories;
    categories << "STATISTIQUE";

    // Adds categories to the axes
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();

    // 1. Bar chart
    chart->setAxisX(axis, series);

    // 2. Stacked Bar chart

    // Define where the legend is displayed
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);


    // Used to display the chart
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(1121,481);
    chartView->setParent(ui->tableau_2);


    // Used to change the palette
    QPalette pal = qApp->palette();


    // Apply palette changes to the application
    qApp->setPalette(pal);


}
else
    QMessageBox::critical(nullptr, QObject::tr(" OK"),
                QObject::tr("Ajout Non Effectué: L'ID n'existe pas.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}
else
    QMessageBox::critical(nullptr, QObject::tr(" OK"),
                QObject::tr("Ajout Non Effectué : Un ou plusieurs cases sont vide .\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);




}
else QMessageBox::critical(nullptr, QObject::tr(" OK"),
                            QObject::tr("Ajout Non Effectué: Vous avez écrit plus que le maximum d'une case.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);



 }





void MainWindow::on_pb_recher_clicked()
{
    QString s=ui->rechercher->text();

    if(ui->rech->currentText()=="Nom de Programme")
       ui->tableau->setModel(m.recherche(1,s));
    else if(ui->rech->currentText()=="ID de Programme")
       ui->tableau->setModel( m.recherche(2,s));
   else if(ui->rech->currentText()=="Nom du Diffuseur")
        ui->tableau->setModel(m.recherche(3,s));
}

void MainWindow::on_pb_tri_clicked()
{
    if(ui->tri->currentText()=="Nom de Programme")
       ui->tableau->setModel(m.sort(1));
    else if(ui->tri->currentText()=="ID de Programme")
       ui->tableau->setModel( m.sort(2));
    else if(ui->tri->currentText()=="Nom du Diffuseur")
        ui->tableau->setModel(m.sort(3));
}

void MainWindow::on_pb_pdf_clicked()
{   QString s;
    s=ui->PDF->text();
    m.exportpdf(s);
}

void MainWindow::on_pushButton_clicked()
{   QString test=ui->test->text();
    if(m.PREDICTION(test)!=-1){
     QString pred=QString::number(int(m.PREDICTION(test)));
     ui->Estimation->setText(pred);
     ui->estimation->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
     ui->estimation->setModel(m.Affichage(test));

}
    else QMessageBox::critical(nullptr, QObject::tr(" NOT OK"),
                               QObject::tr("Nom Du Base Est Incorrecte Réessayer.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);

}








void MainWindow::on_audio_clicked(bool checked)
{   checked=on_audio_clicked();
    if(checked){
    QString s1=ui->audioname->text();
    QString s="C:/Users/essay/Desktop/lenna/"+s1;
    QAudioEncoderSettings audioSettings;
    audioSettings.setCodec("audio/amr");
    audioSettings.setQuality(QMultimedia::HighQuality);

    audioRecorder->setEncodingSettings(audioSettings);

    audioRecorder->setOutputLocation(QUrl::fromLocalFile(s));
    const QStringList inputs = audioRecorder->audioInputs();
    QString selectedInput = audioRecorder->defaultAudioInput();
 audioRecorder->record();

    for (const QString &input : inputs) {
    QString description = audioRecorder->audioInputDescription(input);
    // show descriptions to user and allow selection
    selectedInput = input;}}
}

bool MainWindow::on_audio_clicked()
{ ui->audio->setDisabled(true);
   ui->stop->setEnabled(true);
  return true;
}

void MainWindow::on_stop_clicked()
{   ui->stop->setDisabled(true);
    ui->audio->setEnabled(true);
    audioRecorder->stop();
}



void MainWindow::on_play_clicked()
{    QString s1=ui->audioname->text();
     QString s="C:/Users/essay/Desktop/lenna/"+s1+".wav";

      {
          sourceFile.setFileName(s);
          sourceFile.open(QIODevice::ReadOnly);

          QAudioFormat format;
          // Set up the format, eg.
          format.setSampleRate(25000);
          format.setChannelCount(2);
          format.setSampleSize(16);
          format.setCodec("audio/pcm");
          format.setByteOrder(QAudioFormat::LittleEndian);
          format.setSampleType(QAudioFormat::UnSignedInt);

          QAudioDeviceInfo info(QAudioDeviceInfo::defaultOutputDevice());
          if (!info.isFormatSupported(format)) {
              qWarning() << "Raw audio format not supported by backend, cannot play audio.";
              return;
          }

          audio = new QAudioOutput(format, this);
          connect(audio, SIGNAL(stateChanged(QAudio::State)), this, SLOT(handleStateChanged(QAudio::State)));
          audio->start(&sourceFile);
      }
}

void MainWindow::on_pb_modif_2_clicked()
{
    ui->tableau->setModel(c.afficher());
}
