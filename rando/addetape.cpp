#include "addetape.h"

AddEtape::AddEtape(Etape * etape, QWidget *parent) :
    QDialog(parent), _etape(etape)
{
    this->setMinimumSize(640,640);
    _scrollArea = new QScrollArea();
    _scrollArea->setAttribute(Qt::WA_DeleteOnClose);
    _scrollArea->setWidget(this);
    _scrollArea->show();

    _labels.clear();
    _labels.append(new QLabel("Nom etape :"));
    _labels.append(new QLabel("Description :"));
    _labels.append(new QLabel("Distance :"));
    _labels.append(new QLabel("Duree :"));
    _labels.append(new QLabel("Altitude :"));
    _labels.append(new QLabel("Dénivelé :"));
    _labels.append(new QLabel("Latitude :"));
    _labels.append(new QLabel("Longitude :"));
    _labels.append(new QLabel("Description de l'étape :"));
    _labels.append(new QLabel("Image :"));

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

AddEtape::~AddEtape()
{
    delete _buttonOK;
    delete _buttonAbort;
    for(int i=0; i<_labels.size(); i++)
        delete _labels.at(i);
    _labels.clear();
    for(int i=0; i<_lineEdits.size(); i++)
        delete _lineEdits.at(i);
    _lineEdits.clear();
    _etape = NULL;
    delete _etape;
    delete _layout;
    _scrollArea->close();
}

void AddEtape::ok()
{
    QStringList l = verif();
    if(l.size()==0)
    {
        _etape->setNom(_lineEdits.at(0)->text());
        _etape->setDesc(_lineEdits.at(1)->text());
        _etape->setDistance(_lineEdits.at(2)->text());
        _etape->setDuree(_lineEdits.at(3)->text());
        _etape->setAlt(_lineEdits.at(4)->text());
        _etape->setDeniv(_lineEdits.at(5)->text());
        _etape->setLat(_lineEdits.at(6)->text());
        _etape->setLong(_lineEdits.at(7)->text());
        _etape->setDescEtape(_lineEdits.at(8)->text());
        _etape->setImage(_lineEdits.at(9)->text());
        close();
    }
    else
    {
        QString s;
        for(int i=0; i<l.size(); i++)
            s.append(l.at(i)+'\n');
        QMessageBox::critical(this, "Erreur", s, QMessageBox::Ok);
    }
}

void AddEtape::abort()
{
    close();
}

QStringList AddEtape::verif()
{
    QStringList l;


    QString t = _lineEdits.at(0)->text();
    if((t.size()<5) || (t.size()>70))
    {
        l.append("Le nom doit contenir au minimum 5 caractères et au maximum 70 caractères.");
        _lineEdits.at(0)->setStyleSheet("background-color : #FFC0C0;");
    }
    else
    {
        _lineEdits.at(0)->setStyleSheet("background-color : white;");
        if((t.contains('<')) || (t.contains('>')))
        {
            l.append("Les chevrons '<' '>' sont interdits.");
            _lineEdits.at(0)->setStyleSheet("background-color : #FFC0C0;");
        }
        else
            _lineEdits.at(0)->setStyleSheet("background-color : white;");
    }

    t = _lineEdits.at(1)->text();
    if((t.size()<5) || (t.size()>200))
    {
        l.append("La description doit contenir au minimum 5 caractères et au maximum 200 caractères.");
        _lineEdits.at(1)->setStyleSheet("background-color : #FFC0C0;");
    }
    else
    {
        _lineEdits.at(1)->setStyleSheet("background-color : white;");
        if((t.contains('<')) || (t.contains('>')))
        {
            l.append("Les chevrons '<' '>' sont interdits.");
            _lineEdits.at(1)->setStyleSheet("background-color : #FFC0C0;");
        }
        else
            _lineEdits.at(1)->setStyleSheet("background-color : white;");
    }

    t = _lineEdits.at(2)->text();
    if(!t.contains(QRegExp("(([1-9][0-9]{0,4})|[0-9]))")))
    {
        l.append("La distance doit être de la forme (([1-9][0-9]{4})|[0-9])");
        _lineEdits.at(2)->setStyleSheet("background-color : #FFC0C0;");
    }
    else
    {
        _lineEdits.at(2)->setStyleSheet("background-color : white;");
    }

    t = _lineEdits.at(3)->text();
    if(!t.contains(QRegExp("(([1-9][0-9]{0,3})|[0-9])")))
    {
        l.append("La duree doit être de la forme (([1-9][0-9]{3})|[0-9])");
        _lineEdits.at(3)->setStyleSheet("background-color : #FFC0C0;");
    }
    else
    {
        _lineEdits.at(3)->setStyleSheet("background-color : white;");
    }

    t = _lineEdits.at(4)->text();
    if(!t.contains(QRegExp("\\-?(([1-9][0-9]{0,3})|[0-9])")))
    {
        l.append("L'altitude doit être de la forme \\-?(([1-9][0-9]*)|[0-9])");
        _lineEdits.at(4)->setStyleSheet("background-color : #FFC0C0;");
    }
    else
    {
        _lineEdits.at(4)->setStyleSheet("background-color : white;");
    }

    t = _lineEdits.at(5)->text();
    if(!t.contains(QRegExp("\\-?(([1-9][0-9]{0,4})|[0-9])")))
    {
        l.append("Le dénivelé doit être de la forme \\-?(([1-9][0-9]*)|[0-9])");
        _lineEdits.at(5)->setStyleSheet("background-color : #FFC0C0;");
    }
    else
    {
        _lineEdits.at(5)->setStyleSheet("background-color : white;");
    }

    t = _lineEdits.at(6)->text();
    if(!t.contains(QRegExp("\\-?(([1-9][0-9]{0,1})|[0-9])")))
    {
        l.append("La latitude doit être de la forme \\-?(([1-9][0-9]*)|[0-9])");
        _lineEdits.at(6)->setStyleSheet("background-color : #FFC0C0;");
    }
    else
    {
        _lineEdits.at(6)->setStyleSheet("background-color : white;");
    }

    t = _lineEdits.at(7)->text();
    if(!t.contains(QRegExp("\\-?(([1-9][0-9]{0,2})|[0-9]).[0-9]{6}")))
    {
        l.append("La longitude doit être de la forme \\-?(([1-9][0-9]*)|[0-9])");
        _lineEdits.at(7)->setStyleSheet("background-color : #FFC0C0;");
    }
    else
    {
        _lineEdits.at(7)->setStyleSheet("background-color : white;");
    }

    t = _lineEdits.at(8)->text();
    if((t.size()<5) || (t.size()>2000))
    {
            l.append("La description de l'étape doit contenir au minimum 5 caractères et au maximum 2000 caractères.");
        _lineEdits.at(8)->setStyleSheet("background-color : #FFC0C0;");
    }
    else
    {
        _lineEdits.at(8)->setStyleSheet("background-color : white;");
        if((t.contains('<')) || (t.contains('>')))
        {
            l.append("Les chevrons '<' '>' sont interdits.");
            _lineEdits.at(8)->setStyleSheet("background-color : #FFC0C0;");
        }
        else
            _lineEdits.at(8)->setStyleSheet("background-color : white;");
    }

    t = _lineEdits.at(9)->text();
    if(!QFile::exists(t))
    {
        l.append("L'image n'existe pas.");
        _lineEdits.at(9)->setStyleSheet("background-color : #FFC0C0;");
    }
    else
    {
        _lineEdits.at(9)->setStyleSheet("background-color : white;");
        if((t.contains('<')) || (t.contains('>')))
        {
            l.append("Les chevrons '<' '>' sont interdits.");
            _lineEdits.at(9)->setStyleSheet("background-color : #FFC0C0;");
        }
        else
            _lineEdits.at(9)->setStyleSheet("background-color : white;");
    }


    return l;
}
