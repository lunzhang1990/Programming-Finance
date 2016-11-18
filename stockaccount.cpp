#include "stockaccount.h"

#include "stockaccount.h"
#include "stocklist.h"
#include "iostream"
#include "string"
#include "time.h"
#include "fstream"
#include "iomanip"
#include "stockmarket.h"
#include "bankaccount.h"
#include "engine.h"
#include "vector"
using namespace std;

StockAccount::StockAccount() // to initialize the StockList.txt and the doubly linked list StockList

{
    //cout << "stockaccount constructor" << endl;
    ifstream infile("/Users/lunzhang/FinalPro/StockList.txt");
    Stock* st1;
    string name;
    double num;
    /*(if (!infile) {  // if the file is empty, we set up the tittle of the file
        ofstream outfile("StockList.txt");
        outfile << "CompName" << setw(10)<< "Number of shares"<< endl;
        outfile.close();

    }
    else
    {
        int i=0;
        while (infile >> name >> num) {
            st1= new Stock(name , num);
            SList.addToEnd(st1);
            i++;

        }*/
    int i=0;
    while (infile >> name >> num) {
        st1= new Stock(name , num);
        SList.addToEnd(st1);
        i++;
        //cout << i  << endl;
    }
    infile.close();
   //cout<<"stockAccount constructor" << endl;




}

// we do not sort the vlaue in the buy() and sell() or upload record of the whole stock list, we will do that in the destructor of StockAccount
StockAccount::~StockAccount()
{
   // first quicksort the SList
   cout <<"destructor"<<endl;
    SList.printList();
    QuickSort();
   //update StockList.txt
    ofstream outfile("/Users/lunzhang/FinalPro/StockList.txt");
    Stock* temp ;
    // to update the StockList and remove the 0 number shares
    for (temp = SList.myHead; temp!= NULL; temp=temp->next) {
        if (temp->itemNo!=0) {
            outfile <<setw(10)<< temp->itemName <<setw(10) <<temp->itemNo<< endl;
        }
    }

   // update Total_Portfolio.txt
    double total=0;
    for (temp = SList.myHead; temp!= NULL; temp=temp->next) {
        total = total+SMarket.getStockPrice(temp->itemName)*temp->itemNo;
        cout << total << endl;
        cout << "here"<< endl;
    }
    double bal;// the balance
    ifstream infile_read("/Users/lunzhang/FinalPro/balance.txt");
    if(infile_read >> bal)// to read balance
    {


    }

    ofstream outfile1("/Users/lunzhang/FinalPro/Total_Porfolio.txt", ios::app);// history of stock
    ofstream outfile2("/Users/lunzhang/FinalPro/Total_Value_Stock.txt"); // record the total value of stock
    ofstream outfile3("/Users/lunzhang/FinalPro/Total_Value_History.txt", ios::app);
    //ofstream outfile1("/Users/lunzhang/FinalPro/Total_Porfolio.txt")
    outfile1 <<setw(10)<<  total << setw(30)<<GetTime()<< endl;
    outfile2 << total<< endl;
    outfile3 <<setw(10)<<  total+bal << setw(30)<<GetTime()<< endl;
    //cout << "the destructor" << endl;
}
void StockAccount::dispalyStock(string name)
{
    int num;
    num =SList.SearchStock(name);
    if (num >=0) {
        cout << "There are "<< num << "shares of " << name <<"stock in the stock account"<< endl;
    }
}

void StockAccount::displaySList()
{
    Stock* temp;
    temp = SList.myHead;
    while (temp!= NULL) {
        cout <<"Name:" <<temp->itemName << setw(10)<<"Number:"<<temp->itemNo << endl;
        temp = temp->next;
     }


}



