
VERSION = "v0.5.0"
PLATFORM := gnu+linux

ifeq ($(PLATFORM), gnu+linux)
	PREFIX := $(if $(PREFIX),$(PREFIX),/usr)
	INC_DIR = $(PREFIX)/include
	LIB_DIR = $(PREFIX)/lib
	BIN_DIR = $(PREFIX)/bin
else
ifeq ($(PLATFORM), mingw)
	PREFIX := /usr/x86_64-w64-mingw32
	INC_DIR = $(PREFIX)/include
	LIB_DIR = $(PREFIX)/lib
	BIN_DIR = $(PREFIX)/bin
	CC := x86_64-w64-mingw32-cc
else
all: $(error platform `$(PLATFORM)` not supported)
endif
endif

OBJ_DIR = obj-$(PLATFORM)
SRC = $(shell find src -name '*.c') 
OBJ = $(SRC:src/%.c=$(OBJ_DIR)/%.o)

all: bin/pul $(OBJ_DIR)/ $(OBJ)

INSTALL_INC_DIR = $(INSTALL_DIR)$(INC_DIR)
INSTALL_LIB_DIR = $(INSTALL_DIR)$(LIB_DIR)
INSTALL_BIN_DIR = $(INSTALL_DIR)$(BIN_DIR)

C_FLAGS = -O3 -Wall

%/:
	mkdir -p $@

DIRS = $(INSTALL_INC_DIR)/pul/ \
       $(INSTALL_LIB_DIR)/pul/ \
       $(INSTALL_BIN_DIR)/

ifeq ($(PLATFORM), gnu+linux)
ifeq ($(shell uname -m), x86_64)
	AC = nasm
	A_FLAGS = -O3 -Wall -f elf64 -Iinc/
$(OBJ_DIR)/%.o: src/%.asm
	$(AC) $< -o $@ $(A_FLAGS)
endif
endif

bin/pul: src/pul.zsh bin/
	printf "`cat $<`" $(VERSION) > $@
	chmod +x $@

#echo "\
#,-, , , ,   Pocha's Utility Library v0.5.0
#| | | | |
#|-´ | | |   Copyright (c) 2022 Piero Estéfano Rojas Effio
#'   \`-´ \`-- GNU General Public License v3.0"

$(OBJ_DIR)/%.o: src/%.c
	$(CC) -c $< -o $@ $(C_FLAGS)

install: uninstall all $(DIRS)
	cp -r inc/* $(INSTALL_INC_DIR)/pul/
	cp -r $(OBJ_DIR)/* $(INSTALL_LIB_DIR)/pul/
	cp bin/pul $(INSTALL_BIN_DIR)

uninstall:
	rm -rf $(INSTALL_INC_DIR)/pul/
	rm -rf $(INSTALL_LIB_DIR)/pul/
	rm -rf $(INSTALL_BIN_DIR)/pul

clean:
	rm -rf bin/ $(OBJ_DIR)

