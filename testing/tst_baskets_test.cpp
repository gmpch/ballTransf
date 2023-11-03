#include <QtTest>
#include "../basket.h"

// add necessary includes here

class baskets_test : public QObject
{
    Q_OBJECT

public:
    baskets_test();
    ~baskets_test();
    Basket basket1 = Basket();
    Basket basket2 = Basket();

private slots:
    void addition_test();
    void substraction_test();
    void random_colors_test();

};

baskets_test::baskets_test()
{

}

baskets_test::~baskets_test()
{

}

void baskets_test::substraction_test()
{
    int basket1Sum = basket1.getBallsSum();
    int basket2Sum = basket2.getBallsSum();
    basket1.subRedBall();
    basket2.subRedBall();
    QCOMPARE(basket1.getBallsSum(), basket1Sum - 1);
    QCOMPARE(basket2.getBallsSum(), basket2Sum - 1);

}

void baskets_test::addition_test()
{
    int basket1Sum = basket1.getBallsSum();
    int basket2Sum = basket2.getBallsSum();
    basket1.addRedBall();
    basket2.addBlueBall();
    QCOMPARE(basket1.getBallsSum(), basket1Sum + 1);
    QCOMPARE(basket2.getBallsSum(), basket2Sum + 1);
}

void baskets_test::random_colors_test() {
    int basket1Reds = basket1.getRedBalls();
    int basket1Blues = basket1.getBlueBalls();
    int basket2Reds = basket2.getRedBalls();
    int basket2Blues = basket2.getBlueBalls();

    int rand1 = rand() % 30;
    int rand2 = rand() % 30;

    for (int i = 0; i < rand1; i++) {
        basket1.subRedBall();
        basket2.addBlueBall();
    }
    for (int i = 0; i < rand2; i++) {
        basket1.addBlueBall();
        basket2.subRedBall();
    }

    QCOMPARE(basket1.getRedBalls(), basket1Reds - rand1);
    QCOMPARE(basket1.getBlueBalls(), basket1Blues + rand2);
    QCOMPARE(basket2.getRedBalls(), basket2Reds - rand2);
    QCOMPARE(basket2.getBlueBalls(), basket2Blues + rand1);

}

QTEST_APPLESS_MAIN(baskets_test)

#include "tst_baskets_test.moc"