void StockAccount::BuyStock() // to show history and the, also need to result2.txt, as need to compare the price of....
{
    string name;
    int num;
    double price;
    cout << "Enter the name and share you want to buy"<< endl;;
    cin >> name;
    // first check whether the number is in the list
    if (!SMarket.checkStock(name)) {
        //cout << "The stock is not tradable" << endl;
        return;
    }

    cout << "Enter the price you want to pay" << endl;
    cin >> price;

    // to check whether the calling price is ok

    if (price < SMarket.getStockPrice(name)) {
        //cout << "Sorry, the price is not enough to purchase the shares"<< endl;
        return;
    }

    //cout << "Enter the number of shares want to buy" << endl;
    cin >> num;
    // to check whether the balance is enough to support
    if (num <0) {
        //cout << "please input a positive integer" << endl;
        return;
    }
    if (SMarket.getStockPrice(name)*num > GetBalance()) { // this GetBalance() is defined in the abstract Account
        //cout <<"Do no have enough balance to buy" << endl;
        return;
    }


    // if the purchase is plausible: the stock exists and the price is reasonalbe, we do the action and record it

    Stock* temp;
    temp = SList.SearchStockAddress(name);
    temp->itemNo = temp->itemNo + num;                    // change the holding price of the List

    // to record the action in Stock_Transaction_History.txt
    ofstream outfile("/Users/lunzhang/FinalPro/Stock_Transaction_History.txt",ios::app);
    outfile << "Buy" <<setw(10)<< name << setw(5) << num<< " "<< GetTime() <<endl;
    outfile.close();

   //


    // to update balance in the Balance.txt
    SetBalance(GetBalance()-num*SMarket.getStockPrice(name)); // // SetBalance() in the Account class, to update value in Balance.txt


    //cout << "The buy is done" << endl;

}


void StockAccount::BuyStock(string name,int amount) // just record not to check
{
    // change the holding price of the List
    // if the purchase is plausible: the stock exists and the price is reasonalbe, we do the action and record it
    if(SList.SearchStock(name)>0){
    Stock* temp;
    temp = SList.SearchStockAddress(name);
    temp->itemNo = temp->itemNo + amount;}
    else{ // the stock is not in the SList
    Stock* temp = new Stock(name,amount);
    SList.addToEnd(temp);
     }


    // to record the action in Stock_Transaction_History.txt
    ofstream outfile("/Users/lunzhang/FinalPro/Stock_Transaction_History.txt",ios::app);
    outfile << "Buy" <<setw(10)<< name << setw(5) << amount<< " "<< GetTime() <<endl;
    outfile.close();

   // to update balance in the Balance.txt
   //ofstream outfile2("/Users/lunzhang/FinalPro/balance.txt");  // SetBalance() in the Account class, to update value in Balance.txt
   BankAccount* ba = new BankAccount;
   double rest =ba->GetBalance() - amount*1;
   ba->SetBalance(rest);
   //outfile2 << rest;
   //outfile2.close();

  // to update Bank_transaction_history.txt
  ofstream outfile1("/Users/lunzhang/FinalPro/Bank_transaction_history.txt",ios::app);
  outfile1<<"Buy stock"<< endl;
  outfile1<< setw(10) <<name << setw(5)<< amount<<" "<<GetTime()<< endl;
  outfile1.close();
  delete ba;

}

void StockAccount::BuyStock(string name,int amount,double price) // just record not to check
{
    // change the holding price of the List
    // if the purchase is plausible: the stock exists and the price is reasonalbe, we do the action and record it
    if(SList.SearchStock(name)>0){
    Stock* temp;
    temp = SList.SearchStockAddress(name);
    temp->itemNo = temp->itemNo + amount;}
    else{ // the stock is not in the SList
    Stock* temp = new Stock(name,amount);
    SList.addToEnd(temp);
     }


    // to record the action in Stock_Transaction_History.txt
    ofstream outfile("/Users/lunzhang/FinalPro/Stock_Transaction_History.txt",ios::app);
    outfile << "Buy" <<setw(10)<< name << setw(5) << amount<< " "<< GetTime() <<endl;
    outfile.close();

   // to update balance in the Balance.txt
   //ofstream outfile2("/Users/lunzhang/FinalPro/balance.txt");  // SetBalance() in the Account class, to update value in Balance.txt
   BankAccount* ba = new BankAccount;
   double rest =ba->GetBalance() - amount*price;
   ba->SetBalance(rest);
   //outfile2 << rest;
   //outfile2.close();

  // to update Bank_transaction_history.txt
  ofstream outfile1("/Users/lunzhang/FinalPro/Bank_transaction_history.txt",ios::app);
  outfile1<<"Buy stock"<< endl;
  outfile1<< setw(10) <<name << setw(5)<< amount<<" "<<GetTime()<< endl;
  outfile1.close();
  delete ba;

}

