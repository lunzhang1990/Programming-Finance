#include "bankaccount.h"
#include "account.h"
#include <stdio.h>
#include "iostream"
#include "fstream"
#include "iomanip"
#include "string.h"
using namespace std;
string balanceStr = "/Users/lunzhang/FinalPro/balance.txt";
// address of balance
BankAccount::BankAccount()
{
    //cout << "bank constructor first"<< endl;
    ifstream infile(balanceStr);
    if(!infile)
    {
        balance = 10000;
        cout << "the file is empty" << endl;
    }
    else
    {
        infile >> balance;
        //cout << "the file is not "<< endl;
    }
    infile.close();
    //cout << "constructor of bank account "<< endl;
}

BankAccount::~BankAccount()
{
    //after all the operations of bank account we update the

    /*ofstream outfile(balanceStr);
    if (!outfile)
    {
        cout << "Error, can not open the Balance.txt"<< endl;
    }
    else{

        outfile << balance;
        //cout << "write the balance to " << endl;

    }
    outfile.close();*/
    // update Total_Portfolio.txt
     double total_stock=0;
     ifstream infile_stock("/Users/lunzhang/FinalPro/Total_Value_Stock");
     if(infile_stock >> total_stock)// to read balance
     {


     }
     double bal;// the balance
     ifstream infile_read("/Users/lunzhang/FinalPro/balance.txt");
     if(infile_read >> bal)// to read balance
     {


     }



     ofstream outfile("/Users/lunzhang/FinalPro/Total_Value_History.txt",ios::app);
     //ofstream outfile1("/Users/lunzhang/FinalPro/Total_Porfolio.txt")
     outfile <<setw(10)<<  total_stock+bal << setw(30)<<GetTime()<< endl;

}





void  BankAccount::depositeMoney( ) // output the result into // will check the deposite money and ouput the result into Bank_transaction_history.txt
{
    //cout << "Input the amount of money you want to deposite" << endl;
    double cash;
    cin >> cash;
    if (cash<=0) {
        //cout << "Pleas input a postive number" << endl;
    }
    else
    {
        balance = balance +cash;
        ofstream outfile("Bank_transaction_history.txt",ios::app);
        char* t = GetTime();
        if (outfile.is_open()) {
            outfile << "Deposite" << setw(5)<<"$"<<cash << setw(10)<< t<<setw(10)<<balance << endl;
        }
        else
        {
            //cout << "Error, Bank_transaction_history.txt can not open " <<endl;

        }

     outfile.close();
    }

    ofstream outfile1("/Users/lunzhang/FinalPro/balance.txt");
    outfile1 << balance;
    outfile1.close();

}

void  BankAccount::depositeMoney( double cash)  // overloading with parameter double, in order to be used in GUI
{

    if (cash<=0) {
        //cout << "Pleas input a postive number" << endl;
    }
    else
    {
        balance = balance +cash;
        ofstream outfile("/Users/lunzhang/FinalPro/Bank_transaction_history.txt",ios::app);
        char* t = GetTime();
        if (outfile.is_open()) {
            outfile << "Deposite" << setw(5)<<"$"<<cash << setw(10)<< t<<setw(10)<<balance << endl;
        }
        else
        {
            //cout << "Error, Bank_transaction_history.txt can not open " <<endl;

        }

     outfile.close();
    }

    ofstream outfile1("/Users/lunzhang/FinalPro/balance.txt");
    outfile1 << balance;
    outfile1.close();

}


void BankAccount::withdrawMoney() // output result into // will check the withdraw money and ouput the result into Bank_transaction_history.txt
{
    //cout << "Input the amount of money you want to withdraw" << endl;
    double cash;
    cin >> cash;
    if (cash<=0|| cash> balance) {
        //cout << "Please input a postive number that is smaller than the money in BankAccount" << endl;
    }
    else
    {
        balance = balance -cash;
        ofstream outfile("/Users/lunzhang/FinalPro/Bank_transaction_history.txt", ios::app);
        char* t = GetTime();
        if (outfile.is_open()) {
            outfile << "Withdraw" << setw(5)<<"$"<<cash << setw(10)<< t<<setw(10)<<balance << endl;

        }
       else
       {
          // cout << "Error, Bank_transaction_history.txt can not open " <<endl;

       }

      outfile.close();
    }
 ofstream outfile1("/Users/lunzhang/FinalPro/balance.txt");
 outfile1 << balance;
 outfile1.close();


}

void  BankAccount::withdrawMoney( double cash)  // overloading with parameter double, in order to be used in GUI
{

    if (cash<=0) {
        cout << "Pleas input a postive number" << endl;
    }
    else
    {
        balance = balance -cash;
        ofstream outfile("/Users/lunzhang/FinalPro/Bank_transaction_history.txt",ios::app);
        char* t = GetTime();
        if (outfile.is_open()) {
            outfile << "Withdraw" << setw(5)<<"$"<<cash << setw(10)<< t<<setw(10)<<balance << endl;
        }
        else
        {
            //cout << "Error, Bank_transaction_history.txt can not open " <<endl;

        }

     outfile.close();
    }

    ofstream outfile1("/Users/lunzhang/FinalPro/balance.txt");
    outfile1 << balance;
    outfile1.close();

}

void BankAccount::print_total() // read the data from Balance.txt
{

        //cout << "The current total bank accout is" << balance << endl;


}

double BankAccount::get_total()
{

    return balance;


}

void BankAccount::print_histroy()
{
    ifstream infile("Bank_transaction_history.txt");
    if (infile.is_open()) {
        string t;
        while (getline(infile,t)) {
            cout << t << endl;
        }
    }
    else{
       // cout << "Error, can not open Bank_transaction_history.txt" << endl;

    }
  infile.close();

}


void BankAccount::renew_bank_accout()
{
  this->balance = this->GetBalance();

}
