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
    QObject::connect(_combo, SIGNAL(currentIndexChanged(int)), this, SLOT(comboBoxChanged(int)));
    _vLayout2->addWidget(_combo);

    _buttonAddRando = new QPushButton("Ajouter Randonnée");
    QObject::connect(_buttonAddRando, SIGNAL(clicked()), this, SLOT(addRando()));
    _vLayout1->addWidget(_buttonAddRando);

    _buttonAddEtape = new QPushButton("Ajouter Etape");
    QObject::connect(_buttonAddEtape, SIGNAL(clicked()), this, SLOT(addEtape()));
    _vLayout1->addWidget(_buttonAddEtape);

    _buttonQuit = new QPushButton("Quitter");
    QObject::connect(_buttonQuit, SIGNAL(clicked()), this, SLOT(quit()));
    _vLayout1->addWidget(_buttonQuit);

    this->setMinimumSize(640,480);

    _rand.clear();
    _rand.reserve(15);

    loadRandoFile();

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
    {
        _combo->addItem(_rand[i].getNom());
    }

    if(_rand.size()>0)
    {
        _buttonAddEtape->setEnabled(true);
        _currentRando = 0;
        _combo->setCurrentIndex(_currentRando);
        _textRando->setText(loadXMLFile(_rand[_currentRando].getNom() + ".xml"));
    }
    else
    {
        _buttonAddEtape->setDisabled(true);
    }
}



