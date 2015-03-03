#ifndef KLAWIATURA_H
#define KLAWIATURA_H

#include <QDialog>


namespace Ui {
class klawiatura;
}

class klawiatura : public QDialog
{
Q_OBJECT

public:
     explicit klawiatura(QWidget *parent = 0);
     ~klawiatura();

private:
    Ui::klawiatura *ui;

};


#endif // KLAWIATURA_H
