#ifndef ADDETAPE_H
#define ADDETAPE_H

#include <QDialog>
#include <QFile>
#include <QGridLayout>
#include <QPushButton>
#include <QScrollArea>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>

#include "randonnee.h"
#include "etape.h"

class AddEtape : public QDialog
{
    Q_OBJECT
public:
    explicit AddEtape(Etape * etape,QWidget *parent = 0);
    ~AddEtape();
    
private:
    Etape * _etape;

    QPushButton *_buttonOK, *_buttonAbort;

    QGridLayout *_layout;
    QScrollArea * _scrollArea;

    QVector<QLineEdit *> _lineEdits;
    QVector<QLabel *> _labels;

    QStringList verif();

private slots:
    void ok();
    void abort();
    
};

#endif // ADDETAPE_H
