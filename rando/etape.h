#ifndef ETAPE_H
#define ETAPE_H
#include <QString>

class Etape
{
public:
    Etape();

    QString getId();
    QString getNom();
    QString getDesc();
    QString getDistance();
    QString getDuree();
    QString getAlt();
    QString getDeniv();
    QString getLat();
    QString getLong();
    QString getDescEtape();
    QString getImage();

    void setId(QString id);
    void setNom(QString nom);
    void setDesc(QString desc);
    void setDistance(QString distance);
    void setDuree(QString duree);
    void setAlt(QString alt);
    void setDeniv(QString deniv);
    void setLat(QString lat);
    void setLong(QString longi);
    void setDescEtape(QString descEtape);
    void setImage(QString image);


private:
    QString _id;
    QString _nom;
    QString _desc;
    QString _distance;
    QString _duree;
    QString _alt;
    QString _deniv;
    QString _lat;
    QString _long;
    QString _descEtape;
    QString _image;
};

#endif // ETAPE_H
