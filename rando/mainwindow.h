#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <QTextEdit>
#include <QResizeEvent>
#include <QLayout>
#include <QVector>
#include <QLabel>
#include <QComboBox>
#include <QtXml>
#include <QXmlQuery>

#include "addrando.h"
#include "addetape.h"
#include "randonnee.h"
#include "etape.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private :
    QTextEdit * _textRando;
    QWidget * _widgetButton, * _widgetComboLabel;
    QVBoxLayout * _vLayout1,* _vLayout2;
    QLabel * _label;
    QComboBox * _combo;
    QPushButton * _buttonQuit, * _buttonAddRando, * _buttonAddEtape, * _buttonDelRando, *_buttonTransformation;
    QVector<Randonnee> _rand;
    int _currentRando;

    void update();
    void writeXML(int index);
    QString loadXMLFile(QString path);
    void loadRandoFile();


private slots:
    void quit();
    void addRando();
    void addEtape();
    void delRando();
    void trans();
    void comboBoxChanged(int text);
    void afficheRando(int index);

protected:
    void resizeEvent ( QResizeEvent * event );
};

#endif // MAINWINDOW_H
