#include "lib.cpp"

#include "utest.h"

UTEST(GetMinCostToConnectKruskal, 1) {
    std::vector<std::vector<int>> points = {{0, 0}};
    EXPECT_EQ(0, GetMinCostToConnectKruskal(points));
}

UTEST(GetMinCostToConnectKruskal, 2) {
    std::vector<std::vector<int>> points = {{0, 0}, {1, 0}};
    EXPECT_EQ(1, GetMinCostToConnectKruskal(points));
}

UTEST(GetMinCostToConnectKruskal, 3) {
    std::vector<std::vector<int>> points = {{3, 12}, {-2, 5}, {-4, 1}};
    EXPECT_EQ(18, GetMinCostToConnectKruskal(points));
}

UTEST(GetMinCostToConnectKruskal, 4) {
    std::vector<std::vector<int>> points = {
        {2, -3}, {-17, -8}, {13, 8}, {-17, -15}};
    EXPECT_EQ(53, GetMinCostToConnectKruskal(points));
}

UTEST(GetMinCostToConnectKruskal, 5) {
    std::vector<std::vector<int>> points = {
        {0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    EXPECT_EQ(20, GetMinCostToConnectKruskal(points));
}

UTEST(GetMinCostToConnectPrim, 1) {
    std::vector<std::vector<int>> points = {{0, 0}};
    EXPECT_EQ(0, GetMinCostToConnectPrim(points));
}

UTEST(GetMinCostToConnectPrim, 2) {
    std::vector<std::vector<int>> points = {{0, 0}, {1, 0}};
    EXPECT_EQ(1, GetMinCostToConnectPrim(points));
}

UTEST(GetMinCostToConnectPrim, 3) {
    std::vector<std::vector<int>> points = {{3, 12}, {-2, 5}, {-4, 1}};
    EXPECT_EQ(18, GetMinCostToConnectPrim(points));
}

UTEST(GetMinCostToConnectPrim, 4) {
    std::vector<std::vector<int>> points = {
        {2, -3}, {-17, -8}, {13, 8}, {-17, -15}};
    EXPECT_EQ(53, GetMinCostToConnectPrim(points));
}

UTEST(GetMinCostToConnectPrim, 5) {
    std::vector<std::vector<int>> points = {
        {0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    EXPECT_EQ(20, GetMinCostToConnectPrim(points));
}

UTEST_MAIN()
