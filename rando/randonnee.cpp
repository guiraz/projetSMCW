#include "randonnee.h"

Randonnee::Randonnee()
{
    _nom = "";
    _situation = "";
    _prelude = "";
    _descGen = "";
    _descCult = "";
    _infos = "";
    _reco = "";
    _diff = "";
    _epo = "";
    _depart = "";
    _arrive = "";
    _nomCarte = "";
    _carroyage = "";
    _carte = "";
    _acces = "";
    _parking = "";
    _terrain = "";
    _chemin = "";
    _materiel = "";
}

Randonnee::~Randonnee()
{
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

void Randonnee::setReco(QString reco)
{
    _reco = reco;
}

void Randonnee::setDepart(QString depart)
{
    _depart = depart;
}

void Randonnee::setArrive(QString arrive)
{
    _arrive = arrive;
}

void Randonnee::setDiff(QString diff)
{
    _diff = diff;
}

void Randonnee::setEpoque(QString epoque)
{
        _epo = epoque;
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

void Randonnee::setTerrain(QString terrain)
{
    _terrain = terrain;
}

void Randonnee::setChemin(QString chemin)
{
    _chemin = chemin;
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

QString Randonnee::getReco()
{
    return _reco;
}

QString Randonnee::getDepart()
{
    return _depart;
}

QString Randonnee::getArrive()
{
    return _arrive;
}

QString Randonnee::getDiff()
{
    return _diff;
}

QString Randonnee::getEpoque()
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

QString Randonnee::getTerrain()
{
    return _terrain;
}

QString Randonnee::getChemin()
{
    return _chemin;
}

QString Randonnee::getMateriel()
{
    return _materiel;
}
