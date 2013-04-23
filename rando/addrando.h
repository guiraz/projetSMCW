#ifndef ADDRANDO_H
#define ADDRANDO_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QFormLayout>
#include <QLabel>
#include <QComboBox>
#include <QVector>
#include <iostream>
#include <QScrollArea>
#include <QFile>

#include "randonnee.h"

class AddRando : public QDialog
{
    Q_OBJECT
public:
    explicit AddRando(QVector<Randonnee> * rand ,QWidget *parent = 0);
    ~AddRando();
    
private:

    QVector<Randonnee> * _rand;

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

#endif // ADDRANDO_H
