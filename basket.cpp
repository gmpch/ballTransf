#include "basket.h"
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <stdio.h>

Basket::Basket()
{
    redBalls = rand() % 50 + 10;
    blueBalls = rand() % 50 + 10;
    lastOperation = false;
}

int Basket::getRedBalls() {
    return redBalls;
}

int Basket::getBallsSum() {
    return redBalls + blueBalls;
}

int Basket::getBlueBalls() {
    return blueBalls;
}

bool Basket::getLastOperation() {
    return lastOperation;
}

int Basket::addRedBall() {
    return redBalls++;
}

int Basket::addBlueBall() {
    return blueBalls++;
}
int Basket::subRedBall() {
    if (redBalls > 0) {
       return redBalls--;
    }
    return redBalls;
}
int Basket::subBlueBall() {
    if (blueBalls > 0) {
       return blueBalls--;
    }
    return blueBalls;

}

int Basket::subRandBall() {
    if (getBallsSum() == 0)
        return -1;
    int choice = rand() % (redBalls + blueBalls);
    bool ball = 0;
    if (choice > blueBalls)
        ball = 0;
    else
        ball = 1;


    if (ball == 0) {
        if (redBalls > 0){
            subRedBall();
            return 0;
        }
        else {
            if (blueBalls > 0)
            {
                subBlueBall();
                return 1;
            }
        }
    }
    else {
        if (blueBalls > 0)
        {
            subBlueBall();
            return 1;
        }
        else {
            if (redBalls > 0){
                subRedBall();
                return 0;
            }
        }
    }
    return -1;
}

