#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    _textRando = new QTextEdit(this);
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
