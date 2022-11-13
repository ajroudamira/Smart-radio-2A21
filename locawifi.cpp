#include "locawifi.h"
#include "ui_locawifi.h"
#include <QMessageBox>
locawifi::locawifi(QWidget *parent) :
    QDialog(parent),
    lu(new Ui::locawifi)
{
    lu->setupUi(this);
    QSettings settings(QSettings::IniFormat, QSettings::UserScope,
                       QCoreApplication::organizationName(), QCoreApplication::applicationName());

    lu->axWidget->dynamicCall("Navigate(const QString&)", "https://www.google.com/maps/place/ESPRIT/@36.9016729,10.1713215,15z");

}

locawifi::~locawifi()
{
    delete lu;
}

