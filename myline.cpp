#include "myline.h"
#include "QString"
#include "bankaccount.h"
#include "string.h"
#include "stockmarket.h"
#include <QFile>
#include <QTextStream>
#include "stockaccount.h"
#include <iostream>
using namespace std;
#include <iostream>
using namespace std;
MyLine::MyLine()
{

}

void MyLine::deposite_money()
{
   double deposite;
   BankAccount* ba = new BankAccount;
   QString* str = new QString;
   *str = this->text();
   deposite = str->toDouble();
   ba->depositeMoney(deposite);
   //ba->SetBalance(ba->GetBalance()+deposite);
   delete ba;
}

void MyLine::withdraw_money()
{
   double withdraw=0;
   BankAccount* ba = new BankAccount;
   QString* str = new QString;
   *str = this->text();
   withdraw= str->toDouble();
   if(withdraw < ba->GetBalance()){
   ba->withdrawMoney(withdraw);
       //ba->SetBalance(ba->GetBalance()-withdraw);
   emit Success_withdraw();
   } else
   {

       Failure_withdraw();
   }

   delete ba;
}

void MyLine::stock_search()
{
   StockMarket* sMarket = new StockMarket;
   QString name_stock;
   string name;
   name_stock = this->text();
   name = name_stock.toStdString();
   if(sMarket->checkStock(name) > 0)
   {

       QFile stock_file("/Users/lunzhang/FinalPro/One_stock.txt");
       stock_file.open(QIODevice::WriteOnly);
       QTextStream qtextstream(&stock_file);
       qtextstream <<  name_stock <<"  "<< sMarket->getStockPrice(name);
       stock_file.close();
       emit  stock_tradable();
   }else
   {emit stock_untradable();}

  delete sMarket;
}

void MyLine::stock_buy_amount_check()
{
    BankAccount* ba = new BankAccount;
    StockMarket* sMarket = new StockMarket;
    // get the numbers of stock want to buy
    int amount = this->text().toInt();

    // get the name of the stock to buy
    QFile file_name("/Users/lunzhang/FinalPro/Stock_buy.txt");
    file_name.open(QIODevice::ReadOnly);
    QTextStream qtextstream(&file_name);
    QString qst;
    qst = qtextstream.readAll();
    string name = qst.toStdString();

    // get the price the custom offers to buy stock
    QFile file_price("/Users/lunzhang/FinalPro/Stock_buy_price.txt");
    file_price.open(QIODevice::ReadOnly);
    QTextStream qread(&file_price);
    QString qst1;
    qst1 = qread.readAll();
    double price = qst1.toDouble();


    if(amount*price > ba->GetBalance())
    {
        emit not_enough_balance();

    }else
    {

        StockAccount* sa = new StockAccount;
        sa->BuyStock(name, amount,price);
        delete sa;
        emit enongh_balance();
    }
  delete ba;
  delete sMarket;
 // here need to overload buy shares function that contain parameter in order to record
}

void MyLine::stock_buy_price()
{

    // first get the name of the price to buy, stored by stock_search() function
    QString qname;
    string name;
    QFile file_name("/Users/lunzhang/FinalPro/Stock_buy.txt");
    file_name.open(QIODevice::ReadOnly);
    QTextStream qread(&file_name);
    qname = qread.readAll();
    name =qname.toStdString();

    // find the price of stock in stock market
    double price=0;
    StockMarket* sm = new StockMarket;
    price = sm->getStockPrice(name);

    // read the price custom offers
    double offer = this->text().toDouble();

    // to check condition
    if(offer < price)
    {emit bad_price();}
    else
    {  // record the price of stock in Stock_buy_price.txt

        QFile file_name("/Users/lunzhang/FinalPro/Stock_buy_price.txt");
        file_name.open(QIODevice::WriteOnly);
        QTextStream qwrite(&file_name);
        qwrite << offer;
        file_name.close();
         emit good_price();
    }

   delete sm;

}

