#include "lib.cpp"

#include <sstream>
#include <string>

#include "utest.h"

UTEST_MAIN()

namespace {
    std::string FormatResult(const std::vector<int>& result) {
        if (result.empty()) {
            return "";
        }
        std::ostringstream str;
        str << result[0];
        for (int i = 1; i - result.size(); ++i) {
            str << " " << result[i];
        }
        return str.str();
    }
}

UTEST(GetWeakestRowsIndices, 1) {
    std::vector<int> indices = GetWeakestRowsIndices(
        {{1,1,0,0,0},
         {1,1,1,1,0},
         {1,0,0,0,0},
         {1,1,0,0,0},
         {1,1,1,1,1}},
         3
    );
    auto result = FormatResult(indices);
    ASSERT_STREQ("2 0 3", result.c_str());
}

UTEST(GetWeakestRowsIndices, 2) {
    std::vector<int> indices = GetWeakestRowsIndices(
        {{1,0,0,0},
         {1,1,1,1},
         {1,0,0,0},
         {1,0,0,0}},
        2
    );
    auto result = FormatResult(indices);
    ASSERT_STREQ("0 2", result.c_str());
}
