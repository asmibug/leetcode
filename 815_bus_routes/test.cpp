#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

#define INSERT_TESTS(func) \
UTEST(func, 1) { \
    EXPECT_EQ(2, func({{1,2,7},{3,6,7}}, 1, 6)); \
} \
UTEST(func, 2) { \
    EXPECT_EQ(-1, func({{7,12},{4,5,15},{6},{15,19},{9,12,13}}, 15, 12)); \
} \
UTEST(func, 3) { \
    EXPECT_EQ(3, func({{10,13,22,28,32,35,43},{2,11,15,25,27}, \
                       {6,13,18,25,42}, {5,6,20,27,37,47},{7,11,19,23,35}, \
                       {7,11,17,25,31,43,46,48},{1,4,10,16,25,26,46}, \
                       {7,11},{3,9,19,20,21,24,32,45,46,49},{11,41}}, \
                      37, 43)); \
} \

INSERT_TESTS(GetNumBusesQueueStops)
INSERT_TESTS(GetNumBusesQueueRoutes)
INSERT_TESTS(GetNumBusesRoutesMatrix)
INSERT_TESTS(GetNumBusesBellmanFordMatrix)
INSERT_TESTS(GetNumBusesBellmanFord)
