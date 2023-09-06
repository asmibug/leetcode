CPPFLAGS = -I"$(HOME)/lib/acutest/include"  # https://github.com/mity/acutest
CXXFLAGS = -std=c++20 -Wpedantic -g3 \
-Wall -Wextra \
-fsanitize=address,undefined

BUILD_CMD = $(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@

default: test.exe

test.exe: main.o
	$(BUILD_CMD)

test: test.exe
	./$<

clean:
	-rm *.o *.exe

.PHONY: test clean
.DELETE_ON_ERROR:
