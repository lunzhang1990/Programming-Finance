#ifndef MYLABEL_H
#define MYLABEL_H

#include <QApplication>
#include <QString>
#include <QObject>
#include <QLabel>
class MyLabel: public QLabel
{
Q_OBJECT

public:
    MyLabel();

public slots:
    void renew_balance();
    void show_bank_history();
    void stock_price();
    void blank_label();
    void stock_tradable();
    void stock_untradable();
    void bad_price();
    void transactioin_success();
    void not_enough_balance();
    void out_list();
    void bad_put();
    void out_amount();
    void show_stock_transaction_history();
    void plot_of_portfolio_value();
    void show_current_portfolio();
};

#endif // MYLABEL_H
