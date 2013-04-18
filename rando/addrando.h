#ifndef ADDRANDO_H
#define ADDRANDO_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <iostream>

#include "randonnee.h"

class AddRando : public QDialog
{
    Q_OBJECT
public:
    explicit AddRando(QWidget *parent = 0);
    ~AddRando();
    
private:

    QPushButton _buttonOK, _buttonAbort;

    QWidget _intro, _themCult, _ficheTech, _ficheInfos;
    QVBoxLayout _vLayout1, _vLayout2, _vLayout3, _vLayout4;

    QLineEdit _lineNom, _lineSituation, _linePrelude, _lineDescGen;
    QLabel _labelNom, _labelSituation, _labelPrelude, _labelDescGen;

    QLabel _labelInfos, _labelDiff, _labelEpoque, _labelDepart, _labelArrive;
    QLineEdit _lineInfos, _lineDepart, _lineArrive;
    QComboBox _comboDiff, _comboEpoque1, _comboEpoque2, _comboEpoque3, _comboEpoque4;


private slots:
    void ok();
    void abort();
    
};

#endif // ADDRANDO_H
