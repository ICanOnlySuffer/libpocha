
OS := $(shell uname -o)

AC = nasm
A_FLAGS = -Iinclude/ -O3 -f elf64
C_FLAGS = -Iinclude/ -O3

LIB_PUTILS = $(foreach obj, str put vec dic lng, lib/$(obj).o)
LIB_TESTS = $(foreach obj, tester, tests/lib/$(obj).o)
BIN_TESTS = $(addprefix tests/bin/, lang vector string dictionary)

all: lib/ $(LIB_PUTILS)

%/:
	mkdir -p $@

ifeq ($(OS), GNU/Linux)
lib/%.o: src/%.asm
	$(AC) $(A_FLAGS) $< -o $@
endif

lib/%.o: src/%.c
	$(CC) $(C_FLAGS) -c $< -o $@

tests: all tests/lib/ $(LIB_TESTS) tests/bin/ $(BIN_TESTS)

tests/lib/tester.o: tests/src/tester.c
	$(CC) $(C_FLAGS) -Itests/include/ -c $< -o $@

tests/bin/%: tests/src/%.c
	$(CC) $(C_FLAGS) -Itests/include/ lib/*.o tests/lib/*.o $< -o $@

install: all
	cp -r include/ $(DEST_DIR)/usr/include/putils/
	cp -r lib/ $(DEST_DIR)/usr/lib/putils/

uninstall:
	rm -rf $(DEST_DIR)/usr/include/putils/
	rm -rf $(DEST_DIR)/usr/lib/putils/

clean:
	rm -rf lib/ tests/lib/ tests/bin/

