#include "etape.h"

Etape::Etape()
{
}

QString Etape::getId()
{
    return _id;
}

QString Etape::getNom()
{
    return _nom;
}

QString Etape::getDesc()
{
    return _desc;
}

QString Etape::getDistance()
{
    return _distance;
}

QString Etape::getDuree()
{
    return _duree;
}

QString Etape::getAlt()
{
    return _alt;
}

QString Etape::getDeniv()
{
    return _deniv;
}

QString Etape::getLat()
{
    return _lat;
}

QString Etape::getLong()
{
    return _long;
}

QString Etape::getDescEtape()
{
    return _descEtape;
}

QString Etape::getImage()
{
    return _image;
}

void Etape::setId(QString id)
{
    id = _id;
}

void Etape::setNom(QString nom)
{
    _nom = nom;
}

void Etape::setDesc(QString desc)
{
    _desc = desc;
}

void Etape::setDistance(QString distance)
{
    _distance = distance;
}

void Etape::setDuree(QString duree)
{
    _duree = duree;
}

void Etape::setAlt(QString alt)
{
    _alt = alt;
}

void Etape::setDeniv(QString deniv)
{
    _deniv = deniv;
}

void Etape::setLat(QString lat)
{
    _lat = lat;
}

void Etape::setLong(QString longi)
{
    _long = longi;
}

void Etape::setDescEtape(QString descEtape)
{
    _descEtape = descEtape;
}

void Etape::setImage(QString image)
{
    _image = image;
}
