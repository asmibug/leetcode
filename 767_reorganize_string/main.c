enum {
    MAX_S_LEN = 500
};

#define array_size(array) (sizeof(array) / sizeof(0[array]))

static inline void get_max_and_arg(
        int array[], int array_len, int *max, int *max_idx) {
    *max = array[0];
    *max_idx = 0;
    for (int i = 1; i < array_len; ++i) {
        if (array[i] > *max) {
            *max = array[i];
            *max_idx = i;
        }
    }
}

char *reorganizeString(char *s){
    int s_len = 0;
    int counts['z' - 'a' + 1] = {0};
    for (char *cur = s; *cur; ++cur) {
        ++s_len;
        ++counts[*cur - 'a'];
    }
    int max_count = 0;
    int max_count_idx = 0;
    get_max_and_arg(counts, array_size(counts), &max_count, &max_count_idx);
    if (2 * max_count - s_len > 1) {
        s[0] = '\0';
        return s;
    }
    for (int i = 0; i < 2; ++i) {
        for (char *cur = s + i; cur < s + s_len; cur += 2) {
            if (!counts[max_count_idx]) {
                get_max_and_arg(  // may use heap instead
                    counts, array_size(counts), &max_count, &max_count_idx);
            }
            *cur = 'a' + (char) max_count_idx;
            --counts[max_count_idx];
        }
    }
    return s;
}

char *reorganizeString1(char *s){
    int counts['z' - 'a' + 1] = {0};
    for (char *cur = s; *cur; ++cur) {
        ++counts[*cur - 'a'];
    }
    int max_count = 0;
    int max_count_idx = 0;
    for (int i = 0; i < (int) array_size(counts); ++i) {
        if (counts[i] > max_count) {
            max_count = counts[i];
            max_count_idx = i;
        }
    }
    int sum_count = 0;
    for (int i = 0; i < (int) array_size(counts); ++i) {
        sum_count += counts[i];
    }
    if (2 * max_count - sum_count > 1) {
        s[0] = '\0';
        return s;
    }
    for (char *cur = s; max_count; ++cur) {
        *cur = 'a' + (char) max_count_idx;
        --counts[max_count_idx];
        int prev_idx = max_count_idx;
        max_count = 0;  // may use heap instead
        for (int i = 0; i < (int) array_size(counts); ++i) {
            if (counts[i] > max_count && i != prev_idx) {
                max_count = counts[i];
                max_count_idx = i;
            }
        }
    }
    return s;
}

int main(void) {
    return 0;
}

///////////////////////////////////////////////////////////////////////////////

#include <assert.h>  // assert
#include <stdio.h>  // puts
#include <stdlib.h>  // free malloc
#include <string.h>  // strcmp strcpy

#define check_reorganize_string1(input, expected) do { \
    char *str = malloc(MAX_S_LEN + 1); \
    strcpy(str, input); \
    assert(!strcmp(reorganizeString1(str), expected)); \
    free(str); \
} while (0)

#define check_reorganize_string(input, expected) do { \
    char *str = malloc(MAX_S_LEN + 1); \
    strcpy(str, input); \
    assert(!strcmp(reorganizeString(str), expected)); \
    free(str); \
} while (0)

int test_main(void) {
    check_reorganize_string1("a", "a");
    check_reorganize_string1("aa", "");
    check_reorganize_string1("aab", "aba");
    check_reorganize_string1("aaab", "");
    check_reorganize_string1("aaabc", "abaca");
    check_reorganize_string1("aaabbcc", "abacabc");

    check_reorganize_string("a", "a");
    check_reorganize_string("aa", "");
    check_reorganize_string("aab", "aba");
    check_reorganize_string("aaab", "");
    check_reorganize_string("aaabc", "abaca");
    check_reorganize_string("aaabbcc", "abacacb");

    puts("ALL TESTS PASSED");
    return 0;
}
