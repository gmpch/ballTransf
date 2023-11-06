#ifndef BASKET_H
#define BASKET_H


class Basket
{
public:
    Basket();
    int getRedBalls();
    int getBlueBalls();
    int getBallsSum();
    bool getLastOperation();
    int addRedBall();
    int addBlueBall();
    int subRedBall();
    int subBlueBall();
    int subRandBall();


private:
    int redBalls;
    int blueBalls;
    bool lastOperation;
};



#endif // BASKET_H
