#include "addrando.h"

AddRando::AddRando(QVector<Randonnee> * rand ,QWidget *parent) :
    QDialog(parent), _rand(rand)
{
    this->setMinimumSize(640,640);
    _scrollArea = new QScrollArea();
    _scrollArea->setAttribute(Qt::WA_DeleteOnClose);
    _scrollArea->setWidget(this);
    _scrollArea->show();

    _labels.clear();
    _labels.append(new QLabel("Nom :"));
    _labels.append(new QLabel("Situation :"));
    _labels.append(new QLabel("Prelude :"));
    _labels.append(new QLabel("Descritpion générale :"));
    _labels.append(new QLabel("Descritpion culturelle :"));
    _labels.append(new QLabel("Infos :"));
    _labels.append(new QLabel("Recommandations :"));
    _labels.append(new QLabel("Difficulte :"));
    _labels.append(new QLabel("Epoque :"));
    _labels.append(new QLabel("Depart :"));
    _labels.append(new QLabel("Arrivé :"));
    _labels.append(new QLabel("Carte :"));
    _labels.append(new QLabel("Carroyage :"));
    _labels.append(new QLabel("Nom carte :"));
    _labels.append(new QLabel("Acces :"));
    _labels.append(new QLabel("Parking :"));
    _labels.append(new QLabel("Type de chemin :"));
    _labels.append(new QLabel("Type de terrain :"));
    _labels.append(new QLabel("Materiel :"));

    _lineEdits.clear();
    for(int i=0; i<_labels.size(); i++)
        _lineEdits.append(new QLineEdit());

    _layout = new QGridLayout();
    this->setLayout(_layout);


    for(int i=0; i<_labels.size(); i++)
    {
        _layout->addWidget(_labels.at(i),i,0);
        _layout->addWidget(_lineEdits.at(i),i,1);
    }

    int nbRow = _layout->rowCount();

    _buttonOK = new QPushButton("Ok");
    QObject::connect(_buttonOK, SIGNAL(clicked()), this, SLOT(ok()));
    _layout->addWidget(_buttonOK,nbRow,0,1,2);

    _buttonAbort = new QPushButton("Annuler");
    QObject::connect(_buttonAbort, SIGNAL(clicked()), this, SLOT(abort()));
    _layout->addWidget(_buttonAbort,nbRow+1,0,1,2);
}

AddRando::~AddRando()
{
    delete _buttonOK;
    delete _buttonAbort;
    for(int i=0; i<_labels.size(); i++)
        delete _labels.at(i);
    _labels.clear();
    for(int i=0; i<_lineEdits.size(); i++)
        delete _lineEdits.at(i);
    _lineEdits.clear();
    _rand = NULL;
    delete _rand;
    delete _layout;
    _scrollArea->close();
}

void AddRando::ok()
{
    if(verif())
    {
    }
}

void AddRando::abort()
{
    close();
}

bool AddRando::verif()
{
    return true;
}
