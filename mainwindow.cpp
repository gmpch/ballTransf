#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "basket.h"
#include "probabilityCalc.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPushButton *basket1Button = ui->backet1_transfButton;
    QPushButton *basket2Button = ui->backet2_transfButton;
    QPushButton *basketsButton = ui->backets_get2BallsButton;
    connect(basket1Button, &QPushButton::clicked, this, &MainWindow::onBucket1ButtonClicked);
    connect(basket2Button, &QPushButton::clicked, this, &MainWindow::onBucket2ButtonClicked);
    connect(basketsButton, &QPushButton::clicked, this, &MainWindow::onBucketsButtonClicked);
    basket1 = Basket();
    basket2 = Basket();
    updateLabels();
}

void MainWindow::updateLabels() {
    ui->backet1_RedBallsLabel->setText("Красных шаров: " +  QString::number(basket1.getRedBalls()));
    ui->backet1_BlueBallsLabel->setText("Cиних шаров: " + QString::number(basket1.getBlueBalls()));
    ui->backet1_ballsLabel->setText("Всего шаров: " + QString::number(basket1.getRedBalls() + basket1.getBlueBalls()));
    ui->backet1_probRedLabel->setText("Вероятность достать красный: " + QString::number(calc.getProbRed(basket1)) + "%");
    ui->backet1_probBlueLabel->setText("Вероятность достать синий: " + QString::number(calc.getProbBlue(basket1)) + "%");


    ui->backet2_RedBallsLabel->setText("Красных шаров: " +  QString::number(basket2.getRedBalls()));
    ui->backet2_BlueBallsLabel->setText("Cиних шаров: " +QString::number(basket2.getBlueBalls()));
    ui->backet2_ballsLabel->setText("Всего шаров: " + QString::number(basket2.getRedBalls() + basket2.getBlueBalls()));
    ui->backet2_probRedLabel->setText("Вероятность достать красный: " + QString::number(calc.getProbRed(basket2)) + "%");
    ui->backet2_probBlueLabel->setText("Вероятность достать синий: " + QString::number(calc.getProbBlue(basket2)) + "%");


    ui->backets_prob2RedLabel->setText("Вероятность достать 2 синих шара: " + QString::number(calc.getProbTwoBlue(basket1, basket2)) + "%");
    ui->backets_prob2BlueLabel->setText("Вероятность достать 2 красных шара: " + QString::number(calc.getProbTwoRed(basket1, basket2)) + "%");
    ui->backets_prob1Blue1RedLabel->setText("Вероятность достать 1 синий и 1 красный: "+ QString::number(calc.getProbOneBlueOneRed(basket1, basket2)) + "%");

}

void MainWindow::onBucket1ButtonClicked()
{
    int ball = basket1.subRandBall();
    if (ball == 0){
        basket2.addRedBall();
        ui->backet1_lastOp->setText("Последнее действие: извлекли красный шар");
    }
    if (ball == 1){
        basket2.addBlueBall();
        ui->backet1_lastOp->setText("Последнее действие: извлекли синий шар");
    }
    updateLabels();
}

void MainWindow::onBucket2ButtonClicked()
{
    int ball = basket2.subRandBall();
    if (ball == 0){
        basket1.addRedBall();
        ui->backet2_lastOp->setText("Последнее действие: извлекли красный шар");
    }
    if (ball == 1){
        basket1.addBlueBall();
        ui->backet2_lastOp->setText("Последнее действие: извлекли синий шар");
    }
    updateLabels();
}

void MainWindow::onBucketsButtonClicked()
{
    int basketNumber = rand() % 2;    
    if (basketNumber == 0) {
        subIfExists(basket1, basket2);
    }
    else {
        subIfExists(basket2, basket1);
    }
    basketNumber = rand() % 2;
    if (basketNumber == 0) {
        subIfExists(basket1, basket2);
    }
    else {
        subIfExists(basket2, basket1);
    }
    updateLabels();
}

void MainWindow::subIfExists(Basket& chosenBasket, Basket& secondBasket) {
    if (chosenBasket.getBallsSum() == 0) {
        if (secondBasket.getBallsSum() != 0)
            secondBasket.subRandBall();
    }
    else {
        chosenBasket.subRandBall();
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}

