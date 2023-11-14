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

float ProbabilityCalc::getProbTwoRed(Basket& basket) {
    float firstRed = sDiv(basket.getRedBalls(), basket.getBallsSum());
    float secondRed = sDiv((basket.getRedBalls() - 1),(basket.getBallsSum()-1));
    return firstRed * secondRed;

}


float ProbabilityCalc::getProbTwoBlue(Basket& basket) {
    float firstBlue = sDiv(basket.getBlueBalls(), basket.getBallsSum());
    float secondBlue = sDiv((basket.getBlueBalls() - 1),(basket.getBallsSum()-1));
    return firstBlue * secondBlue;
}

float ProbabilityCalc::getProbTwoDif(Basket& basket) {
    float firstBall = sDiv(basket.getRedBalls(),basket.getBallsSum());
    float secondBall = sDiv((basket.getBlueBalls()),basket.getBallsSum() - 1);
    return firstBall * secondBall;
}



float ProbabilityCalc::getProbTwoRed(Basket& basket1, Basket& basket2) {
    if (basket1.getRedBalls() == 0)
        return getProbTwoRedSingle(basket2);
    else if (basket2.getRedBalls() == 0)
        return getProbTwoRedSingle(basket1);
    float rezRed = 0.25 * getProbTwoRed(basket1) + // вероятность достать 2 красных из первой корзины
                   0.25 * getProbTwoRed(basket2) + // вероятность достать 2 красных из второй
                   0.25 * getProbRed(basket1) * 0.01 * getProbRed(basket2) * 0.01 + // вероятность достать красный сначала из 1, потом к из 2
                   0.25 * getProbRed(basket2) * 0.01 * getProbRed(basket1) * 0.01; // вероятность достать красный сначала из 2, потом к из 1
    return rezRed * 100;
}

float ProbabilityCalc::getProbTwoBlue(Basket& basket1, Basket& basket2) {
    if (basket1.getBlueBalls() == 0)
        return getProbTwoBlueSingle(basket2);
    else if (basket2.getBlueBalls() == 0)
        return getProbTwoBlueSingle(basket1);
    float rezBlue = 0.25 * getProbTwoBlue(basket1) + // вероятность достать 2 синих из первой корзины
                    0.25 * getProbTwoBlue(basket2) + // вероятность достать 2 синих из второй корзины
                    0.25 * getProbBlue(basket1) * 0.01 * getProbBlue(basket2) * 0.01 + // вероятность достать синий сначала из 1, потом с из 2
                    0.25 * getProbBlue(basket2) * 0.01 * getProbBlue(basket1) * 0.01; // вероятность достать синий сначала из 2, потом с из 1
    return rezBlue * 100;
}

float ProbabilityCalc::getProbOneBlueOneRed(Basket& basket1, Basket& basket2) {
    if (basket1.getBallsSum() == 0)
        return getProbOneBlueOneRedSingle(basket2);
    else if (basket2.getBallsSum() == 0)
        return getProbOneBlueOneRedSingle(basket1);
    float rezMixed = 0.25 * getProbTwoDif(basket1) + // вероятность достать сначала красный из первой, потом синий из первой корзины
                     0.25 * getProbRed(basket1) * 0.01 * getProbBlue(basket2) * 0.01 + // вероятность достать сначала красный из первой, потом с из второй корзины
                     0.25 * getProbTwoDif(basket2) + // вероятность достать сначала красный из второй, потом с из второй корзины
                     0.25 * getProbRed(basket2) * 0.01 * getProbBlue(basket1) * 0.01; // вероятность достать сначала красный из второй, потом с из первой корзины
    return rezMixed * 100;
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

