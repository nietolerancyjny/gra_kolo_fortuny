#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <hasla.h>
#include <oknogry.h>
#include <QMainWindow>
#include <QString>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    static QString sciezkaPliku;
    static QString haslaPliku;
    static QString imieGracza1;
    static QString imieGracza2;
    static QString imieGracza3;
    static QString imieGracza4;
    static int liczbaGraczy;


private slots:
    void on_pushButtonWyjscie_clicked();
    void on_pushButtonEdytorHasel_clicked();
    void on_pushButtonStart_clicked();

    void on_radio2graczy_toggled();
    void on_radio3graczy_toggled();
    void on_radio4graczy_toggled();

private:
    Ui::MainWindow *ui;



};

#endif // MAINWINDOW_H
