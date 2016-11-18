#ifndef STOCK_H
#define STOCK_H


#include "string"
#include <stdio.h>
#include "myline.h"
using namespace std;
class Stock
{

    friend class StockList;
    friend class StockAccount;
public:
    Stock(string& name, int no); // the node to store stocke's name and shares
    int show_number();
    /*Stock *pre;
    Stock *next;
     string itemName;
     int itemNo;*/
private:
   string itemName;
    int itemNo;

    Stock *pre;
    Stock *next;

};

#endif // STOCK_H
