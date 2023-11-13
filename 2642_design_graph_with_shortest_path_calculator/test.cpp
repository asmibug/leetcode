#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

#define INSERT_TESTS(cls) \
UTEST(cls, 1) { \
    cls graph(4, {{0,2,5}, {0,1,2}, {1,2,1}, {3,0,3}}); \
    EXPECT_EQ(6, graph.shortestPath(3, 2)); \
    EXPECT_EQ(-1, graph.shortestPath(0, 3)); \
    graph.addEdge({1,3,4}); \
    EXPECT_EQ(6, graph.shortestPath(0, 3)); \
} \

INSERT_TESTS(GraphDijkstra)
INSERT_TESTS(GraphFloydWarshall)
INSERT_TESTS(GraphFloydWarshallOptimized)
