#ifndef QSIGNAL_H
#define QSIGNAL_H
#include <QApplication>
#include <QObject>

class qsignal: public QObject
{
    Q_OBJECT
public:
    qsignal():value(0){};
    public slots:
    void Bool_function()
    {
       value = 1;

    }
public:
    int value;

};



#endif // QSIGNAL_H
