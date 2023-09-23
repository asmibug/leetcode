#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

bool IsPredecessor(const std::string& predecessor,
                   const std::string& successor) {
    if (predecessor.size() + 1 != successor.size()) {
        return false;
    }
    int n = predecessor.size();
    bool seen_diff = false;
    for (int i = 0; i < n; ++i) {
        if (predecessor[i] != successor[i + seen_diff]) {
            if (seen_diff || predecessor[i] != successor[i + 1]) {
                return false;
            }
            seen_diff = true;
        }
    }
    return true;
}

int GetLongestChainLenFirst(std::vector<std::string> words) {
    int n = words.size();
    std::sort(
        words.begin(), words.end(),
        [](const std::string& a, const std::string& b) {
            return a.size() < b.size();
        }
    );
    std::vector<int> max_chain_len(n, 1);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1;
             j < n && words[j].size() <= words[i].size() + 1;
             ++j) {
            if (IsPredecessor(words[i], words[j])) {
                max_chain_len[j] = std::max(max_chain_len[j],
                                            max_chain_len[i] + 1);
            }
        }
    }
    return *std::max_element(max_chain_len.begin(), max_chain_len.end());
}

int GetLongestChainLen(std::vector<std::string> words) {
    std::sort(
        words.begin(), words.end(),
        [](const std::string& a, const std::string& b) {
            return a.size() < b.size();
        }
    );
    std::unordered_map<std::string, int> max_chain_len;
    for (const auto& s : words) {
        max_chain_len[s] = 1;
        for (unsigned j = 0; j < s.size(); ++j) {
            std::string predecessor = s.substr(0, j) + s.substr(j + 1);
            if (max_chain_len.contains(predecessor)) {
                max_chain_len[s] = std::max(max_chain_len[s],
                                            max_chain_len[predecessor] + 1);
            }
        }
    }
    return (*std::max_element(
        max_chain_len.begin(), max_chain_len.end(),
        [](const std::pair<std::string, int>& a,
           const std::pair<std::string, int>& b) {
            return a.second < b.second;
        })).second;
}

using std::string;
using std::vector;

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        return GetLongestChainLen(words);
    }
};
