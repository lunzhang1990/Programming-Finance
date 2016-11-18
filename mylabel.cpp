#include "mylabel.h"
#include "bankaccount.h"
#include "stockaccount.h"
#include <QApplication>
#include <QString>
#include <QFile>
#include <QTextStream>
#include "mainwindow.h"

MyLabel::MyLabel()
{

}

void MyLabel::renew_balance()
{
    BankAccount* ba = new BankAccount;
    QString str1 = "$";
    QString str2 = QString::number(ba->GetBalance());

    this->setText(str1+str2);
    //cout <<ba->GetBalance()<< endl;
    delete ba;

   }
void MyLabel::show_bank_history()
{
    QFile file_bank_history("/Users/lunzhang/FinalPro/Bank_transaction_history.txt");
    file_bank_history.open(QIODevice::ReadOnly);
    QTextStream textstream_bank_history(&file_bank_history);
    QString str_bank_history = textstream_bank_history.readAll();
    //QLabel* label_bank_history = new QLabel;
    //label_bank_history->setText(str_bank_history);
    this->setText(str_bank_history);


}

void MyLabel::stock_price()
{
   QFile file1("/Users/lunzhang/FinalPro/One_stock.txt");
   file1.open(QIODevice::ReadOnly);
   QTextStream qtextstream1(&file1);
   QString stock_name;
   stock_name = qtextstream1.readAll();
   this->setText(stock_name);
}

void MyLabel::blank_label()
{

   this->setText(" ");
}

void MyLabel::stock_tradable()
{
  this->setText("The stock is tradable");
}

void MyLabel::stock_untradable()
{

this->setText("The stock is untradable");

}

void MyLabel::transactioin_success()
{
    this->setText("Successful transaction");

}

void MyLabel::not_enough_balance()
{

    this->setText("Not enough balance");
}

void MyLabel::bad_price()
{
    this->setText("The call price is not enough");

}

void MyLabel::out_list()
{

this->setText("You do not own the stock");

}

void MyLabel::bad_put()
{
    this->setText("The put price is too high");

}

void MyLabel::out_amount()
{
    this->setText("You do not have enough shares to sell");

}

void MyLabel::show_stock_transaction_history()
{
    QFile file_read("/Users/lunzhang/FinalPro/Stock_Transaction_History.txt");
    file_read.open(QIODevice::ReadOnly);
    QTextStream qtext(&file_read);
    QString qstr = qtext.readAll();
    this->setText(qstr);

}

void MyLabel::plot_of_portfolio_value()
{
    MainWindow* w = new MainWindow;
    w->show();

}

void MyLabel::show_current_portfolio()
{
  // read the balance
  double balance;
  BankAccount* ba= new BankAccount;
  balance = ba->get_total();
  QString s1("the balance is: ");
  QString num = QString::number(balance);



  // read the stock hold
  QFile file_read1("/Users/lunzhang/FinalPro/StockList.txt");
  file_read1.open(QIODevice::ReadOnly);
  QTextStream qtext2(&file_read1);
  QString qstr2 = qtext2.readAll();


  //read the total value of portfolio
  StockAccount *sa = new StockAccount;
  double total_stock = sa->get_total();
  double total = total_stock+balance;
  QString qtotal = QString::number(total);
  //set the content of the label
  this->setText(s1+"\n"+num+"\n"+qstr2+"\n"+qtotal);
  delete sa;
  delete ba;




}
