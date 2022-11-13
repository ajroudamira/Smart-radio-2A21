#ifndef DIALOG_H
#define DIALOG_H

#include <QMainWindow>

namespace Ui {
class dialog;
}

class dialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit dialog(QWidget *parent = nullptr);
    ~dialog();

private slots:
    void on_pb_send_clicked();
    void mailSent(QString);



private:
    Ui::dialog *ui;



    };
#endif // DIALOG_H
