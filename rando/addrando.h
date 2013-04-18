#ifndef ADDRANDO_H
#define ADDRANDO_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>

class AddRando : public QDialog
{
    Q_OBJECT
public:
    explicit AddRando(QString * current, QWidget *parent = 0);
    ~AddRando();
    
private:
    QLineEdit * _lineEdit;
    QString * _nomRando;
    QPushButton * _buttonOK, * _buttonAbort;

private slots:
    void ok();
    void abort();
    
};

#endif // ADDRANDO_H
