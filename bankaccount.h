#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include "account.h"
#include <QApplication>
#include <QObject>
#include <QDialog>

class BankAccount: public Account, public QDialog
{


public:
    BankAccount();
    ~BankAccount();
    void depositeMoney( );
    void withdrawMoney();
    virtual void print_total();
    double get_total();
    void print_histroy();

    void depositeMoney(double );

    void withdrawMoney( double cash);
public slots:
    void renew_bank_accout();

private:
    double balance;
 };

#endif // BANKACCOUNT_H
