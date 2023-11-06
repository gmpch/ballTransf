#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "basket.h"
#include "probabilityCalc.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void updateLabels();
    void onBucket1ButtonClicked();
    void onBucket2ButtonClicked();
    void onBucketsButtonClicked();
    void subIfExists(Basket& chosenBasket, Basket& secondBasket);
    Basket basket1;
    Basket basket2;
    ProbabilityCalc calc;
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
