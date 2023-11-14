#ifndef PROBABILITYCALC_H
#define PROBABILITYCALC_H

#include "basket.h"

class ProbabilityCalc{
    public:
        float getProbOneBlueOneRed(Basket& basket1, Basket& basket2);
        float getProbTwoRed(Basket& basket1, Basket& basket2);
        float getProbTwoBlue(Basket& basket1, Basket& basket2);
        float getProbBlue(Basket& basket);
        float getProbRed(Basket& basket);
        float getProbTwoRedSingle(Basket& basket);
        float getProbTwoBlueSingle(Basket& basket);
        float getProbTwoRed(Basket& basket);
        float getProbTwoBlue(Basket& basket);
        float getProbTwoDifRed(Basket& basket1);
        float getProbTwoDifBlue(Basket& basket1);
        float getProbOneBlueOneRedSingle(Basket& basket);
        float sDiv(int number1, int number2);
};

#endif // PROBABILITYCALC_H


