#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

//zmienna globalne
QString MainWindow::sciezkaPliku = "hasla.txt";
QString MainWindow::haslaPliku   = "";
int     MainWindow::liczbaGraczy = 2;
QStringList MainWindow::imionaGraczy;

//wejscie do edytora hasel
void MainWindow::on_pushButtonEdytorHasel_clicked()
{
    hasla h;
    h.otworzPlik(0);
    h.exec();
    h.close();
    if (haslaPliku.length() < 10)
        ui->pushButtonStart->setDisabled(true);
    else
        ui->pushButtonStart->setEnabled(true);
}

//uruchomienie gry
void MainWindow::on_pushButtonStart_clicked()
{
    if (haslaPliku.length() < 10) //tak na wszelki wypadek
    {
        QMessageBox brakHasel ("ERROR", "Blad - nie załadowano pliku z haslami",
                               QMessageBox::Warning,
                               QMessageBox::Ok, 0, 0 );
        brakHasel.exec();
    }
    else
    {
        imionaGraczy << ui->lineImieGracz1->displayText() << ui->lineImieGracz2->displayText() << ui->lineImieGracz3->displayText() << ui->lineImieGracz4->displayText();
        oknoGry o;
        o.exec();
        o.close();
    }
}

//ustawienie liczby graczy
void MainWindow::on_radio2graczy_toggled()
{
    liczbaGraczy = 2;
}

//ustawienie liczby graczy
void MainWindow::on_radio3graczy_toggled()
{
    liczbaGraczy = 3;
}

//ustawienie liczby graczy
void MainWindow::on_radio4graczy_toggled()
{
    liczbaGraczy = 4;
}

//wyjscie z programu
void MainWindow::on_pushButtonWyjscie_clicked()
{
   qApp->exit();
}

