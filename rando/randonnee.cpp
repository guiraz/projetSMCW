#include "randonnee.h"

Randonnee::Randonnee()
{
    _epo = new Epoque[4];
    _terrain = new TypeTerrain[4];
    _chemin = new TypeChemin[5];
    _nom = "";
}

Randonnee::~Randonnee()
{
    delete _epo;
    delete _terrain;
    delete _chemin;
}

//Introduction
void Randonnee::setNom(QString nom)
{
    _nom = nom;
}

void Randonnee::setSituation(QString situation)
{
    _situation = situation;
}

void Randonnee::setPrelude(QString prelude)
{
    _prelude = prelude;
}

void Randonnee::setDescGen(QString desc)
{
    _descGen = desc;
}

//Thematique Culturelle
void Randonnee::setDescCult(QString desc)
{
    _descCult = desc;
}

//Fiche Technique
void Randonnee::setInfos(QString infos)
{
    _infos = infos;
}

void Randonnee::setDepart(QString depart)
{
    _depart = depart;
}

void Randonnee::setArrive(QString arrive)
{
    _arrive = arrive;
}

void Randonnee::setDiff(Difficulte diff)
{
    _diff = diff;
}

void Randonnee::setEpoque(Epoque * epoque)
{
    for(int i=0; i<4; i++)
        _epo[i] = epoque[i];
}

//Fiche Informatives
void Randonnee::setnomCarte(QString nomCarte)
{
    _nomCarte = nomCarte;
}

void Randonnee::setCarroyage(QString carroyage)
{
    _carroyage = carroyage;
}

void Randonnee::setCarte(QString carte)
{
    _carte = carte;
}

void Randonnee::setAcces(QString acces)
{
    _acces = acces;
}

void Randonnee::setParking(QString parking)
{
    _parking = parking;
}

void Randonnee::setTerrain(TypeTerrain * terrain)
{
    for(int i=0; i<4; i++)
        _terrain[i] = terrain[i];
}

void Randonnee::setChemin(TypeChemin * chemin)
{
    for(int i=0; i<5; i++)
        _chemin[i] = chemin[i];
}

void Randonnee::setMateriel(QString materiel)
{
    _materiel = materiel;
}



//Introduction
QString Randonnee::getNom()
{
    return _nom;
}

QString Randonnee::getSituation()
{
    return _situation;
}

QString Randonnee::getPrelude()
{
    return _prelude;
}

QString Randonnee::getDescGen()
{
    return _descGen;
}

//Thematique Culturelle
QString Randonnee::getDescCult()
{
    return _descCult;
}

//Fiche Technique
QString Randonnee::getInfos()
{
    return _infos;
}

QString Randonnee::getDepart()
{
    return _depart;
}

QString Randonnee::getArrive()
{
    return _arrive;
}

Difficulte Randonnee::getDiff()
{
    return _diff;
}

Epoque* Randonnee::getEpoque()
{
    return _epo;
}

//Fiche Informatives
QString Randonnee::getnomCarte()
{
    return _nomCarte;
}

QString Randonnee::getCarroyage()
{
    return _carroyage;
}

QString Randonnee::getCarte()
{
    return _carte;
}

QString Randonnee::getAcces()
{
    return _acces;
}

QString Randonnee::getParking()
{
    return _parking;
}

TypeTerrain* Randonnee::getTerrain()
{
    return _terrain;
}

TypeChemin* Randonnee::getChemin()
{
    return _chemin;
}

QString Randonnee::getMateriel()
{
    return _materiel;
}
