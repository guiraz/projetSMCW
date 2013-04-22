#ifndef RANDONNEE_H
#define RANDONNEE_H
#include <QString>

class Randonnee
{
public:
    Randonnee();
    ~Randonnee();

    void setNom(QString nom);
    void setSituation(QString situation);
    void setPrelude(QString prelude);
    void setDescGen(QString desc);

    void setDescCult(QString desc);

    void setInfos(QString infos);
    void setReco(QString reco);
    void setDepart(QString depart);
    void setArrive(QString arrive);
    void setDiff(QString diff);
    void setEpoque(QString epoque);

    void setnomCarte(QString nomCarte);
    void setCarroyage(QString carroyage);
    void setCarte(QString carte);
    void setAcces(QString acces);
    void setParking(QString parking);
    void setTerrain(QString terrain);
    void setChemin(QString chemin);
    void setMateriel(QString materiel);

    QString getNom();
    QString getSituation();
    QString getPrelude();
    QString getDescGen();

    QString getDescCult();

    QString getInfos();
    QString getReco();
    QString getDepart();
    QString getArrive();
    QString getDiff();
    QString getEpoque();

    QString getnomCarte();
    QString getCarroyage();
    QString getCarte();
    QString getAcces();
    QString getParking();
    QString getTerrain();
    QString getChemin();
    QString getMateriel();

private:
    QString _nom;
    QString _situation;
    QString _prelude;
    QString _descGen;

    QString _descCult;

    QString _infos;
    QString _reco;
    QString _diff;
    QString _epo;
    QString _depart;
    QString _arrive;

    QString _nomCarte;
    QString _carroyage;
    QString _carte;
    QString _acces;
    QString _parking;
    QString _terrain;
    QString _chemin;
    QString _materiel;
};

#endif // RANDONNEE_H
