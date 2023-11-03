#include "basket.h"
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <time.h>

Basket::Basket()
{
    redBalls = rand() % 100 + 10;
    blueBalls = rand() % 100 + 10;
    lastOperation = false;
}

int Basket::getRedBalls() {
    return redBalls;
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
    int choice = rand() % (redBalls + blueBalls);
    int ball = 0;
    if (redBalls > blueBalls) {
        if (choice > blueBalls)
            ball = 0;
        else
            ball = 1;
    }
    else if (redBalls == blueBalls){
        ball = rand() % 2;
    }
    else {
        if (choice > redBalls)
            ball = 1;
        else
            ball = 0;
    }


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

float Basket::getProbRed() {
    int sum = blueBalls + redBalls;
    float rez = static_cast<float>(redBalls) / sum * 100;
    return rez;
}

float Basket::getProbBlue() {
    int sum = blueBalls + redBalls;
    float rez = static_cast<float>(blueBalls) / sum * 100;
    return rez;
}

float Basket::getProbTwoRed() {
    float probFirst = getProbRed() / 100.0;
    float probSecond =  static_cast<float>(redBalls-1) / (blueBalls + (redBalls - 1));
    float rez = probFirst * probSecond;
    return rez;
}
float Basket::getProbTwoBlue() {
    float probFirst = getProbBlue() / 100.0;
    float probSecond =  static_cast<float>(blueBalls-1) / ((blueBalls-1) + redBalls);
    float rez = probFirst * probSecond;
    return rez;
}
float Basket::getProbOneRedOneBlue() {
    float prob1 = redBalls * blueBalls;
    float prob2 = (redBalls + blueBalls) * (redBalls + blueBalls - 1);
    float rez = prob1 / prob2;
    return rez;
}