void MyLine::stock_buy_name()
{
    StockMarket* sMarket = new StockMarket;
    QString qname = this->text();
    string name = qname.toStdString();
    if(sMarket->checkStock(name) > 0)
    {
    QFile file_name("/Users/lunzhang/FinalPro/Stock_buy.txt");
    file_name.open(QIODevice::WriteOnly);
    QTextStream qtextstream(&file_name);
    qtextstream << qname;
    file_name.close();
    emit stock_tradable();
    } else
    {
        stock_untradable();
    }
    delete sMarket;
}

void MyLine::stock_sell_name()
{
    QString qname = this->text();
    QFile file_name("/Users/lunzhang/FinalPro/Stock_sell.txt");
    file_name.open(QIODevice::WriteOnly);
    QTextStream qtextstream(&file_name);
    qtextstream << qname;
    file_name.close();

}

void MyLine::stock_sell_price()
{

    // first get the name of the price to buy, stored by stock_search() function
    QString qname;
    string name;
    QFile file_name("/Users/lunzhang/FinalPro/Stock_sell.txt");
    file_name.open(QIODevice::ReadOnly);
    QTextStream qread(&file_name);
    qname = qread.readAll();
    name =qname.toStdString();

    // find the price of stock in stock market
    double price=0;
    StockMarket* sm = new StockMarket;
    price = sm->getStockPrice(name);

    // read the price custom offers
    double offer = this->text().toDouble();

    // to check condition
    if(offer > price)
    {emit bad_price();}
    else
    {  // record the price of stock in Stock_buy_price.txt

        QFile file_name("/Users/lunzhang/FinalPro/Stock_sell_price.txt");
        file_name.open(QIODevice::WriteOnly);
        QTextStream qwrite(&file_name);
        qwrite << offer;
        file_name.close();
        emit good_price();
    }

   delete sm;

}




void MyLine::stock_search_inlist()
{
   QString qname = this->text();
   string name = qname.toStdString();

   StockAccount* sa = new StockAccount;
   int flag = sa->SList.SearchStock(name);
   delete sa;
   if(flag >0)
   {
       emit in_list();
   }else
   {
       emit not_in_list();

   }


   /*StockAccount* sa = new StockAccount; // this does not work
   if(sa->SList.SearchStock(name) >0)
   {
       emit in_list();
   }else
   {
       emit not_in_list();

   }*/

}


void MyLine::stock_sell_amount_check()
{

    //BankAccount* ba = new BankAccount;
    //StockMarket* sMarket = new StockMarket;
   int amount = this->text().toInt();

    // get the name of stock to sell
    QFile file_amount("/Users/lunzhang/FinalPro/Stock_sell.txt");
    file_amount.open(QIODevice::ReadOnly);
    QTextStream qtextstream(&file_amount);
    QString qst;
    qst = qtextstream.readAll();
    string str = qst.toStdString();

    //get the price of stock to sell
    QFile file_price("/Users/lunzhang/FinalPro/Stock_sell_price.txt");
    file_price.open(QIODevice::ReadOnly);
    QTextStream qread(&file_price);
    QString qst1;
    qst1 = qread.readAll();
    double price = qst1.toDouble();

    // check the amount in list
    cout << "outer" << endl;
    StockAccount* sa = new StockAccount;
    Stock* stk1 = sa->SList.SearchStockAddress(str);
    int amount_list = stk1->show_number();
    delete sa;


    if(amount_list < amount)
    {
        emit not_enough_amount();

    }else
    {
        cout << "inner"<< endl;
        StockAccount* sa = new StockAccount;
        sa->SellStock(str,amount,price); // problem is here
        //cout << "the sell stock work++++"<< endl;
        sa->SList.printList();
        delete sa;
        emit enough_amount();
    }



}


void MyLine::out_list()
{

this->setText("You do not own the stock");

}

