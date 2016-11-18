#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    double Show_account_balance();
private slots:
    void makePlot();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
