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
QString MainWindow::imieGracza1  = "";
QString MainWindow::imieGracza2  = "";
QString MainWindow::imieGracza3  = "";
QString MainWindow::imieGracza4  = "";
int     MainWindow::liczbaGraczy = 2;


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
        imieGracza1 = ui->lineImieGracz1->displayText();
        imieGracza2 = ui->lineImieGracz2->displayText();
        imieGracza3 = ui->lineImieGracz3->displayText();
        imieGracza4 = ui->lineImieGracz4->displayText();
        oknoGry o;
        o.nowaGra();
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

