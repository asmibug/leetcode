CPPFLAGS := -MMD -MP \
-I"${HOME}/lib/utest.h"  # https://github.com/sheredom/utest.h

CXXFLAGS := -std=c++20 -Wpedantic -g3 \
-Wall -Wextra \
-fsanitize=address,undefined

default: test.exe

test: test.exe
	./$<

test.exe: test.o
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	-rm *.d *.o *.exe

.PHONY: test clean
.DELETE_ON_ERROR:

-include $(wildcard *.d)
