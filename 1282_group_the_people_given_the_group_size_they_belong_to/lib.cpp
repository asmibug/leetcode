#include <vector>  // std::vector
#include <unordered_map>  // std::unordered_map

std::vector<std::vector<int>> GetGroups(const std::vector<int>& group_sizes) {
    std::vector<std::vector<int>> groups;
    std::unordered_map<int, std::vector<int>> group_map;
    for (unsigned idx = 0; idx < group_sizes.size(); ++idx) {
        int desired_group_size = group_sizes[idx];
        group_map[desired_group_size].push_back(idx);
        int current_group_size = group_map[desired_group_size].size();
        if (current_group_size == desired_group_size) {
            groups.push_back(std::move(group_map[desired_group_size]));
            group_map.erase(desired_group_size);
        }
    }
    return groups;
}

using std::vector;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        return GetGroups(groupSizes);
    }
};