void StockAccount::SellStock()  // the corresponding behavior of sell
{

    string name;
    int num;
    double price;
    //cout << "Enter the name and share you want to sell"<< endl;;
    cin >> name;
    // first check whether the number is in the list
    if (!SMarket.checkStock(name)) {
        //cout << "The stock is not tradable" << endl;
        return;
    }

    // to check wether have the stock in the list
    if (SList.SearchStock(name)<=0) {
        //cout << "You do not have the stock in your stock list" << endl;
        return;
    }

    cout << "Enter the price you want to pay" << endl;
    cin >> price;

    // to check whether the calling price is ok

    if (price > SMarket.getStockPrice(name)) {
        //cout << "Sorry, the price is too high to sell the shares"<< endl;
        return;
    }

    //cout << "Enter the number of shares want to sell" << endl;
    cin >> num;
    // to check whether the balance is enough to support
    if (num <0) {
        //cout << "please input a positive integer" << endl;
        return;
    }
    if (num > SList.SearchStock(name)) {
        //cout << "You do not have enough shares to sell" << endl;
        return;
    }


    // if the purchase is plausible: the stock exists and the price is reasonalbe, we do the action and record it

    Stock* temp;
    temp = SList.SearchStockAddress(name);
    temp->itemNo = temp->itemNo - num;                    // change the holding price of the List

    // to record the action in Stock_Transaction_History.txt
    ofstream outfile("/Users/lunzhang/FinalPro/Stock_Transaction_History.txt",ios::app);
    outfile << "Sell" <<setw(10)<< name << setw(5) << num<< " "<< GetTime() <<endl;
    outfile.close();

    // to update balance in the Balance.txt
    SetBalance(GetBalance()+num*SMarket.getStockPrice(name)); // SetBalance() in the Account class, to update value in Balance.txt

    //cout << "The sell is done" << endl;

}

// overloading sell
void StockAccount::SellStock(string name, int num)  // the corresponding behavior of buy
// no need to check name in list as it is already plausible to sell
// only need to check amount of the chosen stock < num in list
{

   //double price;

    // if the purchase is plausible: the stock exists and the price is reasonalbe, we do the action and record it

    Stock* temp;
    temp = SList.SearchStockAddress(name);
    temp->itemNo = temp->itemNo - num;                    // change the holding price of the List

    // to record the action in Stock_Transaction_History.txt
    ofstream outfile("/Users/lunzhang/FinalPro/Stock_Transaction_History.txt",ios::app);
    outfile << "Sell" <<setw(10)<< name << setw(5) << num<< " "<< GetTime() <<endl;
    outfile.close();

    // to update balance in the Balance.txt
    BankAccount* ba = new BankAccount;
    double rest =ba->GetBalance() + num*SMarket.getStockPrice(name);
    ba->SetBalance(rest);
    // to update bank history

    ofstream outfile1("/Users/lunzhang/FinalPro/Bank_transaction_history.txt",ios::app);
    outfile1<<"Sell stock"<< endl;
    outfile1<< setw(10) <<name << setw(5)<< num<<" "<<GetTime()<< endl;
    outfile1.close();
    delete ba;

 }


/*void StockAccount::SellStock(string name,int amount,double price) // just record not to check
{
    // change the holding price of the List
    // if the purchase is plausible: the stock exists and the price is reasonalbe, we do the action and record it

    // minus the

    Stock* temp;
    temp = SList.SearchStockAddress(name);
    //cout << temp->itemName<< "the name is here"<< endl; the checked name is good
    temp->itemNo = temp->itemNo - amount;
    //cout << temp->itemNo << "the number is here" << endl; // the number is right
    //cout << "the sell stock work"<< endl;
    //SList.printList();


    // to record the action in Stock_Transaction_History.txt
    ofstream outfile("/Users/lunzhang/FinalPro/Stock_Transaction_History.txt",ios::app);
    outfile << "Sell" <<setw(10)<< name << setw(5) << amount<< " "<< GetTime() <<endl;
    outfile.close();

   // to update balance in the Balance.txt
   //ofstream outfile2("/Users/lunzhang/FinalPro/balance.txt");  // SetBalance() in the Account class, to update value in Balance.txt
   BankAccount* ba = new BankAccount;
   double rest =ba->GetBalance() + amount*price;
   ba->SetBalance(rest);
   //outfile2 << rest;
   //outfile2.close();

  // to update Bank_transaction_history.txt
  ofstream outfile1("/Users/lunzhang/FinalPro/Bank_transaction_history.txt",ios::app);
  outfile1<<"Sell stock"<< endl;
  outfile1<< setw(10) <<name << setw(5)<< amount<<" "<<GetTime()<< endl;
  outfile1.close();
  delete ba;

}*/

