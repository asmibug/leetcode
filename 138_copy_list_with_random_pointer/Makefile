CPPFLAGS = -I"${HOME}/lib/utest.h"  # https://github.com/sheredom/utest.h

CXXFLAGS = -std=c++20 -Wpedantic -g3 \
-Wall -Wextra \
-fsanitize=address,undefined

BUILD_CMD = $(CXX) $(CXXFLAGS) $^ -o $@

default: prog.exe

prog.exe: main.o
	$(BUILD_CMD)

test: test.exe
	./$<

test.exe: test_main.o
	$(BUILD_CMD)

test_main.o: main.cpp
	$(BUILD_CMD) $(CPPFLAGS) -c -DTEST

clean:
	-rm *.o *.exe

.PHONY: test clean
.DELETE_ON_ERROR:
