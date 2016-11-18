#ifndef STOCKACCOUNT_H
#define STOCKACCOUNT_H


#include "account.h"
#include <stdio.h>
#include "stocklist.h"
#include "stockmarket.h" //as we will need the random prices of stocks
#include "myline.h"
class StockAccount: public Account
{
friend class MyLine;
public:
    StockAccount();
    ~StockAccount();
    void dispalyStock(string);
    void displaySList();

    void BuyStock();
    void BuyStock(string, int); // overloading
    void BuyStock(string, int, double);
    void SellStock();
    void SellStock(string , int);
    void SellStock(string, int, double);


    void DisplayGraph();
    void DispalyTransactionHistory();
    virtual void print_total();
    double get_total();
    void BubbleSort();
    void QuickSort();
    //StockList SList;
     void QuickSort(Stock*,Stock*);
     void plot_portfolio_value();
private:
    StockList SList;
    // doubly linked list to store the name and number of shares
    StockMarket SMarket;
    // the quicksort used to build the public quicksort
    Stock* partition(Stock*,Stock*); // this partition is the recursive step in quick sort

};



#endif // STOCKACCOUNT_H
