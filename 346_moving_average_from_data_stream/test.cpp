#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(MovingAverage, 1) {
    constexpr double eps = 1e-5;
    MovingAverage obj(3);
    EXPECT_NEAR(1.0, obj.next(1), eps);
    EXPECT_NEAR(5.5, obj.next(10), eps);
    EXPECT_NEAR(4.66667, obj.next(3), eps);
    EXPECT_NEAR(6.0, obj.next(5), eps);
}
