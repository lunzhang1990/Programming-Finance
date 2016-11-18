#include "mainwindow.h"
#include <QApplication>
#include "account.h"
#include "stock.h"
#include "stockaccount.h"
#include "bankaccount.h"
#include "iostream"
#include "iomanip"
#include <QTextStream>
#include <QFile>
#include <QString>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>

#include "mylabel.h"
#include "myline.h"

// name: lunzhang
// submission date: 2016/5/2



/*storage of data:
1.balance.txt : for balance on bankaccount
2.StockList.txt : to store the stocks owned by
3.Total_Porfolio.txt : store the history of total value of stock
4.Total_Value_Stock.txt : store the current value of stock list
5.Total_Value_History.txt : store the total porfolio value history
5.Total_Value.txt, Total_Porforlio.txt: abandoned*/






using namespace std;
int main(int argc, char *argv[])
{
   QApplication final(argc,argv);



   // test of mainwindows
   MainWindow w;
   //w.show();




   //****** Definitions of all windows ***** begin

   //*** Three main windows

   QWidget *Account_Window = new QWidget;
   Account_Window->setWindowTitle("Account  System");
   QWidget *Bank_Window = new QWidget;
   Bank_Window->setWindowTitle("Bank\n Account");
   QWidget *Stock_Window = new QWidget;
   Stock_Window->setWindowTitle("Stock Account");

  //*** Subwindows of stock account

   QWidget *Price_of_stock_window = new QWidget;
   Price_of_stock_window->setWindowTitle("Stock price");

   QWidget *Display_current_porfolio_window = new QWidget;
  Display_current_porfolio_window->setWindowTitle("Current Portfolio");

   QWidget *Buy_window = new QWidget;
   Buy_window->setWindowTitle("Buy shares");

   QWidget *Sell_window = new QWidget;
   Sell_window->setWindowTitle("Sell shares");

   QWidget *Graph_portfolio_value_window = new QWidget;
   Graph_portfolio_value_window->setWindowTitle("Graph of portfolio value");

   QWidget *Transaction_history_window = new QWidget;
   Transaction_history_window->setWindowTitle("Transaction history stock account");

   //*** Subwindows of bank account

   QWidget* Account_balance_window = new QWidget;
   Account_balance_window->setWindowTitle("Account balance");

   QWidget* Deposite_money_window = new QWidget;
   Deposite_money_window->setWindowTitle("Deposit money");

   QWidget* Withdraw_money_window = new QWidget;
   Withdraw_money_window->setWindowTitle("Withdraw money");

   QWidget* Print_out_history_window = new QWidget;
   Print_out_history_window->setWindowTitle("History of bank account");


 //*** Result windows


   QWidget* Result_window = new QWidget;
   Result_window->setWindowTitle("Show result");

//***** Definitions of all windows ***** end


//***** Account window ****** begin

   // The buttons on Account window, and layout

   QPushButton* Bank_Button = new QPushButton("Bank Account");
   QPushButton* Stock_Button = new QPushButton("Stock Account");
   QPushButton* Quit_Button = new QPushButton("Quit");



   // Layout of account window

   QVBoxLayout *layout_account = new QVBoxLayout;
   layout_account->addWidget(Bank_Button);
   layout_account->addWidget(Stock_Button);
   layout_account->addWidget(Quit_Button);
   Account_Window->setLayout(layout_account);


   //The connections on Account window: access to the bank and stock accounts
   QObject::connect(Bank_Button,SIGNAL(clicked()),Account_Window,SLOT(hide()));
   QObject::connect(Bank_Button,SIGNAL(clicked()),Bank_Window,SLOT(show()));
   QObject::connect(Stock_Button,SIGNAL(clicked()),Account_Window, SLOT(hide()));
   QObject::connect(Stock_Button,SIGNAL(clicked()),Stock_Window,SLOT(show()));
   QObject::connect(Quit_Button,SIGNAL(clicked()),&final,SLOT(quit()));

//***** Account window end


//***** Bank Account ****** begin

   //The buttons on bank account

   QPushButton* Account_balance = new QPushButton("Account balance");
   QPushButton* Deposite_money = new QPushButton("Deposite money");
   QPushButton* Withdraw_money = new QPushButton("Withdraw money");
   QPushButton* Print_out_history = new QPushButton("Print out history");

   //Layout of bank account window

   QVBoxLayout* layout_bank_accout = new QVBoxLayout;
   layout_bank_accout->addWidget(Account_balance);
   layout_bank_accout->addWidget(Deposite_money);
   layout_bank_accout->addWidget(Withdraw_money);
   layout_bank_accout->addWidget(Print_out_history);
   Bank_Window->setLayout(layout_bank_accout);

   //conncetions on bank account

   QObject::connect(Account_balance,SIGNAL(clicked()),Bank_Window,SLOT(hide()));
   QObject::connect(Account_balance,SIGNAL(clicked()),Account_balance_window,SLOT(show()));

   QObject::connect(Deposite_money,SIGNAL(clicked()),Bank_Window,SLOT(hide()));
   QObject::connect(Deposite_money,SIGNAL(clicked()),Deposite_money_window,SLOT(show()));

   QObject::connect(Withdraw_money,SIGNAL(clicked()),Bank_Window,SLOT(hide()));
   QObject::connect(Withdraw_money,SIGNAL(clicked()),Withdraw_money_window,SLOT(show()));

   QObject::connect(Print_out_history,SIGNAL(clicked()),Bank_Window,SLOT(hide()));
   QObject::connect(Print_out_history,SIGNAL(clicked()),Print_out_history_window,SLOT(show()));

//***** Bank Account ****** end



//***** Stock Account ***** begin

   //The buttons on stock account

   QPushButton* Price_of_stock = new QPushButton("Price of a Stock");
   QPushButton* Display_current_porfolio = new QPushButton("Current Portfolio");
   QPushButton* Buy = new QPushButton("Buy");
   QPushButton* Sell = new QPushButton("Sell");
   QPushButton* Graph_portfolio_value = new QPushButton("Veiw graph of porforlio value");
   QPushButton* Transaction_history = new QPushButton("Transaction history");

   //Layout of stock account window

   QVBoxLayout *layout_stock_account = new QVBoxLayout;
   layout_stock_account->addWidget(Price_of_stock);
   layout_stock_account->addWidget(Display_current_porfolio);
   layout_stock_account->addWidget(Buy);
   layout_stock_account->addWidget(Sell);
   layout_stock_account->addWidget(Graph_portfolio_value);
   layout_stock_account->addWidget(Transaction_history);
   Stock_Window->setLayout(layout_stock_account);




   // conncetions on stock account

   QObject::connect(Price_of_stock,SIGNAL(clicked()),Stock_Window,SLOT(hide()));
   QObject::connect(Price_of_stock,SIGNAL(clicked()),Price_of_stock_window,SLOT(show()));

   QObject::connect(Display_current_porfolio,SIGNAL(clicked()),Stock_Window,SLOT(hide()));
   QObject::connect(Display_current_porfolio,SIGNAL(clicked()),Display_current_porfolio_window,SLOT(show()));

   QObject::connect(Buy,SIGNAL(clicked()),Stock_Window,SLOT(hide()));
   QObject::connect(Buy,SIGNAL(clicked()),Buy_window,SLOT(show()));

   QObject::connect(Sell,SIGNAL(clicked()),Stock_Window,SLOT(hide()));
   QObject::connect(Sell,SIGNAL(clicked()),Sell_window,SLOT(show()));

   QObject::connect(Graph_portfolio_value,SIGNAL(clicked()),Stock_Window,SLOT(hide()));
   QObject::connect(Graph_portfolio_value,SIGNAL(clicked()),Graph_portfolio_value_window,SLOT(show()));

   QObject::connect(Transaction_history,SIGNAL(clicked()),Stock_Window,SLOT(hide()));
   QObject::connect(Transaction_history,SIGNAL(clicked()),Transaction_history_window,SLOT(show()));

//***** Stock Account ***** end



 //**** The bank balance window begin
     //: one balance label and one back button b


   //** two Widgets
   QPushButton* Back_buttion = new QPushButton("Back");
   MyLabel* mylabel = new MyLabel;

   //** Layout
   QVBoxLayout* layout_balance = new QVBoxLayout;
   layout_balance->addWidget(mylabel);
   layout_balance->addWidget(Back_buttion);
   Account_balance_window->setLayout(layout_balance);
   //** connections

   QObject::connect(Account_balance,SIGNAL(clicked()),mylabel,SLOT(renew_balance()));

   QObject::connect(Back_buttion,SIGNAL(clicked()),Account_Window,SLOT(show()));
   QObject::connect(Back_buttion,SIGNAL(clicked()),Account_balance_window,SLOT(hide()));
   QObject::connect(Back_buttion,SIGNAL(clicked()),mylabel,SLOT(show()));
//**** The bank balance window end

//*** The Deposite window begin
   //: one subwindow to show the action success

    //** The deposite terminal window
   QWidget* deposite_terminal_window =new QWidget;
   QLabel* deposite_terminal_label = new QLabel;
   deposite_terminal_label->setText("Successful deposite");
   QPushButton* deposite_terminal_button = new QPushButton("Back");
   QVBoxLayout* deposite_terminal_layout = new QVBoxLayout;
   deposite_terminal_layout->addWidget(deposite_terminal_label);
   deposite_terminal_layout->addWidget(deposite_terminal_button);
   deposite_terminal_window->setLayout(deposite_terminal_layout);

   //** Three widgets
   QLabel* deposite_info = new QLabel;
   deposite_info->setText("How much do you want to deposite");
   MyLine* deposite_line = new MyLine;
   QPushButton* deposite_button = new QPushButton("Depostie");
    //** Layout
   QVBoxLayout* deposite_layout = new QVBoxLayout;
   deposite_layout->addWidget(deposite_info);
   deposite_layout->addWidget(deposite_line);
   deposite_layout->addWidget(deposite_button);
   Deposite_money_window->setLayout(deposite_layout);

    //** Connections

   QObject::connect(Deposite_money,SIGNAL(clicked()),Deposite_money_window,SLOT(show()));

   QObject::connect(deposite_button,SIGNAL(clicked()),deposite_line,SLOT(deposite_money()));
   QObject::connect(deposite_button,SIGNAL(clicked()),Deposite_money_window,SLOT(hide()));
   QObject::connect(deposite_button,SIGNAL(clicked()),deposite_terminal_window,SLOT(show()));

   QObject::connect(deposite_terminal_button, SIGNAL(clicked()),deposite_terminal_window,SLOT(hide()));
   QObject::connect(deposite_terminal_button, SIGNAL(clicked()),Account_Window,SLOT(show()));
//*** The Deposite window end

   //*** The Withdraw window begin:
    //one subwindow to show the action success

    //** Two withdraw terminal windows: success and failure
     // success
   QWidget* withdraw_terminal_window_success =new QWidget;
   QLabel* withdraw_terminal_label_success = new QLabel;
   withdraw_terminal_label_success->setText("Successful withdraw");
   QPushButton* withdraw_terminal_button_success = new QPushButton("Back");
   QVBoxLayout* withdraw_terminal_layout_success = new QVBoxLayout;
   withdraw_terminal_layout_success->addWidget(withdraw_terminal_label_success);
   withdraw_terminal_layout_success->addWidget(withdraw_terminal_button_success);
   withdraw_terminal_window_success->setLayout(withdraw_terminal_layout_success);
     // failure
   QWidget* withdraw_terminal_window_failure =new QWidget;
   QLabel* withdraw_terminal_label_failure = new QLabel;
   withdraw_terminal_label_failure->setText("Failed deposite");
   QPushButton* withdraw_terminal_button_failure = new QPushButton("Back");
   QVBoxLayout* withdraw_terminal_layout_failure = new QVBoxLayout;
   withdraw_terminal_layout_failure->addWidget(withdraw_terminal_label_failure);
   withdraw_terminal_layout_failure->addWidget(withdraw_terminal_button_failure);
   withdraw_terminal_window_failure->setLayout(withdraw_terminal_layout_failure);

   //** Three widgets
   QLabel* withdraw_info = new QLabel;
   deposite_info->setText("How much do you want to withdraw");
   MyLine* withdraw_line = new MyLine;
   QPushButton* withdraw_button = new QPushButton("Withdraw");
    //** Layout
   QVBoxLayout* withdraw_layout = new QVBoxLayout;
   withdraw_layout->addWidget(withdraw_info);
   withdraw_layout->addWidget(withdraw_line);
   withdraw_layout->addWidget(withdraw_button);
   Withdraw_money_window->setLayout(withdraw_layout);

    //** Connections

   QObject::connect(Withdraw_money,SIGNAL(clicked()),Withdraw_money_window,SLOT(show()));

   QObject::connect(withdraw_button,SIGNAL(clicked()),withdraw_line,SLOT(withdraw_money()));
   QObject::connect(withdraw_button,SIGNAL(clicked()),Withdraw_money_window,SLOT(hide()));
   //QObject::connect(withdraw_button,SIGNAL(clicked()),withdraw_terminal_window_success,SLOT(show()));

   QObject::connect(withdraw_line,SIGNAL(Success_withdraw()),withdraw_terminal_window_success,SLOT(show()));
   QObject::connect(withdraw_line,SIGNAL(Failure_withdraw()),withdraw_terminal_window_failure,SLOT(show()));

   QObject::connect(withdraw_terminal_button_success, SIGNAL(clicked()),withdraw_terminal_window_success,SLOT(hide()));
   QObject::connect(withdraw_terminal_button_failure, SIGNAL(clicked()),withdraw_terminal_window_failure,SLOT(hide()));
   QObject::connect(withdraw_terminal_button_success, SIGNAL(clicked()),Account_Window,SLOT(show()));
   QObject::connect(withdraw_terminal_button_failure, SIGNAL(clicked()),Account_Window,SLOT(show()));
//*** The Withdraw window end
//  QObject::connect(Display_current_porfolio,SIGNAL(clicked()),Display_current_porfolio_window,SLOT(show()));

   MyLabel* label_display_current_porfolio = new MyLabel;
   QPushButton* button_display_current_portfolio = new QPushButton("Back");

   QVBoxLayout* layout_current_portfolio = new QVBoxLayout;
   layout_current_portfolio->addWidget(label_display_current_porfolio);
   layout_current_portfolio->addWidget(button_display_current_portfolio);
   Display_current_porfolio_window->setLayout(layout_current_portfolio);



   QObject::connect(Display_current_porfolio,SIGNAL(clicked()),label_display_current_porfolio,SLOT(show_current_portfolio()));

   QObject::connect(button_display_current_portfolio,SIGNAL(clicked()),Display_current_porfolio_window,SLOT(hide()));
   QObject::connect(button_display_current_portfolio,SIGNAL(clicked()),Account_Window,SLOT(show()));













//*** window of show bank transaction history begin
   //:Print_out_history_window, Print_out_history (the button) ,/Users/lunzhang/FinalPro/Bank_transaction_history.txt,

   // to read the data from /Users/lunzhang/FinalPro/Bank_transaction_history.txt
   QFile file_bank_history("/Users/lunzhang/FinalPro/Bank_transaction_history.txt");
   file_bank_history.open(QIODevice::ReadOnly);
   QTextStream textstream_bank_history(&file_bank_history);
   QString str_bank_history = textstream_bank_history.readAll();
   // the label to show history and back label
   MyLabel* label_bank_history = new MyLabel;
   QPushButton*  button_bank_history_back = new QPushButton("Back");
   //layout of window
   QVBoxLayout* layout_bank_history = new QVBoxLayout;
   layout_bank_history->addWidget(label_bank_history);
   layout_bank_history->addWidget(button_bank_history_back);
   Print_out_history_window->setLayout(layout_bank_history);

   //the connections
   QObject::connect(Print_out_history,SIGNAL(clicked()),label_bank_history,SLOT(show_bank_history()));
   QObject::connect(button_bank_history_back,SIGNAL(clicked()),Print_out_history_window,SLOT(hide()));
   QObject::connect(button_bank_history_back,SIGNAL(clicked()),Account_Window,SLOT(show()));




   //*** Show stock price window:
   //QWidget* stock_name_window = new QWidget;
   Price_of_stock_window->setWindowTitle("Name of stock");

   //One result windows to show whether the tradable and price
   QWidget* stock_name_result_window = new QWidget;
   MyLabel*  stock_name_result_label_trade = new MyLabel;
   MyLabel*  stock_name_result_label_price = new MyLabel;
   QPushButton* stock_name_back_button = new QPushButton("Back");

   //layout of result window
   QVBoxLayout* layout_stock_name_result_window = new QVBoxLayout;
   layout_stock_name_result_window->addWidget(stock_name_result_label_trade);
   layout_stock_name_result_window->addWidget(stock_name_result_label_price);
   layout_stock_name_result_window->addWidget(stock_name_back_button);
   stock_name_result_window->setLayout(layout_stock_name_result_window);

   //connections on the result window
   QObject::connect(stock_name_back_button,SIGNAL(clicked()),stock_name_result_window,SLOT(hide()));
   QObject::connect(stock_name_back_button,SIGNAL(clicked()),Account_Window,SLOT(show()));



   //**one label, one lineedit for entring name and one button
   QLabel* stock_name_window_label =new QLabel;
   stock_name_window_label->setText("Input the name of the stock");
   MyLine* stock_name_line = new MyLine;
   QPushButton* stock_name_search_button = new QPushButton("Go");


//** layout of stock price window
   QVBoxLayout* layout_stock_price_window =new QVBoxLayout;
   layout_stock_price_window->addWidget(stock_name_window_label);
   layout_stock_price_window->addWidget(stock_name_line);
   layout_stock_price_window->addWidget(stock_name_search_button);
   Price_of_stock_window->setLayout(layout_stock_price_window);

   //** connections
   QObject::connect(stock_name_search_button,SIGNAL(clicked()),Price_of_stock_window,SLOT(hide()));
   QObject::connect(stock_name_search_button,SIGNAL(clicked()),stock_name_line,SLOT(stock_search()));

   QObject::connect(stock_name_line,SIGNAL(stock_tradable()),stock_name_result_label_trade,SLOT(stock_tradable()));
   QObject::connect(stock_name_line,SIGNAL(stock_untradable()),stock_name_result_label_trade,SLOT(stock_untradable()));
   QObject::connect(stock_name_line,SIGNAL(stock_tradable()),stock_name_result_label_price,SLOT(stock_price()));
   QObject::connect(stock_name_line,SIGNAL(stock_untradable()),stock_name_result_label_price,SLOT(blank_label()));

   QObject::connect(stock_name_search_button,SIGNAL(clicked()),stock_name_result_window,SLOT(show()));

   void stock_tradable();
   void stock_untradable();

//*** current porrfolio window begin






//*** current portfolio window end


//*** window of buy stock: Buy_window
   //** Widgets: two labels and two lines and one button and subwindows
   QLabel* label_buy_stock_name = new QLabel("The name of stock want to buy");
   MyLine* line_buy_stock_name = new MyLine;
   QLabel* label_buy_stock_price = new QLabel("The price you offer");
   MyLine* line_buy_stock_price = new MyLine;
   QLabel* label_buy_stock_amount = new QLabel("The amount you want to buy");
   MyLine* line_buy_stock_amount = new MyLine;
   QPushButton* button_buy_stock_result_go =new QPushButton("Buy");

   //subwindows to show whether buy is plausible or not
   QWidget* window_stock_buy_result = new QWidget;
   MyLabel* label_stock_buy_result = new MyLabel;
   QPushButton* button_stock_buy_resault_back = new QPushButton("Back");
   QVBoxLayout* layout_buy_stock_result = new QVBoxLayout;
   layout_buy_stock_result->addWidget(label_stock_buy_result);
   layout_buy_stock_result->addWidget(button_stock_buy_resault_back);
   window_stock_buy_result->setLayout(layout_buy_stock_result);
   //connections: back
   QObject::connect(button_stock_buy_resault_back,SIGNAL(clicked()),window_stock_buy_result,SLOT(hide()));
   QObject::connect(button_stock_buy_resault_back,SIGNAL(clicked()),Account_Window,SLOT(show()));

   //layout of buy_window
   QVBoxLayout* layout_buy_stock =new QVBoxLayout;
   layout_buy_stock->addWidget(label_buy_stock_name);
   layout_buy_stock->addWidget(line_buy_stock_name);
   layout_buy_stock->addWidget(label_buy_stock_price);
   layout_buy_stock->addWidget(line_buy_stock_price);
   layout_buy_stock->addWidget(label_buy_stock_amount);
   layout_buy_stock->addWidget(line_buy_stock_amount);

   layout_buy_stock->addWidget(button_buy_stock_result_go);
   Buy_window->setLayout(layout_buy_stock);
  // conncections
   QObject::connect(button_buy_stock_result_go,SIGNAL(clicked()),Buy_window,SLOT(hide()));
   QObject::connect(button_buy_stock_result_go,SIGNAL(clicked()),line_buy_stock_name,SLOT(stock_buy_name()));

   QObject::connect(line_buy_stock_name,SIGNAL(stock_untradable()),label_stock_buy_result,SLOT(stock_untradable()));

   QObject::connect(line_buy_stock_name,SIGNAL(stock_tradable()),line_buy_stock_price,SLOT(stock_buy_price()));
   QObject::connect(line_buy_stock_price,SIGNAL(bad_price()),label_stock_buy_result,SLOT(bad_price()));
   QObject::connect(line_buy_stock_price,SIGNAL(good_price()),line_buy_stock_amount,SLOT(stock_buy_amount_check()));

   QObject::connect(line_buy_stock_amount,SIGNAL(not_enough_balance()),label_stock_buy_result,SLOT(not_enough_balance()));
   QObject::connect(line_buy_stock_amount,SIGNAL(enongh_balance()),label_stock_buy_result,SLOT(transactioin_success()));

   QObject::connect(button_buy_stock_result_go,SIGNAL(clicked()),window_stock_buy_result,SLOT(show()));

//****** window of sell stock

   //*** window of sell stock: Buy_window
      //** Widgets: two labels and two lines and one button and subwindows
      QLabel* label_sell_stock_name = new QLabel("The name of stock want to sell");
      MyLine* line_sell_stock_name = new MyLine;
      QLabel* label_sell_stock_price = new QLabel("The price you want to sell");
      MyLine* line_sell_stock_price = new MyLine;
      QLabel* label_sell_stock_amount = new QLabel("The amount you want to sell");
      MyLine* line_sell_stock_amount = new MyLine;
      QPushButton* button_sell_stock_result_go =new QPushButton("Sell");

      //subwindows to show whether buy is plausible or not
      QWidget* window_stock_sell_result = new QWidget;
      MyLabel* label_stock_sell_result = new MyLabel;
      QPushButton* button_stock_sell_resault_back = new QPushButton("Back");
      QVBoxLayout* layout_sell_stock_result = new QVBoxLayout;
      layout_sell_stock_result->addWidget(label_stock_sell_result);
      layout_sell_stock_result->addWidget(button_stock_sell_resault_back);
      window_stock_sell_result->setLayout(layout_sell_stock_result);
      //connections: back
      QObject::connect(button_stock_sell_resault_back,SIGNAL(clicked()),window_stock_sell_result,SLOT(hide()));
      QObject::connect(button_stock_sell_resault_back,SIGNAL(clicked()),Account_Window,SLOT(show()));

      //layout of sell_window
      QVBoxLayout* layout_sell_stock =new QVBoxLayout;
      layout_sell_stock->addWidget(label_sell_stock_name);
      layout_sell_stock->addWidget(line_sell_stock_name);
      layout_sell_stock->addWidget(label_sell_stock_price);
      layout_sell_stock->addWidget(line_sell_stock_price);
      layout_sell_stock->addWidget(label_sell_stock_amount);
      layout_sell_stock->addWidget(line_sell_stock_amount);
      layout_sell_stock->addWidget(button_sell_stock_result_go);

      Sell_window->setLayout(layout_sell_stock);

      // conncections
      QObject::connect(button_sell_stock_result_go,SIGNAL(clicked()),Sell_window,SLOT(hide()));
      QObject::connect(button_sell_stock_result_go,SIGNAL(clicked()),window_stock_sell_result,SLOT(show()));
      QObject::connect(button_sell_stock_result_go,SIGNAL(clicked()),line_sell_stock_name,SLOT(stock_search_inlist()));


      QObject::connect(line_sell_stock_name,SIGNAL(not_in_list()),label_stock_sell_result,SLOT(out_list()));

      QObject::connect(line_sell_stock_name,SIGNAL(in_list()),line_sell_stock_name,SLOT(stock_sell_name()));
      QObject::connect(line_sell_stock_name,SIGNAL(in_list()),line_sell_stock_price,SLOT(stock_sell_price()));

      QObject::connect(line_sell_stock_price,SIGNAL(bad_price()),label_stock_sell_result,SLOT(bad_put()));
      QObject::connect(line_sell_stock_price,SIGNAL(good_price()),line_sell_stock_amount,SLOT(stock_sell_amount_check()));

      QObject::connect(line_sell_stock_amount,SIGNAL(enough_amount()),label_stock_sell_result,SLOT(transactioin_success()));
      QObject::connect(line_sell_stock_amount,SIGNAL(not_enough_amount()),label_stock_sell_result,SLOT(out_amount()));

      QObject::connect(button_sell_stock_result_go,SIGNAL(clicked()),window_stock_sell_result,SLOT(show()));

//window of porfolio value


 // Transaction_history, Transaction_history_window
// window of history transaction: one back botton

   MyLabel* label_stock_transaction_result = new MyLabel;
   QPushButton* button_stock_transaction_result = new QPushButton("Back");

   //layout
   QVBoxLayout* layout_stock_transaction_result = new QVBoxLayout;
   layout_stock_transaction_result->addWidget(label_stock_transaction_result);
   layout_stock_transaction_result->addWidget(button_stock_transaction_result);
   Transaction_history_window->setLayout(layout_stock_transaction_result);

   //connections


   QObject::connect(Transaction_history,SIGNAL(clicked()),label_stock_transaction_result,SLOT(show_stock_transaction_history()));




   QObject::connect(button_stock_transaction_result,SIGNAL(clicked()),Transaction_history_window,SLOT(hide()));
   QObject::connect(button_stock_transaction_result,SIGNAL(clicked()),Account_Window,SLOT(show()));



    /*StockAccount* sa;
    sa->plot_portfolio_value();*/

//**** Graph of portfolio value
   //one window for the stock graph window with back button, the other window with the
   //qcustomgraph picture
   //QObject::connect(Graph_portfolio_value,SIGNAL(clicked()),Graph_portfolio_value_window,SLOT(show()));
   QPushButton* button_Graph_portfolio_value_window_back = new QPushButton("Back");
   MyLabel* label_Graph_portfolio_value_window = new MyLabel;
   label_Graph_portfolio_value_window->setText("The graph of portfolio value");
   QVBoxLayout* layout_Graph_portfolio_value_window = new QVBoxLayout;
   layout_Graph_portfolio_value_window->addWidget(label_Graph_portfolio_value_window);
   layout_Graph_portfolio_value_window->addWidget(button_Graph_portfolio_value_window_back);
   Graph_portfolio_value_window->setLayout(layout_Graph_portfolio_value_window);


   //connections
   // QObject::connect(Graph_portfolio_value,SIGNAL(clicked()),&w,SLOT(show()));

   QObject::connect(Graph_portfolio_value,SIGNAL(clicked()),label_Graph_portfolio_value_window,SLOT(plot_of_portfolio_value()));
   QObject::connect(button_Graph_portfolio_value_window_back,SIGNAL(clicked()),Account_Window,SLOT(show()));
   QObject::connect(button_Graph_portfolio_value_window_back,SIGNAL(clicked()),Graph_portfolio_value_window,SLOT(hide()));



   Account_Window->show();
   return final.exec();


}


/*
void MainMenu()
{
    cout <<"Welcome to the Account Management"<< endl;
    cout << "Select the account to access"<< endl;
    cout << "1.Stock Portfolio Account"<< endl;
    cout << "2.Bank Account"<< endl;
    cout << "3.Exit"<< endl;

}

void SaccountMenu()
{
    cout << "Stock Portfolio Account" << endl;
    cout << "Select an option"<< endl;
    cout << "1.Display the price for a stock"<< endl;
    cout << "2.Display the current portfolio" << endl;
    cout << "3.Buy shares" << endl;
    cout << "4.Sell shares"<< endl;
    cout << "5.View a graph for the portfolio value"<<endl;
    cout << "6.View transaction history"<< endl;
    cout << "7.Return to previous menu" << endl;

}

void BaccountMenu()
{
    cout << ".Bank Account"<< endl;
    cout << "1.View account balance"<< endl;
    cout << "2.Deposit Money "<< endl;
    cout << "3.Withdraw Money"<< endl;
    cout << "4.Print out history"<< endl;
    cout << "5.Return to the previous menu"<< endl;

}*/
