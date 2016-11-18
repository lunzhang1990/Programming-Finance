#ifndef MYLINE_H
#define MYLINE_H
#include <QLineEdit>

class MyLine: public QLineEdit
{
Q_OBJECT

public:
    MyLine();

signals:
    void Success_withdraw();
    void Failure_withdraw();
    void stock_tradable();
    void stock_untradable();
    void search_isdone();
    void not_enough_balance();
    void enongh_balance();
    void in_list();
    void not_in_list();
    void good_price();
    void bad_price();
    void not_enough_amount();
    void enough_amount();

public slots:
    void deposite_money();
    void withdraw_money();
    void stock_search();

    void stock_buy_amount_check();
    void stock_buy_price(); // record the plausible price in the Stock_buy_price.txt
    void stock_buy_name();

    void stock_sell_name();
    void stock_sell_price();
    void stock_search_inlist();
    void stock_sell_amount_check();

    void out_list();

};

#endif // MYLINE_H
