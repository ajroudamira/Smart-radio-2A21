#ifndef LOCAWIFI_H
#define LOCAWIFI_H
#include <QFileDialog>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDialog>
#include <QDesktopWidget>
#include <QSettings>
#include <QFile>
#include <QDataStream>
namespace Ui {
class locawifi;
}

class locawifi : public QDialog
{
    Q_OBJECT

public:
    explicit locawifi(QWidget *parent = nullptr);
    ~locawifi();

private:
    Ui::locawifi *lu;
};

#endif // LOCAWIFI_H
