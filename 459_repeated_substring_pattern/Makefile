CFLAGS = -std=c17 -Wpedantic -g3 \
-Wall -Wextra -Wformat=2 -Wformat-overflow=2 -Wformat-truncation=2 \
-Wundef -Wshadow -Wdouble-promotion -Wconversion -Wno-sign-conversion \
-Wfloat-equal -Wswitch-default \
-fsanitize=address,undefined

BUILD_CMD = $(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

default: prog.exe

prog.exe: main.o
	$(BUILD_CMD)

test: test.exe
	./$<

test.exe: test_main.o
	$(BUILD_CMD)

test_main.o: main.o
	objcopy -N main $< $@
	objcopy --redefine-sym test_main=main $@

clean:
	-rm *.o *.exe

.PHONY: test clean
.DELETE_ON_ERROR:
