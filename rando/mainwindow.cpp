#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0,0,640,480);
    this->setMinimumSize(640,480);
    this->setWindowTitle("Randonnée");

    _currentRando = NULL;

    _labelComboBox = new QLabel("Choisir une randonnée :");

    _comboListRando = new QComboBox();
    _comboListRando->setMinimumSize(150, 27);
    QObject::connect(_comboListRando, SIGNAL(currentIndexChanged(QString)), this, SLOT(comboBoxChanged(QString)));

    _textRando = new QTextEdit(this);
    _textRando->setStyleSheet("background-color : black; color : white; font: 70% \"Times New Roman\";");
    _textRando->setReadOnly(true);

    _buttonQuit = new QPushButton("Quitter");
    QObject::connect(_buttonQuit, SIGNAL(clicked()), this, SLOT(quit()));

    _buttonAddRando = new QPushButton("Ajouter randonnée");
    QObject::connect(_buttonAddRando, SIGNAL(clicked()), this, SLOT(addRando()));

    _buttonAddEtape = new QPushButton("Ajouter étape");
    QObject::connect(_buttonAddEtape, SIGNAL(clicked()), this, SLOT(addEtape()));

    _buttonDelRando = new QPushButton("Supprimer randonnée");
    QObject::connect(_buttonDelRando, SIGNAL(clicked()), this, SLOT(delRando()));

    _buttonDelEtape = new QPushButton("Supprimer étape");
    QObject::connect(_buttonDelEtape, SIGNAL(clicked()), this, SLOT(delEtape()));

    _vLayout = new QVBoxLayout();
    _vLayout->addWidget(_labelComboBox, 0, Qt::AlignLeft|Qt::AlignTop);
    _vLayout->addWidget(_comboListRando, 0, Qt::AlignLeft|Qt::AlignTop);
    _vLayout->addWidget(_buttonAddRando, 0, Qt::AlignLeft|Qt::AlignVCenter);
    _vLayout->addWidget(_buttonAddEtape, 0, Qt::AlignLeft|Qt::AlignVCenter);
    _vLayout->addWidget(_buttonDelRando, 0, Qt::AlignLeft|Qt::AlignVCenter);
    _vLayout->addWidget(_buttonDelEtape, 0, Qt::AlignLeft|Qt::AlignVCenter);
    _vLayout->addWidget(_buttonQuit, 0, Qt::AlignRight|Qt::AlignBottom);

    _widgetBouton = new QWidget(this);
    _widgetBouton->setLayout(_vLayout);
}

MainWindow::~MainWindow()
{
    delete _textRando;
    delete _labelComboBox;
    delete _comboListRando;
    delete _buttonQuit;
    delete _buttonAddRando;
    delete _buttonAddEtape;
    delete _buttonDelRando;
    delete _buttonDelEtape;
    delete _widgetBouton;
    delete _currentRando;
}

void MainWindow::quit()
{
    if(QMessageBox::warning(this, "Fermeture", "Etes vous sure?", QMessageBox::Ok, QMessageBox::Abort) == QMessageBox::Ok)
        this->close();
}

void MainWindow::addRando()
{
    QString temp;
    AddRando ar(&temp, this);
    ar.exec();
    if(temp.size()>4)
    {
        _currentRando = new QString(temp);
        _comboListRando->addItem(temp);
        _comboListRando->setCurrentIndex(_comboListRando->findText(temp));
    }
}

void MainWindow::addEtape()
{
}

void MainWindow::delRando()
{
    if(_currentRando->size()>4)
        if(QMessageBox::warning(this, "Suppression", "Etes vous sure de vouloir supprimer " + *_currentRando + "?", QMessageBox::Ok, QMessageBox::Abort) == QMessageBox::Ok)
        {
            _comboListRando->removeItem(_comboListRando->findText(*_currentRando));
            _currentRando = new QString(_comboListRando->currentText());
        }
}

void MainWindow::delEtape()
{
}

void MainWindow::comboBoxChanged(QString text)
{
    * _currentRando = text;
}

void MainWindow::resizeEvent(QResizeEvent * event)
{
    QWidget::resizeEvent(event);
    QSize s(event->size());
    _textRando->setGeometry(3,3,((s.width()/100)*70)-6, s.height()-6);
    _widgetBouton->setGeometry(((s.width()/100)*70)+3,3,((s.width()/100)*30)-6, s.height()-6);
}
