#ifndef BASKET_H
#define BASKET_H


class Basket
{
public:
    Basket();
    int getRedBalls();
    int getBlueBalls();
    bool getLastOperation();
    int addRedBall();
    int addBlueBall();
    int subRedBall();
    int subBlueBall();
    float getProbRed();
    float getProbBlue();
    float getProbTwoRed();
    float getProbTwoBlue();
    float getProbOneRedOneBlue();
    int subRandBall();


private:
    int redBalls;
    int blueBalls;
    bool lastOperation;
};



#endif // BASKET_H
