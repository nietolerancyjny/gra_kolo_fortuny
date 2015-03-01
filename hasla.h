#ifndef HASLA_H
#define HASLA_H

#include "mainwindow.h"
#include <QDialog>
#include <QString>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

namespace Ui {
class hasla;
}

class hasla : public QDialog
{
Q_OBJECT

public:
     explicit hasla(QWidget *parent = 0);
     ~hasla();
     void otworzPlik(bool decyzja);

private slots:
    void on_pushButtonOtworz_clicked();
    void on_pushButtonZapisz_clicked();

private:
    Ui::hasla *ui;
    void zapiszPlik();

};

#endif // HASLA_H
