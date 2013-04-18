#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <QComboBox>
#include <QTextEdit>
#include <QLabel>
#include <QLayout>
#include <QResizeEvent>
#include <QVector>
#include <iostream>

#include "addrando.h"
#include "randonnee.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private :
    QTextEdit _textRando;
    QWidget _widgetBouton;
    int _currentRando;

    QVector<Randonnee> _randonnees;


private slots:
    void quit();
    void addRando();
    void addEtape();
    void delRando();
    void delEtape();
    void comboBoxChanged(int text);

protected:
    void resizeEvent ( QResizeEvent * event );
};

#endif // MAINWINDOW_H
