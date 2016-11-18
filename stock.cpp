#include "stock.h"

Stock::Stock(string& name, int no) // the node to store stocke's name and shares
:itemName(name), itemNo(no)
{
    this->pre =NULL;
    this->next=NULL;
}

int Stock::show_number()
{
   return itemNo;

}
