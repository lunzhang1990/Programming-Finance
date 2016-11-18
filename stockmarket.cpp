#include "stockmarket.h"
#include "fstream"
#include "map"
#include "iostream"
#include "string"
using namespace std;
StockMarket::StockMarket()
{
    //cout << "constructor of stock markets" << endl;
    SetStockMarket();
    //cout << "constructor of stock market" << endl;
}

StockMarket::~StockMarket()
{

}

void StockMarket::SetStockMarket()
{


    ifstream infile1("/Users/lunzhang/FinalPro/Results_1.txt");
    ifstream infile2("/Users/lunzhang/FinalPro/Results_2.txt");
    //ifstream infile3("/Users/lunzhang/FinalPro/balance.txt");

    string name;
    double price;
    string date;
    while (!infile1.eof()) {

        infile1 >> name >> price>>date;
        //cout << "set 5"<< endl;
        Market1[name] = price;
    }
    //cout << "set 3"<< endl;
    while (!infile2.eof()) {
        infile2>> name >> price>>date;
        Market2[name] = price;
    }
    //cout << "set 4"<< endl;
    infile1.close();
    infile2.close();

}

double StockMarket::getStockPrice(string name)
{

    if (checkStock(name)) {
        randNum();
        if (randNum() == 1) {
            return Market1[name];
        } else
        {

            return Market2[name];
        }
    } else
    {
        //cout << "The stock is not available for trading" << endl;
        cout << name<< endl;
        return 0;

    }


}

bool StockMarket::checkStock(string name)
{
    if (Market1.count(name)>0) {
        return 1;
    }
    else
    {
        return 0;

    }

}

int StockMarket::randNum()
{
    srand((unsigned int)time(NULL));
    int i = rand()%2 +1;               // the random number is 0 or 1
    return i;

}
