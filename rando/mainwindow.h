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
#include <iostream>

#include "addrando.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private :
    QPushButton * _buttonQuit, * _buttonAddRando, * _buttonAddEtape, * _buttonDelRando, *_buttonDelEtape;
    QComboBox * _comboListRando;
    QTextEdit * _textRando;
    QLabel * _labelComboBox;
    QWidget * _widgetBouton;
    QVBoxLayout * _vLayout;
    QString * _currentRando;


private slots:
    void quit();
    void addRando();
    void addEtape();
    void delRando();
    void delEtape();
    void comboBoxChanged(QString text);

protected:
    void resizeEvent ( QResizeEvent * event );
};

#endif // MAINWINDOW_H
