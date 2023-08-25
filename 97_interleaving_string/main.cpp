#include <algorithm>  // std::swap
#include <string>  // std::string
#include <string_view>  // std::string_view
#include <vector>  // std::vector

using std::string;

bool isInterleaveRecursive(std::string_view s1,
                           std::string_view s2,
                           std::string_view s3) {
    if (s1.size() == 0) {
        if (s2 == s3) {
            return true;
        }
        return false;
    }
    if (s2.size() == 0) {
        if (s1 == s3) {
            return true;
        }
        return false;
    }
    bool res = false;
    if (s1[0] == s3[0]) {
        res |= isInterleaveRecursive(std::string_view(&s1[1], s1.size() - 1),
                                     s2,
                                     std::string_view(&s3[1], s3.size() - 1));
    }
    if (s2[0] == s3[0]) {
        res |= isInterleaveRecursive(s1,
                                     std::string_view(&s2[1], s2.size() - 1),
                                     std::string_view(&s3[1], s3.size() - 1));
    }
    return res;
}

bool isInterleaveCycle(const std::string& s1,
                       const std::string& s2, 
                       const std::string& s3) {
    std::vector<unsigned> borders = {0};
    for (unsigned i = 1; i <= s3.size(); ++i) {
        std::vector<unsigned> new_borders;
        for (unsigned j : borders) {
            if (i - j - 1 < s2.size() && s2[i - j - 1] == s3[i - 1]) {
                if (new_borders.empty() || new_borders.back() != j) {
                    new_borders.push_back(j);
                }
            }
            if (j < s1.size() && s1[j] == s3[i - 1]) {
                new_borders.push_back(j + 1);
            }            
        }
        if (new_borders.empty()) {
            return false;
        }
        std::swap(borders, new_borders);
    }
    return true;
}

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }
        return isInterleaveCycle(s1, s2, s3);
    }
};


#ifndef TEST
int main() {
    return 0;
}
#endif

///////////////////////////////////////////////////////////////////////////////

#include <cassert>  // assert
#include <iostream>  // std::cout std::endl

static void test() {
    assert(Solution().isInterleave("aabcc", "dbbca", "aadbbcbcac"));
    assert(!Solution().isInterleave("aabcc", "dbbca", "aadbbbaccc"));
    assert(Solution().isInterleave("", "", ""));
    assert(Solution().isInterleave(
        "cbcccbabbccbbcccbbbcabbbabcababbbbbbaccaccbabbaacbaabbbc",
        "abcbbcaababccacbaaaccbabaabbaaabcbababbcccbbabbbcbbb",
        "abcbcccbacbbbbccbcbcacacbbbbacabbbabbcacbcaabcbaaacbcbbbabbbaacacbbaaaabccbcbaabbbaaabbcccbcbabababbbcbbbcbb"
    ));
    std::cout << "ALL TESTS PASSED" << std::endl;
}

#ifdef TEST
int main() {
    test();
    return 0;
}
#endif
