#include "lib.cpp"

#include <sstream>

#include "utest.h"

std::string ItineraryToString(const std::vector<std::string>& itinerary) {
    if (itinerary.empty()) {
        return "";
    }
    std::ostringstream str;
    str << itinerary[0];
    for (unsigned i = 1; i < itinerary.size(); ++i) {
        str << "," << itinerary[i];
    }
    return str.str();
}

UTEST(FindItinerarySlow, Linear) {
    std::vector<std::vector<std::string>> tickets = {
        {"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    std::vector<std::string> expected = {"JFK", "MUC", "LHR", "SFO", "SJC"};
    std::vector<std::string> result = FindItinerarySlow(tickets);
    std::string expected_str = ItineraryToString(expected);
    std::string result_str = ItineraryToString(result);
    EXPECT_STREQ(expected_str.c_str(), result_str.c_str());
}

UTEST(FindItinerarySlow, TwoPossible) {
    std::vector<std::vector<std::string>> tickets = {
        {"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"}, {"ATL", "JFK"},
        {"ATL", "SFO"}};
    std::vector<std::string> expected = {
        {"JFK", "ATL", "JFK", "SFO", "ATL", "SFO"}};
    auto result = FindItinerarySlow(tickets);
    auto expected_str = ItineraryToString(expected);
    auto result_str = ItineraryToString(result);
    EXPECT_STREQ(expected_str.c_str(), result_str.c_str());
}

UTEST(FindItinerarySlow, OnePossible) {
    std::vector<std::vector<std::string>> tickets = {
        {"JFK", "BBB"}, {"BBB", "CCC"}, {"JFK", "DDD"}, {"DDD", "JFK"}};
    std::vector<std::string> expected = {
        {"JFK", "DDD", "JFK", "BBB", "CCC"}};
    auto result = FindItinerarySlow(tickets);
    auto expected_str = ItineraryToString(expected);
    auto result_str = ItineraryToString(result);
    EXPECT_STREQ(expected_str.c_str(), result_str.c_str());
}

UTEST(FindItinerary, Linear) {
    std::vector<std::vector<std::string>> tickets = {
        {"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    std::vector<std::string> expected = {"JFK", "MUC", "LHR", "SFO", "SJC"};
    std::vector<std::string> result = FindItinerary(tickets);
    std::string expected_str = ItineraryToString(expected);
    std::string result_str = ItineraryToString(result);
    EXPECT_STREQ(expected_str.c_str(), result_str.c_str());
}

UTEST(FindItinerary, TwoPossible) {
    std::vector<std::vector<std::string>> tickets = {
        {"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"}, {"ATL", "JFK"},
        {"ATL", "SFO"}};
    std::vector<std::string> expected = {
        {"JFK", "ATL", "JFK", "SFO", "ATL", "SFO"}};
    auto result = FindItinerary(tickets);
    auto expected_str = ItineraryToString(expected);
    auto result_str = ItineraryToString(result);
    EXPECT_STREQ(expected_str.c_str(), result_str.c_str());
}

UTEST(FindItinerary, OnePossible) {
    std::vector<std::vector<std::string>> tickets = {
        {"JFK", "BBB"}, {"BBB", "CCC"}, {"JFK", "DDD"}, {"DDD", "JFK"}};
    std::vector<std::string> expected = {
        {"JFK", "DDD", "JFK", "BBB", "CCC"}};
    auto result = FindItinerary(tickets);
    auto expected_str = ItineraryToString(expected);
    auto result_str = ItineraryToString(result);
    EXPECT_STREQ(expected_str.c_str(), result_str.c_str());
}

UTEST_MAIN()