void MainWindow::writeXML(int index)
{
    if(index == -1)
        return;

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



QString MainWindow::loadXMLFile(QString path)
{
    QFile xml_doc(path);
    xml_doc.open(QIODevice::ReadWrite);

    QString s;

    QTextStream stream(&xml_doc);

    s = stream.readAll();

    xml_doc.close();

    return s;
}



void MainWindow::loadRandoFile()
{
    QDirIterator dir(".");
    while(dir.hasNext())
    {
        QString fileName = dir.next();
        if(fileName.contains(QRegExp(".+\\.xml")))
        {
            QFile file(fileName);
            if(file.open(QIODevice::ReadWrite))
            {
               Randonnee temp;
               QDomDocument doc("xml_file");
               doc.setContent(&file);
               QDomElement docElement = doc.documentElement();
               QDomNode n = docElement.firstChild();
               while(!n.isNull())
               {
                    QDomElement e = n.toElement();
                    if(e.tagName()=="introduction")
                    {
                        QDomNode introNode = e.firstChild();
                        while(!introNode.isNull())
                        {
                            QDomElement introElement = introNode.toElement();

                            if(introElement.tagName()=="nom")
                                temp.setNom(introElement.text());
                            if(introElement.tagName()=="situation")
                                temp.setSituation(introElement.text());
                            if(introElement.tagName()=="prelude")
                                temp.setPrelude(introElement.text());
                            if(introElement.tagName()=="description_generale")
                                temp.setDescGen(introElement.text());

                            introNode = introNode.nextSibling();
                        }
                    }
                    if(e.tagName()=="partie")
                    {
                        if(e.attribute("titre") == "THEMATIQUE CULTURELLE")
                        {
                            QDomNode partieNode = e.firstChild();
                            while(!partieNode.isNull())
                            {
                                QDomElement partieElement = partieNode.toElement();

                                if(partieElement.tagName()=="description_culturel")
                                    temp.setDescCult(partieElement.text());

                                partieNode = partieNode.nextSibling();
                            }
                        }
                        if(e.attribute("titre") == "DESCRIPTION")
                        {
                            QDomNode partieNode = e.firstChild();
                            while(!partieNode.isNull())
                            {
                                QDomElement partieElement = partieNode.toElement();

                                if(partieElement.tagName()=="etape")
                                {
                                    Etape et;
                                    et.setDescEtape(partieElement.firstChildElement().text());
                                    et.setId(partieElement.attribute("id"));
                                    et.setNom(partieElement.attribute("nom"));
                                    et.setDesc(partieElement.attribute("description"));
                                    et.setDistance(partieElement.attribute("distance_a_parcourir"));
                                    et.setDuree(partieElement.attribute("duree_estime"));
                                    et.setAlt(partieElement.attribute("altitude"));
                                    et.setDeniv(partieElement.attribute("denivele"));
                                    et.setLat(partieElement.attribute("lat"));
                                    et.setLong(partieElement.attribute("long"));
                                    et.setImage(partieElement.attribute("src"));
                                    temp.addEtape(et);
                                }

                                partieNode = partieNode.nextSibling();
                            }
                        }
                    }
                    if(e.tagName()=="fichetechnique")
                    {
                        QDomNode ftNode = e.firstChild();
                        while(!ftNode.isNull())
                        {
                            QDomElement ftElement = ftNode.toElement();

                            if(ftElement.tagName()=="infos")
                                temp.setInfos(ftElement.text());
                            if(ftElement.tagName()=="recommandations")
                                temp.setReco(ftElement.text());
                            if(ftElement.tagName()=="difficulte")
                                temp.setDiff(ftElement.text());
                            if(ftElement.tagName()=="epoque")
                                temp.setEpoque(ftElement.text());
                            if(ftElement.tagName()=="depart")
                                temp.setDepart(ftElement.text());
                            if(ftElement.tagName()=="arrivee")
                                temp.setArrive(ftElement.text());

                            ftNode = ftNode.nextSibling();
                        }
                    }
                    if(e.tagName()=="ficheinfo")
                    {
                        QDomNode fiNode = e.firstChild();
                        while(!fiNode.isNull())
                        {
                            QDomElement fiElement = fiNode.toElement();

                            if(fiElement.tagName()=="nom")
                                temp.setnomCarte(fiElement.text());
                            if(fiElement.tagName()=="acces")
                                temp.setAcces(fiElement.text());
                            if(fiElement.tagName()=="parking")
                                temp.setParking(fiElement.text());
                            if(fiElement.tagName()=="carte")
                                temp.setCarte(fiElement.text());
                            if(fiElement.tagName()=="carroyage")
                                temp.setCarroyage(fiElement.text());
                            if(fiElement.tagName()=="typedechemin")
                                temp.setChemin(fiElement.text());
                            if(fiElement.tagName()=="typedeterrain")
                                temp.setTerrain(fiElement.text());
                            if(fiElement.tagName()=="materiel")
                                temp.setMateriel(fiElement.text());

                            fiNode = fiNode.nextSibling();
                        }
                    }
                    n = n.nextSibling();
               }
               _rand.append(temp);
            }
        }
    }

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
    Etape temp;
    AddEtape * ae;
    ae = new AddEtape(&temp, this);
    ae->exec();
    delete ae;

    if(temp.getNom().size()!=0)
    {
        int id = _rand[_currentRando].getEtapes()->size()+1;
        temp.setId(QString::number(id));
        _rand[_currentRando].addEtape(temp);
        writeXML(_rand.size()-1);
    }

    update();
}



void MainWindow::comboBoxChanged(int index)
{
    _currentRando = index;
    if(_currentRando >=0)
        _textRando->setText(loadXMLFile(_rand[_currentRando].getNom() + ".xml"));
}

void MainWindow::afficheRando(int index)
{
    std::cout<<_rand[index].getNom().toStdString()<<std::endl;
    for(int i=0; i<_rand[index].getEtapes()->size(); i++)
        std::cout<<(_rand[index].getEtapes())->operator [](i).getNom().toStdString()<<std::endl;
}


void MainWindow::resizeEvent(QResizeEvent * event)
{
    QWidget::resizeEvent(event);
    QSize s(event->size());
    _textRando->setGeometry(3,3,(s.width()-9)*0.7, s.height()-6);
    _widgetComboLabel->setGeometry((s.width()-9)*0.7+6,3,(s.width()-9)*0.3,(s.height()-9)*0.3);
    _widgetButton->setGeometry((s.width()-9)*0.7+6,(s.height()-9)*0.3+6,(s.width()-9)*0.3,(s.height()-9)*0.7);
}
