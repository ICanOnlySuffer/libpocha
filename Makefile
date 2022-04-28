
NAME = "Pocha's utility library"
VERSION = "v0.4.0"
OS := all
OSES = gnu+linux windows

ifeq ($(OS), all)
all:
	make all OS=gnu+linux
	make all OS=windows
install:
	make install OS=gnu+linux
	make install OS=windows
uninstall:
	make uninstall OS=gnu+linux
	make uninstall OS=windows
else
ifeq ($(OS), gnu+linux)
	DIR_INC = /usr/include
	DIR_LIB = /usr/lib
	DIR_BIN = /usr/bin
	CC := cc
	AC = nasm
	A_FLAGS = -Iinc/ -O3 -f elf64
	ARCH = $(shell uname -m)
else
ifeq ($(OS), windows)
	DIR_INC = /usr/x86_64-w64-mingw32/include
	DIR_LIB = /usr/x86_64-w64-mingw32/lib
	DIR_BIN = /usr/x86_64-w64-mingw32/bin
	CC := x86_64-w64-mingw32-cc
else
all: $(error operating system `$(OS)` not supported)
endif
endif

DIR_OBJ = obj-$(OS)
SRC = $(shell find src -name '*.c') 
OBJ = $(SRC:src/%.c=$(DIR_OBJ)/%.o)

all: $(DIR_OBJ)/ $(OBJ)

DIR_INSTALL_INC = $(DIR_INSTALL)$(DIR_INC)
DIR_INSTALL_LIB = $(DIR_INSTALL)$(DIR_LIB)
DIR_INSTALL_BIN = $(DIR_INSTALL)$(DIR_BIN)

C_FLAGS = -Iinc/ -O3

%/:
	mkdir -p $@

makedirs:
	mkdir -p $(DIR_INSTALL_INC)
	mkdir -p $(DIR_INSTALL_LIB)
	mkdir -p $(DIR_INSTALL_BIN)

ifeq ($(ARCH), x86_64)
$(DIR_OBJ)/%.o: src/%.asm
	$(AC) $< -o $@ $(A_FLAGS)
endif

$(DIR_OBJ)/%.o: src/%.c
	$(CC) -c $< -o $@ $(C_FLAGS)

install: all makedirs
	cp -ru inc/* $(DIR_INSTALL_INC)/pul/
	cp -ru $(DIR_OBJ)/* $(DIR_INSTALL_LIB)/pul/
	cp -u bin/pul $(DIR_INSTALL_BIN)

uninstall:
	rm -rf $(DIR_INSTALL_INC)/pul/
	rm -rf $(DIR_INSTALL_LIB)/pul/
	rm -rf $(DIR_INSTALL_BIN)/pul
endif

clean:
	rm -rf obj-*

