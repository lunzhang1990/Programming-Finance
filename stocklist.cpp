#include "stocklist.h"
#include "iostream"
#include "iomanip"
using namespace std;
StockList::StockList()
{
    myHead = NULL;
    myTail = NULL;
    mySize =0;

}
StockList::~StockList()
{
    if (mySize!= 0){
        Stock* pCurrent = myHead;
        Stock* temp;
        while (pCurrent != NULL) {
            temp = pCurrent;
            pCurrent = pCurrent->next;
            delete temp;
        }
    }



}
int StockList::size() const
{
    return  mySize;

}

void StockList::addToStart(Stock * item)
{
    if (mySize==0) {   // when the list is empty we need to initialize myHead and myTail
        myHead = item;
        myTail =item;
        mySize++;
    }
    else{
        item->next = myHead;
        myHead->pre = item;
        myHead = item;
        mySize++;
    }
}
void StockList::addToEnd(Stock * item)
{
    if (mySize == 0) {
        myHead = item;
        myTail =item;
        mySize++;
    }
    else{
        myTail->next = item;
        item->pre = myTail;
        myTail = item;
        mySize++;
    }
}

void StockList::printList()
{

    cout << "Item No" <<"  "<<"Item Name"<< endl;
    Stock* pCurrent = myHead;

    while (pCurrent != NULL) {
        cout << setw(7)<<pCurrent->itemNo<<" "<<setw(7)<< pCurrent->itemName<< endl;
        pCurrent = pCurrent->next;
    }


}

int StockList::SearchStock(string name)
{
    Stock* temp;
    temp = myHead;
    while (temp) {
        if (temp->itemName == name) {
           break;
        }
        else
        {
            temp = temp->next;
        }
    }

    if (temp == NULL) {
        //cout << "The name is not in stock account" << endl;
        return -1;
    }
    else
    {
        return  temp->itemNo;
        cout << "the number of stock" <<temp->itemNo;
    }
}

Stock* StockList::SearchStockAddress(string name)
{
    Stock* temp;
    temp = myHead;
    while (temp) {
        if (temp->itemName == name) {
            break;
        }
        else
        {
            temp = temp->next;
        }
    }
    if (temp == NULL) {
        //cout << "The name is not in stock account" << endl;
        return nullptr;
    }
    else
    {
        return  temp;
    }



}
