
OS := $(shell uname -o)
PREFIX := /usr

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

install: all $(DEST_DIR)$(PREFIX)/include/ $(DEST_DIR)$(PREFIX)/lib/
	cp -r include/ $(DEST_DIR)$(PREFIX)/include/pul/
	cp -r lib/ $(DEST_DIR)$(PREFIX)/lib/pul/

uninstall:
	rm -rf $(DEST_DIR)$(PREFIX)/include/pul/
	rm -rf $(DEST_DIR)$(PREFIX)/lib/pul/

clean:
	rm -rf lib/

