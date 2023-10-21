#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(GetMaxSumMaxQueue, 1) {
    EXPECT_EQ(37, GetMaxSumMaxQueue<MaxQueue>({10,2,-10,5,20}, 2));
    EXPECT_EQ(37, GetMaxSumMaxQueue<MaxQueueD>({10,2,-10,5,20}, 2));
}

UTEST(GetMaxSumMaxQueue, 2) {
    EXPECT_EQ(-1, GetMaxSumMaxQueue<MaxQueue>({-1,-2,-3}, 1));
    EXPECT_EQ(-1, GetMaxSumMaxQueue<MaxQueueD>({-1,-2,-3}, 1));
}

UTEST(GetMaxSumMaxQueue, 3) {
    EXPECT_EQ(23, GetMaxSumMaxQueue<MaxQueue>({10,-2,-10,-5,20}, 2));
    EXPECT_EQ(23, GetMaxSumMaxQueue<MaxQueueD>({10,-2,-10,-5,20}, 2));
}

UTEST(GetMaxSumMaxQueue, 4) {
    EXPECT_EQ(11355, GetMaxSumMaxQueue<MaxQueue>({-5266,4019,7336,-3681,-5767}, 2));
    EXPECT_EQ(11355, GetMaxSumMaxQueue<MaxQueueD>({-5266,4019,7336,-3681,-5767}, 2));
}


UTEST(GetMaxSumHeap, 1) {
    EXPECT_EQ(37, GetMaxSumHeap({10,2,-10,5,20}, 2));
}

UTEST(GetMaxSumHeap, 2) {
    EXPECT_EQ(-1, GetMaxSumHeap({-1,-2,-3}, 1));
}

UTEST(GetMaxSumHeap, 3) {
    EXPECT_EQ(23, GetMaxSumHeap({10,-2,-10,-5,20}, 2));
}

UTEST(GetMaxSumHeap, 4) {
    EXPECT_EQ(11355, GetMaxSumHeap({-5266,4019,7336,-3681,-5767}, 2));
}


UTEST(GetMaxSumTree, 1) {
    EXPECT_EQ(37, GetMaxSumTree({10,2,-10,5,20}, 2));
}

UTEST(GetMaxSumTree, 2) {
    EXPECT_EQ(-1, GetMaxSumTree({-1,-2,-3}, 1));
}

UTEST(GetMaxSumTree, 3) {
    EXPECT_EQ(23, GetMaxSumTree({10,-2,-10,-5,20}, 2));
}

UTEST(GetMaxSumTree, 4) {
    EXPECT_EQ(11355, GetMaxSumTree({-5266,4019,7336,-3681,-5767}, 2));
}


UTEST(GetMaxSumMonotonousQueue, 1) {
    EXPECT_EQ(37, GetMaxSumMonotonousQueue({10,2,-10,5,20}, 2));
}

UTEST(GetMaxSumMonotonousQueue, 2) {
    EXPECT_EQ(-1, GetMaxSumMonotonousQueue({-1,-2,-3}, 1));
}

UTEST(GetMaxSumMonotonousQueue, 3) {
    EXPECT_EQ(23, GetMaxSumMonotonousQueue({10,-2,-10,-5,20}, 2));
}

UTEST(GetMaxSumMonotonousQueue, 4) {
    EXPECT_EQ(11355, GetMaxSumMonotonousQueue({-5266,4019,7336,-3681,-5767}, 2));
}
