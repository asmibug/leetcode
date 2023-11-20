#include <numeric>
#include <string>
#include <vector>

int GetTotalTime(const std::vector<std::string>& garbage,
                 const std::vector<int>& travel_times) {
    int n = garbage.size();

    constexpr int kAsciiNum = 128;
    int travel_times_by_type[kAsciiNum] = {0};

    int collection_time = 0;
    int current_travel_time = 0;
    for (int house = 0; house < n; ++house) {
        if (house) {
            current_travel_time += travel_times[house - 1];
        }
        collection_time += garbage[house].size();
        for (unsigned char garbage_type : garbage[house]) {
            travel_times_by_type[garbage_type] = current_travel_time;
        }
    }
    return collection_time + std::reduce(std::begin(travel_times_by_type),
                                         std::end(travel_times_by_type));
}

using std::string;
using std::vector;

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        return GetTotalTime(garbage, travel);
    }
};
