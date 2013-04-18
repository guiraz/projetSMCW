#ifndef RANDONNEE_H
#define RANDONNEE_H
#include <QString>

#include "enumeration.h"

class Randonnee
{
public:
    Randonnee();

    void setNom(QString nom);
    void setSituation(QString situation);
    void setPrelude(QString prelude);
    void setDescGen(QString desc);

    void setDescCult(QString desc);

    void setInfos(QString infos);
    void setDepart(QString depart);
    void setArrive(QString arrive);
    void setDiff(Difficulte diff);
    void setEpoque(Epoque * epoque);

    void setnomCarte(QString nomCarte);
    void setCarroyage(QString carroyage);
    void setCarte(QString carte);
    void setAcces(QString acces);
    void setParking(QString parking);
    void setTerrain(TypeTerrain * terrain);
    void setChemin(TypeChemin * chemin);
    void setMateriel(QString materiel);

    QString getNom();
    QString getSituation();
    QString getPrelude();
    QString getDescGen();

    QString getDescCult();

    QString getInfos();
    QString getDepart();
    QString getArrive();
    Difficulte getDiff();
    Epoque* getEpoque();

    QString getnomCarte();
    QString getCarroyage();
    QString getCarte();
    QString getAcces();
    QString getParking();
    TypeTerrain* getTerrain();
    TypeChemin* getChemin();
    QString getMateriel();

private:
    QString _nom;
    QString _situation;
    QString _prelude;
    QString _descGen;

    QString _descCult;

    QString _infos;
    Difficulte _diff;
    Epoque * _epo;
    QString _depart;
    QString _arrive;

    QString _nomCarte;
    QString _carroyage;
    QString _carte;
    QString _acces;
    QString _parking;
    TypeTerrain * _terrain;
    TypeChemin * _chemin;
    QString _materiel;
};

#endif // RANDONNEE_H
