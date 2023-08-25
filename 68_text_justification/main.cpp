#include <vector>  // std::vector
#include <string>  // std::string

using std::string;
using std::vector;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> text;
        auto strBeginIt = words.begin();
        while (strBeginIt != words.end()) {
            int wordsCnt = 1;
            int wordsLen = strBeginIt->size();
            auto strEndIt = strBeginIt + 1;
            for (;
                 strEndIt != words.end() 
                 && wordsLen + wordsCnt + static_cast<int>(strEndIt->size())
                    <= maxWidth;
                 ++strEndIt) {
                ++wordsCnt;
                wordsLen += strEndIt->size();
            }

            string str = *strBeginIt;
            --wordsCnt;
            int spacesLeft = maxWidth - wordsLen;
            if (strEndIt == words.end()) {  // last string
                spacesLeft = wordsCnt;
            }
            for (auto it = strBeginIt + 1; it != strEndIt; ++it) {
                int spacesNum = (spacesLeft + wordsCnt - 1) / wordsCnt;
                str += string(spacesNum, ' ');
                str += *it;
                --wordsCnt;
                spacesLeft -= spacesNum;
            }
            str.resize(maxWidth, ' ');
            text.push_back(str);
            strBeginIt = strEndIt;
        }
        return text;
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

using text = std::vector<std::string>;

static bool checkFullJustify(text input, int maxWidth, text expected) {
    return Solution().fullJustify(input, maxWidth) == expected;
}

/*
1) каждая строка имеет ровно maxWidth символов
2) если в строке больше одного слова, то пробелы между словами распределены равномерно
3) в последней строке между словами должно быть по 1 пробелу`
*/

static void test() {
    assert(checkFullJustify({"a"}, 1, {"a"}));
    assert(checkFullJustify({"a", "b"}, 3, {"a b"}));
    assert(checkFullJustify({"a"}, 2, {"a "}));
    assert(checkFullJustify({"a", "b"}, 4, {"a b "}));
    assert(checkFullJustify({"a", "b", "c"}, 4, {"a  b", "c   "}));
    std::cout << "ALL TESTS PASSED" << std::endl;
}

#ifdef TEST
int main() {
    test();
    return 0;
}
#endif
