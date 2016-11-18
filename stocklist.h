#ifndef STOCKLIST_H
#define STOCKLIST_H


#include <stdio.h>
#include "stock.h"
#include "string"
using namespace std;
class StockList
{
    friend class StockAccount;
     public:
        StockList();
        ~StockList();
        int size() const;
        void addToStart(Stock *);
        void addToEnd(Stock *);
        void printList();
        int SearchStock(string); // find the number of shares of one stock
        Stock* SearchStockAddress(string);
    //Stock *myHead;
    //Stock *myTail;
private:
         Stock *myHead;
         Stock *myTail;
         int mySize;

};

#endif // STOCKLIST_H
