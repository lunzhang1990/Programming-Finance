#ifndef STOCKMARKET_H
#define STOCKMARKET_H


#include <stdio.h>
#include "string"
#include "map"
using namespace std;
class StockMarket
{
public:
    StockMarket();
    ~StockMarket();
    void SetStockMarket(); // to read the price of stock from results.txt file
    double getStockPrice(string);
    bool checkStock(string);
    int randNum();
    map<string, double> Market1; 	 // map stock symbol with price
    map<string, double> Market2;

};
#endif // STOCKMARKET_H
