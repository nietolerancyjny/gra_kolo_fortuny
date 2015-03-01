#ifndef OKNOGRY_H
#define OKNOGRY_H

#include "mainwindow.h"
#include <QDialog>
#include <QStringList>
#include <QToolButton>
#include <QTimer>
#include <ctime>


namespace Ui {
class oknoGry;
}

class oknoGry : public QDialog
{
Q_OBJECT

public:
     explicit oknoGry(QWidget *parent = 0);
     ~oknoGry();
     void nowaGra();

private slots:

     void Obroc_o_kat();

     void on_pbUkryj_clicked();
     void on_pbWyswietl_clicked();
     void on_pbLitera_clicked();
     void on_pbKlawiatura_clicked();

     void on_klaw_y_clicked();
     void on_klaw_u_clicked();
     void on_klaw_oPL_clicked();
     void on_klaw_o_clicked();
     void on_klaw_i_clicked();
     void on_klaw_ePL_clicked();
     void on_klaw_e_clicked();
     void on_klaw_aPL_clicked();
     void on_klaw_a_clicked();
     void on_klaw_zPL_clicked();
     void on_klaw_zPL2_clicked();
     void on_klaw_z_clicked();
     void on_klaw_w_clicked();
     void on_klaw_x_clicked();
     void on_klaw_v_clicked();
     void on_klaw_t_clicked();
     void on_klaw_sPL_clicked();
     void on_klaw_s_clicked();
     void on_klaw_r_clicked();
     void on_klaw_q_clicked();
     void on_klaw_p_clicked();
     void on_klaw_nPL_clicked();
     void on_klaw_n_clicked();
     void on_klaw_m_clicked();
     void on_klaw_lPL_clicked();
     void on_klaw_l_clicked();
     void on_klaw_k_clicked();
     void on_klaw_j_clicked();
     void on_klaw_h_clicked();
     void on_klaw_g_clicked();
     void on_klaw_f_clicked();
     void on_klaw_d_clicked();
     void on_klaw_cPL_clicked();
     void on_klaw_c_clicked();
     void on_klaw_b_clicked();
     void on_pbNowe_clicked();

     void on_pbZakrecKolem_clicked();

private:
    Ui::oknoGry *ui;

    void wczytajKolo();
    void wylosujHaslo();
    void stylPrzyciskow();
    void wyczyscEkran();
    void kolorujPusteZnaki();
    void wstawHaslo();
    void ukryjHaslo();
    void wyswietlHaslo();
    void pokazSamogloski(bool decyzja);
    void pokazSpolgloski(bool decyzja);
    int odgadujeLitere(QString znak);

    QString wylosowaneHaslo;
    QToolButton* tablica[59];


    unsigned obrot;
    unsigned kat_kola;
    unsigned stan_kola;
    QStringList wartosciNaKole;
    unsigned spowolnienie1;
    QTimer * timer;

};


#endif // OKNOGRY_H
