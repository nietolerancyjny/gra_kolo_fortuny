#ifndef OKNOGRY_H
#define OKNOGRY_H

#include "mainwindow.h"
#include "windows.h"
#include <ctime>
#include <QDialog>
#include <QObject>
#include <QStringList>
#include <QToolButton>
#include <QInputDialog>

enum komunikaty
{
    CZYJA_KOLEJKA,
    ZAKREC_KOLEM,
    ZAKREC_KOLEM_LUB_KUP_SAMOGLOSKE,
    ODGADNIJ_SAMOGLOSKE,
    WYSWIETL_WYNIK,
    KUPIL_SAMOGLOSKE,
};

enum stanyGry
{
    KRECENIE_KOLEM,
    ODGADUJE_LITERE,
    ODGADL_LITERE,
    NIE_ODGADL_LITERY,
    KUPUJE_SAMOGLOSKE,
    BANKRUT,
    NAGRODA,
    STOP,
    KONIEC_GRY,
};

namespace Ui {
class oknoGry;
}

class oknoGry : public QDialog
{
Q_OBJECT

public:
     explicit oknoGry(QWidget *parent = 0);
     ~oknoGry();

private slots:

     //przyciski
     void on_pbUkryj_clicked();
     void on_pbWyswietl_clicked();
     void on_pbKupSamogloske_clicked();
     void on_pbZakrecKolem_clicked();
     void on_pbOdgadnijHaslo_clicked();

     //klawiatura
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

private:
    Ui::oknoGry *ui;

    //wyswietlacz / okno / gra
    void nowaGra();
    void koniecGry();
    void rozgrywka();
    void nastepnyStanGry();
    void stylPrzyciskow();
    void wyczyscEkran();
    void kolorujPusteZnaki();
    void pokazSamogloski(bool decyzja);
    void pokazSpolgloski(bool decyzja);
    void pokazPrzyciski(bool decyzja);
    void pokazKlawiature(bool decyzja);
    void pokazZakrecKolem(bool decyzja);
    void pokazKupSamogloski(bool decyzja);
    void pokazOdgadujeHaslo(bool decyzja);
    void wyswietlKomunikat(int komunikat);
    void wyswietlKomunikatMsgBox(QString komunikat);
    void wylosujNagrode();
    QToolButton * tablica[60];
    komunikaty komunikat;
    stanyGry stanGry;

    //haslo
    void wylosujHaslo();
    void wstawHaslo();
    void ukryjHaslo();
    void wyswietlHaslo();
    void sprawdzIloscLiterHasla();
    void odgadujeHaslo();
    void odgadujeLitere(QString znak, bool spolgloska);
    QString wylosowaneHaslo;
    QStringList odgadywaneLitery;
    int pozostaloLiterDoOdgadniecia;

    //kolo
    void wczytajKolo();
    void obroc();
    unsigned obrot;
    unsigned katKola;
    unsigned stanKola;
    QStringList wartosciNaKole;
    //QTimer * timer;

    //gracze
    void wylosujGracza();
    void nastepnyGracz();
    int kolejkaGracza;
    int wynikGracza[4];

};

#endif // OKNOGRY_H