void StockAccount::SellStock(string name,int amount,double price) // just record not to check
{
    // change the holding price of the List
    // if the purchase is plausible: the stock exists and the price is reasonalbe, we do the action and record it
    if(SList.SearchStock(name)>0){
    Stock* temp;
    temp = SList.SearchStockAddress(name);
    temp->itemNo = temp->itemNo - amount;}


    // to record the action in Stock_Transaction_History.txt
    ofstream outfile("/Users/lunzhang/FinalPro/Stock_Transaction_History.txt",ios::app);
    outfile << "Sell" <<setw(10)<< name << setw(5) << amount<< " "<< GetTime() <<endl;
    outfile.close();

   // to update balance in the Balance.txt
   //ofstream outfile2("/Users/lunzhang/FinalPro/balance.txt");  // SetBalance() in the Account class, to update value in Balance.txt
   BankAccount* ba = new BankAccount;
   double rest =ba->GetBalance() + amount*price;
   ba->SetBalance(rest);
   //outfile2 << rest;
   //outfile2.close();

  // to update Bank_transaction_history.txt
  ofstream outfile1("/Users/lunzhang/FinalPro/Bank_transaction_history.txt",ios::app);
  outfile1<<"Sell stock"<< endl;
  outfile1<< setw(10) <<name << setw(5)<< amount<<" "<<GetTime()<< endl;
  outfile1.close();
  delete ba;

}



void DisplayGraph(); // how to display graph of what .....










void DispalyTransactionHistory();
void StockAccount::print_total() // neid the result1.txt i.e the price of each stock
{
    Stock* temp;
    temp = SList.myHead;
    double total =0;
    if (SList.myHead!= NULL)   {
    while (temp!= NULL) {
        total = total + temp->itemNo*SMarket.getStockPrice(temp->itemName);
        temp= temp->next;
      }
    }
    cout << "The total number of stock account is "<< setw(5) << "$"<<total<< endl;
}


double StockAccount::get_total()
{
     Stock* temp;
    temp = SList.myHead;
    double total =0;
    if (SList.myHead!= NULL)   {
    while (temp!= NULL) {
        total = total + temp->itemNo*SMarket.getStockPrice(temp->itemName);
        temp= temp->next;
      }
    }

    return total;


}





void StockAccount::BubbleSort() // in increasing order
{
   Stock* tempHead; // the temp used to move the stock in the stock list
    Stock* tempTail;// this will record the last one which has not been a sorted, will move forward after each loop
    tempHead = SList.myHead;
    tempTail= SList.myTail;
    while (tempTail != SList.myHead) { // we will do the sorting untial tempTail move to the head place
        while (tempHead->next!= tempTail) {
            // we will stop at the second to last step, to avoid confusing and tricks

            double priceHead = tempHead->itemNo*SMarket.getStockPrice(tempHead->itemName);
            double priceNext = tempHead->next->itemNo*SMarket.getStockPrice(tempTail->next->itemName);
             // if tempHead value is bigger then we exchange the position of temp and temp->next
            if (priceHead >priceNext) {
                Stock* temp;
                temp = tempHead->pre;
                // firt change the tempHead
                tempHead->pre = tempHead->next;
                tempHead->next = tempHead->next->next;
                // change the original tempHead->next by using temp, and the fact it is in the tempHead->pre
                tempHead->pre->next = tempHead;
                tempHead->pre->pre = temp;

            } else // if no change is needed
            {
                tempHead = tempHead->next;

            }

        }
        // we deal with final step from second to final separatly
        double priceHead = tempHead->itemNo*SMarket.getStockPrice(tempHead->itemName);
        double priceNext = tempHead->next->itemNo*SMarket.getStockPrice(tempTail->next->itemName);// this is tempTail
        if (priceHead > priceNext) {
            // do exchange a before, but set tempHead= myHead and tempTail to something to start new step
            Stock* temp;
            temp = tempHead->pre;
            // firt change the tempHead
            tempHead->pre = tempHead->next;
            tempHead->next = tempHead->next->next;
            // change the original tempHead->next by using temp, and the fact it is in the tempHead->pre
            tempHead->pre->next = tempHead;
            tempHead->pre->pre = temp;
            tempHead = SList.myHead;// reset the tempHead, the tempTail by above changing alreading move to the one step befor

        } else
        {
            tempHead = SList.myHead;
            tempTail = tempTail->pre;

        }


    }



}


