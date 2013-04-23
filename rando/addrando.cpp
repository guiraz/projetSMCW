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
    QStringList l = verif();
    if(l.size()==0)
    {
        Randonnee temp;
        temp.setNom(_lineEdits.at(0)->text());
        temp.setSituation(_lineEdits.at(1)->text());
        temp.setPrelude(_lineEdits.at(2)->text());
        temp.setDescGen(_lineEdits.at(3)->text());
        temp.setDescCult(_lineEdits.at(4)->text());
        temp.setInfos(_lineEdits.at(5)->text());
        temp.setReco(_lineEdits.at(6)->text());
        temp.setDiff(_lineEdits.at(7)->text());
        temp.setEpoque(_lineEdits.at(8)->text());
        temp.setDepart(_lineEdits.at(9)->text());
        temp.setArrive(_lineEdits.at(10)->text());
        temp.setCarte(_lineEdits.at(11)->text());
        temp.setCarroyage(_lineEdits.at(12)->text());
        temp.setnomCarte(_lineEdits.at(13)->text());
        temp.setAcces(_lineEdits.at(14)->text());
        temp.setParking(_lineEdits.at(15)->text());
        temp.setChemin(_lineEdits.at(16)->text());
        temp.setTerrain(_lineEdits.at(17)->text());
        temp.setMateriel(_lineEdits.at(18)->text());
        _rand->append(temp);
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

void AddRando::abort()
{
    close();
}

QStringList AddRando::verif()
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
    if((t.size()<5) || (t.size()>100))
    {
        l.append("La situation doit contenir au minimum 5 caractères et au maximum 100 caractères.");
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
    if((t.size()<5) || (t.size()>500))
    {
        l.append("Le prelude doit contenir au minimum 5 caractères et au maximum 500 caractères.");
        _lineEdits.at(2)->setStyleSheet("background-color : #FFC0C0;");
    }
    else
    {
        _lineEdits.at(2)->setStyleSheet("background-color : white;");
        if((t.contains('<')) || (t.contains('>')))
        {
            l.append("Les chevrons '<' '>' sont interdits.");
            _lineEdits.at(2)->setStyleSheet("background-color : #FFC0C0;");
        }
        else
            _lineEdits.at(2)->setStyleSheet("background-color : white;");
    }



    t = _lineEdits.at(3)->text();
    if((t.size()<5) || (t.size()>2000))
    {
        l.append("La description générale doit contenir au minimum 5 caractères et au maximum 2000 caractères.");
        _lineEdits.at(3)->setStyleSheet("background-color : #FFC0C0;");
    }
    else
    {
        _lineEdits.at(3)->setStyleSheet("background-color : white;");
        if((t.contains('<')) || (t.contains('>')))
        {
            l.append("Les chevrons '<' '>' sont interdits.");
            _lineEdits.at(3)->setStyleSheet("background-color : #FFC0C0;");
        }
        else
            _lineEdits.at(3)->setStyleSheet("background-color : white;");
    }



    t = _lineEdits.at(4)->text();
    if((t.size()<5) || (t.size()>2000))
    {
        l.append("La description culturelle doit contenir au minimum 5 caractères et au maximum 2000 caractères.");
        _lineEdits.at(4)->setStyleSheet("background-color : #FFC0C0;");
    }
    else
    {
        _lineEdits.at(4)->setStyleSheet("background-color : white;");
        if((t.contains('<')) || (t.contains('>')))
        {
            l.append("Les chevrons '<' '>' sont interdits.");
            _lineEdits.at(4)->setStyleSheet("background-color : #FFC0C0;");
        }
        else
            _lineEdits.at(4)->setStyleSheet("background-color : white;");
    }



    t = _lineEdits.at(5)->text();
    if((t.size()<5) || (t.size()>200))
    {
        l.append("Les informations doivent contenir au minimum 5 caractères et au maximum 2000 caractères.");
        _lineEdits.at(5)->setStyleSheet("background-color : #FFC0C0;");
    }
    else
    {
        _lineEdits.at(5)->setStyleSheet("background-color : white;");
        if((t.contains('<')) || (t.contains('>')))
        {
            l.append("Les chevrons '<' '>' sont interdits.");
            _lineEdits.at(5)->setStyleSheet("background-color : #FFC0C0;");
        }
        else
            _lineEdits.at(5)->setStyleSheet("background-color : white;");
    }



    t = _lineEdits.at(6)->text();
    if((t.size()<5) || (t.size()>200))
    {
        l.append("Les recommandations doivent contenir au minimum 5 caractères et au maximum 2000 caractères.");
        _lineEdits.at(6)->setStyleSheet("background-color : #FFC0C0;");
    }
    else
    {
        _lineEdits.at(6)->setStyleSheet("background-color : white;");
        if((t.contains('<')) || (t.contains('>')))
        {
            l.append("Les chevrons '<' '>' sont interdits.");
            _lineEdits.at(6)->setStyleSheet("background-color : #FFC0C0;");
        }
        else
            _lineEdits.at(6)->setStyleSheet("background-color : white;");
    }



    t = _lineEdits.at(7)->text();
    if((t!="Facile") && (t!="Moyenne") && (t!="Difficile"))
    {
        l.append("Les différentes difficultés sont : 'Facile', 'Moyenne', 'Difficile'. Attention respecter la casse.");
        _lineEdits.at(7)->setStyleSheet("background-color : #FFC0C0;");
    }
    else
        _lineEdits.at(7)->setStyleSheet("background-color : white;");



    t = _lineEdits.at(8)->text();
    QStringList temp = t.split(' ');
    for(int i = 0; i<temp.size(); i++)
    {
        if((temp[i]!="Automne") && (temp[i]!="Hiver") && (temp[i]!="Pringtemps") && (temp[i]!="Ete"))
        {
            l.append("Les différentes époques sont : 'Automne', 'Hiver', 'Pringtemps', 'Ete'. Attention a la casse.");
            _lineEdits.at(8)->setStyleSheet("background-color : #FFC0C0;");
        }
        else
        {
            _lineEdits.at(8)->setStyleSheet("background-color : white;");
            for(int j=0; j<i; j++)
                if(temp[i]==temp[j])
                {
                    l.append("Il ne peut y avoir deux fois la même époque.");
                    _lineEdits.at(8)->setStyleSheet("background-color : #FFC0C0;");
                }
                else
                    _lineEdits.at(8)->setStyleSheet("background-color : white;");
        }
    }



    t = _lineEdits.at(9)->text();
    if((t.size()<3) || (t.size()>70))
    {
        l.append("Le départ doit contenir au minimum 3 caractères et au maximum 70 caractères.");
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



    t = _lineEdits.at(10)->text();
    if((t.size()<3) || (t.size()>70))
    {
        l.append("L'arrivé doit contenir au minimum 3 caractères et au maximum 70 caractères.");
        _lineEdits.at(10)->setStyleSheet("background-color : #FFC0C0;");
    }
    else
    {
        _lineEdits.at(10)->setStyleSheet("background-color : white;");
        if((t.contains('<')) || (t.contains('>')))
        {
            l.append("Les chevrons '<' '>' sont interdits.");
            _lineEdits.at(10)->setStyleSheet("background-color : #FFC0C0;");
        }
        else
            _lineEdits.at(10)->setStyleSheet("background-color : white;");
    }



    t = _lineEdits.at(11)->text();
    if((t.size()<5) || (t.size()>70))
    {
        l.append("La carte doit contenir au minimum 5 caractères et au maximum 70 caractères.");
        _lineEdits.at(11)->setStyleSheet("background-color : #FFC0C0;");
    }
    else
    {
        _lineEdits.at(11)->setStyleSheet("background-color : white;");
        if((t.contains('<')) || (t.contains('>')))
        {
            l.append("Les chevrons '<' '>' sont interdits.");
            _lineEdits.at(11)->setStyleSheet("background-color : #FFC0C0;");
        }
        else
            _lineEdits.at(11)->setStyleSheet("background-color : white;");
    }



    t = _lineEdits.at(12)->text();
    if(!t.contains(QRegExp("[1-9][0-9]{3}[A-Z]{2}")))
    {
        l.append("Le carroyage est de type : [1-9][0-9]{3}[A-Z]{2}.");
        _lineEdits.at(12)->setStyleSheet("background-color : #FFC0C0;");
    }
    else
    {
        _lineEdits.at(12)->setStyleSheet("background-color : white;");
        if((t.contains('<')) || (t.contains('>')))
        {
            l.append("Les chevrons '<' '>' sont interdits.");
            _lineEdits.at(12)->setStyleSheet("background-color : #FFC0C0;");
        }
        else
            _lineEdits.at(12)->setStyleSheet("background-color : white;");
    }



    t = _lineEdits.at(13)->text();
    if((t.size()<5) || (t.size()>70))
    {
        l.append("Le nom de la carte doit contenir au minimum 5 caractères et au maximum 70 caractères.");
        _lineEdits.at(13)->setStyleSheet("background-color : #FFC0C0;");
    }
    else
    {
        _lineEdits.at(13)->setStyleSheet("background-color : white;");
        if((t.contains('<')) || (t.contains('>')))
        {
            l.append("Les chevrons '<' '>' sont interdits.");
            _lineEdits.at(13)->setStyleSheet("background-color : #FFC0C0;");
        }
        else
            _lineEdits.at(13)->setStyleSheet("background-color : white;");
    }



    t = _lineEdits.at(14)->text();
    if((t.size()<5) || (t.size()>200))
    {
        l.append("L'accés doit contenir au minimum 5 caractères et au maximum 70 caractères.");
        _lineEdits.at(14)->setStyleSheet("background-color : #FFC0C0;");
    }
    else
    {
        _lineEdits.at(14)->setStyleSheet("background-color : white;");
        if((t.contains('<')) || (t.contains('>')))
        {
            l.append("Les chevrons '<' '>' sont interdits.");
            _lineEdits.at(14)->setStyleSheet("background-color : #FFC0C0;");
        }
        else
            _lineEdits.at(14)->setStyleSheet("background-color : white;");
    }



    t = _lineEdits.at(15)->text();
    if((t.size()<5) || (t.size()>200))
    {
        l.append("Le parking doit contenir au minimum 5 caractères et au maximum 70 caractères.");
        _lineEdits.at(15)->setStyleSheet("background-color : #FFC0C0;");
    }
    else
    {
        _lineEdits.at(15)->setStyleSheet("background-color : white;");
        if((t.contains('<')) || (t.contains('>')))
        {
            l.append("Les chevrons '<' '>' sont interdits.");
            _lineEdits.at(15)->setStyleSheet("background-color : #FFC0C0;");
        }
        else
            _lineEdits.at(15)->setStyleSheet("background-color : white;");
    }



    t = _lineEdits.at(16)->text();
    temp = t.split(' ');
    for(int i = 0; i<temp.size(); i++)
    {
        if((temp[i]!="Goudronné") && (temp[i]!="Terre") && (temp[i]!="Balisé") && (temp[i]!="Cairne") && (temp[i]!="HorsSentier"))
        {
            l.append("Les différents types de chemin sont : 'Goudronné', 'Terre', 'Balise', 'Cairne', 'HorsSentier'. Attention a la casse.");
            _lineEdits.at(16)->setStyleSheet("background-color : #FFC0C0;");
        }
        else
        {
            _lineEdits.at(17)->setStyleSheet("background-color : white;");
            for(int j=0; j<i; j++)
                if(temp[i]==temp[j])
                {
                    l.append("Il ne peut y avoir deux fois la même époque.");
                    _lineEdits.at(16)->setStyleSheet("background-color : #FFC0C0;");
                }
                else
                    _lineEdits.at(17)->setStyleSheet("background-color : white;");
        }
    }



    t = _lineEdits.at(17)->text();
    temp = t.split(' ');
    for(int i = 0; i<temp.size(); i++)
    {
        if((temp[i]!="Agricole") && (temp[i]!="Herbe") && (temp[i]!="Eboulis") && (temp[i]!="Urbaine"))
        {
            l.append("Les différents types de terrain sont : 'Agricole', 'Herbe', 'Eboulis', 'Urbaine'. Attention a la casse.");
            _lineEdits.at(17)->setStyleSheet("background-color : #FFC0C0;");
        }
        else
        {
            _lineEdits.at(17)->setStyleSheet("background-color : white;");
            for(int j=0; j<i; j++)
                if(temp[i]==temp[j])
                {
                    l.append("Il ne peut y avoir deux fois la même époque.");
                    _lineEdits.at(17)->setStyleSheet("background-color : #FFC0C0;");
                }
                else
                    _lineEdits.at(17)->setStyleSheet("background-color : white;");
        }
    }



    t = _lineEdits.at(18)->text();
    if((t.size()<5) || (t.size()>200))
    {
        l.append("Le Matériel doit contenir au minimum 5 caractères et au maximum 70 caractères.");
        _lineEdits.at(18)->setStyleSheet("background-color : #FFC0C0;");
    }
    else
    {
        _lineEdits.at(18)->setStyleSheet("background-color : white;");
        if((t.contains('<')) || (t.contains('>')))
        {
            l.append("Les chevrons '<' '>' sont interdits.");
            _lineEdits.at(18)->setStyleSheet("background-color : #FFC0C0;");
        }
        else
            _lineEdits.at(18)->setStyleSheet("background-color : white;");
    }



    return l;
}
