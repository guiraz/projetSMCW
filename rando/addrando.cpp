#include "addrando.h"

AddRando::AddRando(QWidget *parent) :
    QDialog(parent)
{
    this->setFixedSize(1024,768);
    this->setWindowTitle("Edition de la randonnée");
    this->setStyleSheet(".AddRando{background-color : grey;}");

    ////////////////
    //INTRODUCTION//
    ////////////////

    _labelNom.setText("Nom de la randonnée :");
    _labelSituation.setText("Situation de la randonnée :");
    _labelPrelude.setText("Prelude de la randonnée :");
    _labelDescGen.setText("Description génèrale de la randonnée :");

    _vLayout1.addWidget(&_labelNom);
    _vLayout1.addWidget(&_lineNom);
    _vLayout1.addWidget(&_labelSituation);
    _vLayout1.addWidget(&_lineSituation);
    _vLayout1.addWidget(&_labelPrelude);
    _vLayout1.addWidget(&_linePrelude);
    _vLayout1.addWidget(&_labelDescGen);
    _vLayout1.addWidget(&_lineDescGen);

    _intro.setParent(this);
    _intro.setLayout(&_vLayout1);
    _intro.setGeometry(3,3,506,278);
    _intro.setStyleSheet(".QWidget{background-color : black;} QLabel{color : white;}");

    ///////////////////
    //FICHE TECHNIQUE//
    ///////////////////

    _labelInfos.setText("Informations sur la randonnée :");
    _labelDiff.setText("Difficulté :");
    _labelEpoque.setText("Epoques conseillées :");
    _labelDepart.setText("Lieu de départ :");
    _labelArrive.setText("Lieu d'arrivée :");

    _comboDiff.addItem("Facile");
    _comboDiff.addItem("Moyen");
    _comboDiff.addItem("Difficile");

    _comboEpoque1.addItem("None");
    _comboEpoque1.addItem("Automne");
    _comboEpoque1.addItem("Hiver");
    _comboEpoque1.addItem("Pringtemps");
    _comboEpoque1.addItem("Ete");
    _comboEpoque2.addItem("None");
    _comboEpoque2.addItem("Automne");
    _comboEpoque2.addItem("Hiver");
    _comboEpoque2.addItem("Pringtemps");
    _comboEpoque2.addItem("Ete");
    _comboEpoque3.addItem("None");
    _comboEpoque3.addItem("Automne");
    _comboEpoque3.addItem("Hiver");
    _comboEpoque3.addItem("Pringtemps");
    _comboEpoque3.addItem("Ete");
    _comboEpoque4.addItem("None");
    _comboEpoque4.addItem("Automne");
    _comboEpoque4.addItem("Hiver");
    _comboEpoque4.addItem("Pringtemps");
    _comboEpoque4.addItem("Ete");

    _vLayout2.addWidget(&_labelInfos);
    _vLayout2.addWidget(&_lineInfos);
    _vLayout2.addWidget(&_labelDiff);
    _vLayout2.addWidget(&_comboDiff);
    _vLayout2.addWidget(&_labelEpoque);
    _vLayout2.addWidget(&_comboEpoque1);
    _vLayout2.addWidget(&_comboEpoque2);
    _vLayout2.addWidget(&_comboEpoque3);
    _vLayout2.addWidget(&_comboEpoque4);
    _vLayout2.addWidget(&_labelDepart);
    _vLayout2.addWidget(&_lineDepart);
    _vLayout2.addWidget(&_labelArrive);
    _vLayout2.addWidget(&_lineArrive);

    _ficheTech.setParent(this);
    _ficheTech.setLayout(&_vLayout2);
    _ficheTech.setGeometry(3,287,506,478);
    _ficheTech.setStyleSheet(".QWidget{background-color : black;} QLabel{color : white;}");

    _buttonOK.setText("Ok");
    _buttonOK.setParent(this);
    QObject::connect(&_buttonOK, SIGNAL(clicked()), this, SLOT(ok()));

    _buttonAbort.setText("Annuler");
    _buttonAbort.setParent(this);
    QObject::connect(&_buttonAbort, SIGNAL(clicked()), this, SLOT(abort()));
}

AddRando::~AddRando()
{
}

void AddRando::ok()
{
}

void AddRando::abort()
{
    close();
}
