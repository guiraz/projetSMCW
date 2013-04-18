#include "addrando.h"

AddRando::AddRando(QString * current, QWidget *parent) :
    QDialog(parent), _nomRando(current)
{
    this->setFixedSize(500,150);
    this->setWindowTitle("Quel est le nom de la nouvelle randonnée?");

    _lineEdit = new QLineEdit(this);
    _lineEdit->setGeometry(3,50,494,27);

    _buttonOK = new QPushButton("Ok",this);
    _buttonOK->setGeometry(300,120,97,27);
    QObject::connect(_buttonOK, SIGNAL(clicked()), this, SLOT(ok()));

    _buttonAbort = new QPushButton("Annuler",this);
    _buttonAbort->setGeometry(400,120,97,27);
    QObject::connect(_buttonAbort, SIGNAL(clicked()), this, SLOT(abort()));
}

AddRando::~AddRando()
{
}

void AddRando::ok()
{
    if((_lineEdit->text().contains('<')) || (_lineEdit->text().contains('>')))
    {
        QMessageBox::critical(this, "Erreur de saisie", "Les chevrons '<' '>' sont interdits!", QMessageBox::Ok);
    }
    else
    {
        if(_lineEdit->text().size() < 5)
        {
            QMessageBox::critical(this, "Erreur de saisie", "Nombre de caractères insuffisants", QMessageBox::Ok);
        }
        else
        {
            * _nomRando = QString(_lineEdit->text());
            this->close();
        }
    }
}

void AddRando::abort()
{
    * _nomRando = QString("");
    this->close();
}