Stock* StockAccount::partition(Stock* stock1,Stock* stock2)
{
   // take the pivot stock to be the left one,
    //cout<<"start partition"<< endl;
    Stock* leftptr = stock1;
    Stock* rightptr = stock2;
    int pivotNo = stock1->itemNo;
    string pivotName = stock1->itemName;
    double pivot = SMarket.getStockPrice(leftptr->itemName)*leftptr->itemNo;
    while (leftptr!= rightptr) {

    while (leftptr!= rightptr&& leftptr!=NULL&&rightptr!=NULL) {
        if (SMarket.getStockPrice(rightptr->itemName)*rightptr->itemNo < pivot) {
            // we move the stokc to the left position
            leftptr->itemName = rightptr->itemName;
            leftptr->itemNo  = rightptr->itemNo;
            break;
            //cout <<1<< endl;
        } else
        {
            rightptr = rightptr->pre;
            //cout << 2<< endl;
        }
    }
    while (leftptr!= rightptr&& leftptr!=NULL&&rightptr!=NULL) {
            if (SMarket.getStockPrice(leftptr->itemName)*leftptr->itemNo > pivot) {
                // we move the stokc to the left position
                rightptr->itemName = leftptr->itemName;
                rightptr->itemNo  =  leftptr->itemNo;
                //cout << 3 << endl;
                break;
            } else
            {
                leftptr = leftptr->next;
                //cout << 4<< endl;
            }

     }
    }
    leftptr->itemNo = pivotNo;
    leftptr->itemName = pivotName; // to finish the partition by filling the final empty by using pivot

    //cout << "partition" << endl;
    return leftptr;

}

void StockAccount::QuickSort(Stock* h,Stock* l)
{
    if(h != NULL && l != h && l!= NULL)
    {
        Stock* temp;
        temp = partition(h, l);
        /*if (temp->pre != NULL) {
            cout << temp->pre->itemName << endl;
        }

        cout << temp->itemName<< endl;
        if (temp->next != NULL) {
            cout << temp->next->itemName<< endl;
        }*/
        if (temp!=l) {                         // we need to note the temp = l case will cause trouble
            QuickSort(temp->next, l);
        }

        //cout << "Good"<< endl;
        if (temp != h) {                      // the temp = h will cause trouble
            QuickSort(h, temp->pre);
        }

        //cout << "Fine" << endl;

    }





}

void StockAccount::QuickSort()
{
    QuickSort(SList.myHead, SList.myTail);

}

void StockAccount::plot_portfolio_value()
{



        /*vector<double> v;
        double value;
        string t1,t2,t3,t4;
        int num =0;
        ifstream read_total("/Users/lunzhang/FinalPro/Total_Porfolio.txt");
        while(read_total >> value>>t1>>t2>>t3>>t4)
        { v.push_back(value);
            num =num+1;
            //cout << num << endl;
        }

        double z[num];
        for (int i=0; i<num; i++) {
            z[i] = v.at(i);
        }
        for (int i =0; i<num; i++) {
            cout << z[i] << endl;
        }

    Engine* eg;
    eg = engOpen(NULL);
    mxArray* z_array = mxCreateDoubleMatrix_700(num,1,mxREAL);
    double *pz = mxGetPr(z_array);

   for(int i =0;i<num; i++)
  {
    pz[i] = z[i];
  }

 engPutVariable(eg,"z",z_array);
 engEvalString(eg,"testPlot");
*/



}
