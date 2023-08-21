#include <assert.h>  // assert
#include <stdbool.h>  // bool false true
#include <stdio.h>  // puts
#include <string.h>  // strlen

bool repeatedSubstringPatternLowMem(const char *s) {
    unsigned s_len = (unsigned) strlen(s);
    unsigned pattern_len = 1;
    unsigned pattern_pos = 0;
    const char *cursor = s + 1;
    for (; *cursor; ++cursor) {
        if (*cursor == *(s + pattern_pos)) {
            pattern_pos = (pattern_pos + 1) % pattern_len;
        } else if (s_len % (cursor - s + 1) == 0) {
            pattern_len = (unsigned) (cursor - s) + 1;
            pattern_pos = 0;
        } else {
            do {
                ++pattern_len;
            } while (s_len % pattern_len);
            pattern_pos = 0;
            cursor = s + pattern_len - 1;
        }
    }
    if (!pattern_pos && pattern_len < cursor - s) {
        return true;
    }
    return false;
}

bool repeatedSubstringPattern(const char *s) {
    unsigned s_len = strlen(s);
    // copy s twice: without first character and without last
    char ss[2 * s_len - 2 /* add one for null-termination */ + 1];
    strncpy(ss, s + 1, s_len - 1);
    strncpy(ss + s_len - 1, s, s_len - 1);
    ss[2 * s_len - 2] = '\0';  // don't forget to terminate
    return strstr(ss, s) != NULL;
}

int main(void) {
    return 0;
}


#define TEST_PATTERNS(func) do { \
    assert(func("a") == false); \
    assert(func("aa") == true); \
    assert(func("ab") == false); \
    assert(func("aaa") == true); \
    assert(func("aba") == false); \
    assert(func("aab") == false); \
    assert(func("abab") == true); \
    assert(func("ababa") == false); \
    assert(func("ababab") == true); \
    assert(func("abacababacab") == true); \
    assert(func("ababba") == false); \
} while (0)

int test_main(void) {
    TEST_PATTERNS(repeatedSubstringPatternLowMem);
    TEST_PATTERNS(repeatedSubstringPattern);
    puts("ALL TESTS PASSED");
    return 0;
}
