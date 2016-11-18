#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "fstream"
#include "ctime"
#include "iostream"
#include "string"
#include  "time.h"
#include  <QObject>
using namespace std;







class Account: public QObject   // to define an abstract Account class
{               // both accounts share the same balance, the functions in this class enable both of them to do operation on the balance
Q_OBJECT

public:
    virtual void print_total(){};

  char* GetTime()
    {
        char* t;
        time_t seconds;
        seconds = time(NULL);
        //cout<<"The number of seconds since January 1, 1970 is:" <<seconds<<"\n";
        tm * timeinfo;
        timeinfo = localtime(&seconds);
        t= asctime(timeinfo);
        return t;
    }

  double GetBalance()
    {
        ifstream infile("/Users/lunzhang/FinalPro/balance.txt");
        double cash;
        infile >> cash;
        return cash;
    }

//protected:
    void SetBalance(double cash)
    {
        ofstream outfile("/Users/lunzhang/FinalPro/balance.txt");
        if (!outfile) {
            //cout << "Can not open the Balance.txt" << endl;

        }
        else
        {
            outfile << cash;
            //cout << "balance have been changed"<< endl;
        }

        outfile.close();
        //cout << "set balance +1" << endl;
    }



};



#endif // ACCOUNT_H
