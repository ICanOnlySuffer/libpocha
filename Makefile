
define VERSION_H

# define LIBPOCHA_VERSION_MAYOR 0
# define LIBPOCHA_VERSION_MINOR 8
# define LIBPOCHA_VERSION_PATCH 0

/*
	libpocha
	Copyright (c) 2022 Piero Rojas
	GNU General Public License v3.0
*/

endef

export VERSION_H

PLATFORM := gnu+linux
ARCH := $(shell uname -m)

ifeq ($(PLATFORM),gnu+linux)
PREFIX := $(if $(PREFIX),$(PREFIX),/usr)
INC_DIR = $(PREFIX)/include
LIB_DIR = $(PREFIX)/lib
TARGET  = libpocha.a
else
ifeq ($(PLATFORM),mingw)
PREFIX := $(if $(PREFIX),$(PREFIX),/usr/x86_64-w64-mingw32)
INC_DIR = $(PREFIX)/include
LIB_DIR = $(PREFIX)/lib
TARGET  = libpocha.dll
CC     := x86_64-w64-mingw32-cc
AR     := x86_64-w64-mingw32-ar
else
all: $(error platform `$(PLATFORM)` not supported)
endif
endif

SRC = $(shell find src -type f -name '*.c' ! -name ver.c) 
OBJ = $(SRC:src/%.c=lib/%.o)

INSTALL_INC_DIR = $(INSTALL_DIR)$(INC_DIR)
INSTALL_LIB_DIR = $(INSTALL_DIR)$(LIB_DIR)

C_FLAGS = -O3 -Wall -Wextra -pedantic -g3

ifeq ($(CC),clang)
C_FLAGS += -fno-stack-protector
else
C_FLAGS += -Wno-cast-function-type
endif

all: inc/ver.h lib/$(TARGET)

%/:
	mkdir -p $@

inc/ver.h:
	echo "$$VERSION_H" > $@

ifeq ($(PLATFORM)-$(ARCH),gnu+linux-x86_64)
lib/%.o: src/%.asm
	@mkdir -p lib/
	fasm $< $@
endif

lib/%.o: src/%.c
	@mkdir -p lib/
	$(CC) -c $< -o $@ $(C_FLAGS)

lib/$(TARGET): $(OBJ)
	$(AR) rcs $@ lib/*
	strip -g $@

install: uninstall all
	@mkdir -p $(INSTALL_INC_DIR)/pocha/
	@mkdir -p $(INSTALL_LIB_DIR)/
	cp -r inc/* $(INSTALL_INC_DIR)/pocha/
	cp -r lib/$(TARGET) $(INSTALL_LIB_DIR)/$(TARGET)

uninstall:
	rm -rf $(INSTALL_INC_DIR)/pocha/
	rm -rf $(INSTALL_LIB_DIR)/$(TARGET)

clean:
	rm -rf inc/ver.h lib/

