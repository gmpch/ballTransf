#include "probabilityCalc.h"
#include "basket.h"


float ProbabilityCalc::getProbRed(Basket& basket) {
    if (basket.getBallsSum() == 0)
        return 0;
    float rez = static_cast<float>(basket.getRedBalls()) / basket.getBallsSum();
    return rez * 100;
}

float ProbabilityCalc::getProbBlue(Basket& basket) {
    if (basket.getBallsSum() == 0)
        return 0;
    float rez = static_cast<float>(basket.getBlueBalls()) / basket.getBallsSum();
    return rez * 100;
}

float ProbabilityCalc::getProbTwoRed(Basket& basket1, Basket& basket2) {
    if (basket1.getRedBalls() == 0)
        return getProbTwoRedSingle(basket2);
    else if (basket2.getRedBalls() == 0)
        return getProbTwoRedSingle(basket1);
    float rez = (0.5 * sDiv(basket1.getRedBalls(),basket1.getBallsSum()) * 0.5 *  sDiv(basket2.getRedBalls(),basket2.getBallsSum())) +
           (0.5 * sDiv(basket1.getRedBalls(),basket1.getBallsSum()) * 0.5 *  sDiv((basket1.getRedBalls() - 1),(basket1.getBallsSum() - 1))) +
           (0.5 * sDiv(basket2.getRedBalls(),basket2.getBallsSum()) * 0.5 *  sDiv((basket2.getRedBalls() - 1),(basket2.getBallsSum() - 1))) +
           (0.5 * sDiv(basket2.getRedBalls(),basket2.getBallsSum()) * 0.5 *  sDiv(basket1.getRedBalls(),basket1.getBallsSum()));
    return rez * 100;
}

float ProbabilityCalc::getProbTwoBlue(Basket& basket1, Basket& basket2) {
    if (basket1.getBlueBalls() == 0)
        return getProbTwoBlueSingle(basket2);
    else if (basket2.getBlueBalls() == 0)
        return getProbTwoBlueSingle(basket1);
    float rez = (0.5 * sDiv(basket1.getBlueBalls(),basket1.getBallsSum()) * 0.5 *  sDiv(basket2.getBlueBalls(),basket2.getBallsSum())) +
           (0.5 * sDiv(basket1.getBlueBalls(),basket1.getBallsSum()) * 0.5 *  sDiv((basket1.getBlueBalls() - 1),(basket1.getBallsSum() - 1))) +
           (0.5 * sDiv(basket2.getBlueBalls(),basket2.getBallsSum()) * 0.5 *  sDiv((basket2.getBlueBalls() - 1),(basket2.getBallsSum() - 1))) +
           (0.5 * sDiv(basket2.getBlueBalls(),basket2.getBallsSum()) * 0.5 *  sDiv(basket1.getBlueBalls(),basket1.getBallsSum()));
    return rez * 100;
}

float ProbabilityCalc::getProbOneBlueOneRed(Basket& basket1, Basket& basket2) {
    if (basket1.getBallsSum() == 0)
        return getProbOneBlueOneRedSingle(basket2);
    else if (basket2.getBallsSum() == 0)
        return getProbOneBlueOneRedSingle(basket1);
    float rez = (0.5 * sDiv(basket1.getRedBalls(),basket1.getBallsSum()) * 0.5 *  sDiv(basket2.getBlueBalls(),basket2.getBallsSum())) +
           (0.5 * sDiv(basket1.getBlueBalls(),basket1.getBallsSum()) * 0.5 *  sDiv(basket2.getRedBalls(),basket2.getBallsSum()));
    return rez * 100;
}

float ProbabilityCalc::getProbTwoRedSingle(Basket& basket){
    if (basket.getRedBalls() <= 1)
        return 0;
    float rez = 1.0 * basket.getRedBalls() / basket.getBallsSum() * ((1.0 * basket.getRedBalls() - 1) / (1.0 * basket.getBallsSum() - 1));
    return rez * 100;
}
float ProbabilityCalc::getProbTwoBlueSingle(Basket& basket){
    if (basket.getBlueBalls() <= 1)
        return 0;
    float rez = 1.0 * basket.getBlueBalls() / basket.getBallsSum() * ((1.0 * basket.getBlueBalls() - 1) / (1.0*basket.getBallsSum() - 1));
    return rez * 100;
}
float ProbabilityCalc::getProbOneBlueOneRedSingle(Basket& basket) {
    if (basket.getBallsSum() <= 1)
        return 0;
    float rez = 1.0 * basket.getRedBalls()/basket.getBallsSum() * basket.getBlueBalls() / (1.0 * basket.getBallsSum() - 1);
    return rez * 100;
}


float ProbabilityCalc::sDiv(int number1, int number2){
    float n1 = number1 * 1.0;
    float n2 = number2 * 1.0;
    return number2 == 0 ? 0 : n1/n2;
}

