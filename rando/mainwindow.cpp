#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
}

MainWindow::~MainWindow()
{
}

void MainWindow::quit()
{
    if(QMessageBox::warning(this, "Fermeture", "Etes vous sure?", QMessageBox::Ok, QMessageBox::Abort) == QMessageBox::Ok)
        this->close();
}

void MainWindow::addRando()
{
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
    _textRando.setGeometry(3,3,((s.width()/100)*70)-6, s.height()-6);
    _widgetBouton.setGeometry(((s.width()/100)*70)+3,3,((s.width()/100)*30)-6, s.height()-6);
}
