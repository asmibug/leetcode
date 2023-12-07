#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

#define INSERT_TESTS(cls) \
UTEST(cls, 1) { \
    cls obj; \
    EXPECT_EQ(1, obj.next(100)); \
    EXPECT_EQ(1, obj.next(80)); \
    EXPECT_EQ(1, obj.next(60)); \
    EXPECT_EQ(2, obj.next(70)); \
    EXPECT_EQ(1, obj.next(60)); \
    EXPECT_EQ(4, obj.next(75)); \
    EXPECT_EQ(6, obj.next(85)); \
} \

INSERT_TESTS(StockSpannerBruteForce)
INSERT_TESTS(StockSpannerMap)
INSERT_TESTS(StockSpannerHeap)
INSERT_TESTS(StockSpannerStack)
INSERT_TESTS(StockSpannerHash)
