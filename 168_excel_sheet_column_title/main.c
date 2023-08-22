#include <stdlib.h>  // malloc
#include <string.h>  // strcpy

char *convertToTitle(int columnNumber){
    const char base = 'Z' - 'A' + 1;
    char str[sizeof(columnNumber) * 8 + 1];
    const unsigned max_len = sizeof(str) - 1;
    str[max_len] = '\0';
    unsigned cursor = max_len;
    while (columnNumber) {
        --cursor;
        str[cursor] = 'A' + (columnNumber - 1) % base;
        columnNumber = (columnNumber - 1) / base;
    }
    char *result = malloc(max_len - cursor + 1);
    strcpy(result, str + cursor);
    return result;
}

int main(void) {
    return 0;
}

///////////////////////////////////////////////////////////////////////////////

#include <assert.h>  // assert
#include <stdbool.h>  // bool
#include <stdio.h>  // puts
#include <stdlib.h>  // free
#include <string.h>  // strcmp

static bool check_convert_to_title(int column_number, const char *expected) {
    char *result = convertToTitle(column_number);
    bool result_and_expected_are_equal = !strcmp(result, expected);
    free(result);
    return result_and_expected_are_equal;
}

int test_main(void) {
    assert(check_convert_to_title(1, "A"));
    assert(check_convert_to_title(2, "B"));
    assert(check_convert_to_title(3, "C"));
    assert(check_convert_to_title(27, "AA"));
    assert(check_convert_to_title(52, "AZ"));
    assert(check_convert_to_title(53, "BA"));

    puts("ALL TESTS PASSED");
    return 0;
}
