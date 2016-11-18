#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bankaccount.h"
#include "stockaccount.h"
#include <QString>
#include <vector>
#include "string.h"
#include "iostream"
#include "fstream"
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    makePlot();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::makePlot()
{

    vector<double> v;
    double value;
    string t1,t2,t3,t4,t5;
    int num =0;
    ifstream read_total("/Users/lunzhang/FinalPro/Total_Value_History.txt");
    while(read_total >> value>>t1>>t2>>t3>>t4>>t5)
    { v.push_back(value);
        num =num+1;
        //cout << num << endl;
    }

    double z[num];
    for (int i=0; i<num; i++) {
        z[i] = v.at(i);
    }
   double max = *std::max_element(z,z+num);

    // generate some data:
    QVector<double> x(num), y(num); // initialize with entries 0..100
    for (int i=0; i<num; ++i)
    {
      x[i] = i; // x goes from -1 to 1
      y[i] = z[i]; // let's plot a quadratic function
    }
    // create graph and assign data to it:
    ui->customplot->addGraph();
    ui->customplot->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->customplot->xAxis->setLabel("x");
    ui->customplot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->customplot->xAxis->setRange(0, num);
    ui->customplot->yAxis->setRange(0, 2*max);
    ui->customplot->replot();




}
