
OS := $(shell uname -o)
PREFIX := /usr
BUILD = $(DEST_DIR)$(PREFIX)

AC = nasm
A_FLAGS = -Iinclude/ -O3 -f elf64
C_FLAGS = -Iinclude/ -O3

LIB = $(foreach obj, str num put vec dic lng, lib/$(obj).o)

all: lib/ $(LIB)

%/:
	mkdir -p $@

ifeq ($(OS), GNU/Linux)
lib/%.o: src/%.asm
	$(AC) $(A_FLAGS) $< -o $@
endif

lib/%.o: src/%.c
	$(CC) $(C_FLAGS) -c $< -o $@

install: all $(BUILD)/include/pul/ $(BUILD)/lib/pul/
	cp -ru include/* $(BUILD)/include/pul/
	cp -ru lib/* $(BUILD)/lib/pul/

uninstall:
	rm -rf $(BUILD)/include/pul/
	rm -rf $(BUILD)/lib/pul/

clean:
	rm -rf lib/

