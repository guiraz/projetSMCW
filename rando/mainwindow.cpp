#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    _textRando = new QTextEdit(this);
    _textRando->setReadOnly(true);
    _widgetButton = new QWidget(this);
    _widgetButton->setStyleSheet(".QWidget{background-color : grey;}");
    _vLayout1 = new QVBoxLayout();
    _widgetButton->setLayout(_vLayout1);
    _widgetComboLabel = new QWidget(this);
    _widgetComboLabel->setStyleSheet(".QWidget{background-color : grey;}");
    _vLayout2 = new QVBoxLayout();
    _widgetComboLabel->setLayout(_vLayout2);

    _label = new QLabel("Choisir une randonnée :");
    _vLayout2->addWidget(_label);
    _label->setStyleSheet("color : white;");

    _combo = new QComboBox();
    _vLayout2->addWidget(_combo);

    _buttonAddRando = new QPushButton("Ajouter Randonnée");
    QObject::connect(_buttonAddRando, SIGNAL(clicked()), this, SLOT(addRando()));
    _vLayout1->addWidget(_buttonAddRando);

    _buttonQuit = new QPushButton("Quitter");
    QObject::connect(_buttonQuit, SIGNAL(clicked()), this, SLOT(quit()));
    _vLayout1->addWidget(_buttonQuit);

    this->setMinimumSize(640,480);

    _rand.clear();
    _rand.reserve(15);
    loadXMLFile();
    update();
}

MainWindow::~MainWindow()
{
    delete _textRando;

    delete _buttonQuit;
    delete _buttonAddRando;

    delete _vLayout1;
    delete _widgetButton;

    delete _vLayout2;
    delete _widgetComboLabel;
}

void MainWindow::update()
{
    _combo->clear();

    for(int i=0; i<_rand.size(); i++)
        _combo->addItem(_rand[i].getNom());

    _combo->setCurrentIndex(_currentRando);
}

