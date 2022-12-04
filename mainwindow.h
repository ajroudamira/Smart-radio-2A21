#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"crud.h"
#include"metiers.h"
#include<QtCharts>
#include<QChartView>
#include<QLineSeries>
#include <QCloseEvent>
#include <QString>
#include <QUrl>
#include <QKeySequenceEdit>
#include <QDebug>
#include <QAudioRecorder>
#include <QAudioBuffer>
#include <QMediaRecorder>
#include <QAudioOutput>
#include<QMediaPlayer>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();
    void on_supprimer_clicked();
    void on_tableau_activated(const QModelIndex &index);
    void on_pb_modif_clicked();

    void on_pb_recher_clicked();

    void on_pb_tri_clicked();

    void on_pb_pdf_clicked();

    void on_pushButton_clicked();



    void on_audio_clicked(bool checked);

    bool on_audio_clicked();

    void on_stop_clicked();


    void on_play_clicked();
    void handleStateChanged(QAudio::State newState)
    {
        switch (newState) {
            case QAudio::IdleState:
                // Finished playing (no more data)
                audio->stop();
                sourceFile.close();
                delete audio;
                break;

            case QAudio::StoppedState:
                // Stopped for other reasons
                if (audio->error() != QAudio::NoError) {
                    // Error handling
                }
                break;

            default:
                // ... other cases as appropriate
                break;
        }
    }
    void on_pb_modif_2_clicked();

private:
    Ui::MainWindow *ui;
    CRUD c;
    Metiers m;
    QAudioRecorder *audioRecorder= new QAudioRecorder;
    QFile sourceFile;
    QAudioOutput* audio;


};
#endif // MAINWINDOW_H