void MainWindow::writeXML(int index)
{

    QString name = _rand[index].getNom();
    QDomDocument *dom = new QDomDocument(name);

    if(QFile::exists(name + ".xml"))
        QFile::remove(name + ".xml");

    QFile xml_doc(name + ".xml");
    xml_doc.open(QIODevice::ReadWrite);

    dom->setContent(&xml_doc);

    QDomElement randonnee = dom->createElement("randonnee");
    QDomElement introduction = dom->createElement("introduction");
    introduction.setAttribute("titre", "PAS DE CIRCUIT");
    QDomElement nom = dom->createElement("nom");
    QDomElement situation = dom->createElement("situation");
    QDomElement prelude = dom->createElement("prelude");
    QDomElement desc_gen = dom->createElement("description_generale");
    QDomElement partieCult = dom->createElement("partie");
    partieCult.setAttribute("titre", "THEMATIQUE CULTURELLE");
    QDomElement desc_cult = dom->createElement("description_culturel");
    QDomElement fiche_tech = dom->createElement("fichetechnique");
    QDomElement fiche_info = dom->createElement("ficheinfo");
    QDomElement info = dom->createElement("infos");
    QDomElement reco = dom->createElement("recommandations");
    QDomElement diff = dom->createElement("difficulte");
    QDomElement epoque = dom->createElement("epoque");
    QDomElement depart = dom->createElement("depart");
    QDomElement arrivee = dom->createElement("arrivee");
    QDomElement nomCarte = dom->createElement("nom");
    QDomElement acces = dom->createElement("acces");
    QDomElement parking = dom->createElement("parking");
    QDomElement carte = dom->createElement("carte");
    QDomElement carroyage = dom->createElement("carroyage");
    QDomElement chemin = dom->createElement("typedechemin");
    QDomElement terrain = dom->createElement("typedeterrain");
    QDomElement materiel = dom->createElement("materiel");


    QDomText nomT = dom->createTextNode(_rand[index].getNom());
    QDomText situationT = dom->createTextNode(_rand[index].getSituation());
    QDomText preludeT = dom->createTextNode(_rand[index].getPrelude());
    QDomText desc_genT = dom->createTextNode(_rand[index].getDescGen());
    QDomText desc_cultT = dom->createTextNode(_rand[index].getDescCult());
    QDomText infoT = dom->createTextNode(_rand[index].getInfos());
    QDomText recoT = dom->createTextNode(_rand[index].getReco());
    QDomText diffT = dom->createTextNode(_rand[index].getDiff());
    QDomText epoqueT = dom->createTextNode(_rand[index].getEpoque());
    QDomText departT = dom->createTextNode(_rand[index].getDepart());
    QDomText arriveeT = dom->createTextNode(_rand[index].getArrive());
    QDomText nomCarteT = dom->createTextNode(_rand[index].getnomCarte());
    QDomText accesT = dom->createTextNode(_rand[index].getAcces());
    QDomText parkingT = dom->createTextNode(_rand[index].getParking());
    QDomText carteT = dom->createTextNode(_rand[index].getCarte());
    QDomText carroyageT = dom->createTextNode(_rand[index].getCarroyage());
    QDomText cheminT = dom->createTextNode(_rand[index].getChemin());
    QDomText terrainT = dom->createTextNode(_rand[index].getTerrain());
    QDomText materielT = dom->createTextNode(_rand[index].getMateriel());

    nom.appendChild(nomT);
    situation.appendChild(situationT);
    prelude.appendChild(preludeT);
    desc_gen.appendChild(desc_genT);
    desc_cult.appendChild(desc_cultT);
    info.appendChild(infoT);
    reco.appendChild(recoT);
    diff.appendChild(diffT);
    epoque.appendChild(epoqueT);
    depart.appendChild(departT);
    arrivee.appendChild(arriveeT);
    nomCarte.appendChild(nomCarteT);
    acces.appendChild(accesT);
    parking.appendChild(parkingT);
    carte.appendChild(carteT);
    carroyage.appendChild(carroyageT);
    chemin.appendChild(cheminT);
    terrain.appendChild(terrainT);
    materiel.appendChild(materielT);

    introduction.appendChild(nom);
    introduction.appendChild(situation);
    introduction.appendChild(prelude);
    introduction.appendChild(desc_gen);

    partieCult.appendChild(desc_cult);

    fiche_tech.appendChild(info);
    fiche_tech.appendChild(reco);
    fiche_tech.appendChild(diff);
    fiche_tech.appendChild(epoque);
    fiche_tech.appendChild(depart);
    fiche_tech.appendChild(arrivee);

    fiche_info.appendChild(nomCarte);
    fiche_info.appendChild(acces);
    fiche_info.appendChild(parking);
    fiche_info.appendChild(carte);
    fiche_info.appendChild(carroyage);
    fiche_info.appendChild(chemin);
    fiche_info.appendChild(terrain);
    fiche_info.appendChild(materiel);

    randonnee.appendChild(introduction);
    randonnee.appendChild(partieCult);
    randonnee.appendChild(fiche_tech);
    randonnee.appendChild(fiche_info);

    dom->appendChild(randonnee);

    QString s = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    s.append(dom->toString());
    QTextStream stream(&xml_doc);
    stream << s;

    xml_doc.close();
}

void MainWindow::loadXMLFile()
{

}

void MainWindow::quit()
{
    if(QMessageBox::warning(this, "Fermeture", "Etes vous sure?", QMessageBox::Ok, QMessageBox::Abort) == QMessageBox::Ok)
        this->close();
}

void MainWindow::addRando()
{
    AddRando * ar;
    ar = new AddRando(&_rand, this);
    ar->exec();
    delete ar;

    writeXML(_rand.size()-1);
    update();
}

void MainWindow::addEtape()
{
}

void MainWindow::delRando()
{
}

void MainWindow::delEtape()
{
}

void MainWindow::comboBoxChanged(int index)
{
    _currentRando = index;
}

void MainWindow::resizeEvent(QResizeEvent * event)
{
    QWidget::resizeEvent(event);
    QSize s(event->size());
    _textRando->setGeometry(3,3,(s.width()-9)*0.7, s.height()-6);
    _widgetComboLabel->setGeometry((s.width()-9)*0.7+6,3,(s.width()-9)*0.3,(s.height()-9)*0.3);
    _widgetButton->setGeometry((s.width()-9)*0.7+6,(s.height()-9)*0.3+6,(s.width()-9)*0.3,(s.height()-9)*0.7);
}
