
NAME = "Pocha's utility library"
PLATFORM := all
PLATFORMS = gnu+linux mingw

ifeq ($(PLATFORM), all)
all:
	make all PLATFORM=gnu+linux
	make all PLATFORM=mingw
install:
	make install PLATFORM=gnu+linux
	make install PLATFORM=mingw
uninstall:
	make uninstall PLATFORM=gnu+linux
	make uninstall PLATFORM=mingw
clean:
	make clean PLATFORM=gnu+linux
	make clean PLATFORM=mingw
else
ifeq ($(PLATFORM), gnu+linux)
	DIR_INC = /usr/include
	DIR_LIB = /usr/lib
	DIR_BIN = /usr/bin
	CC := cc
	AC = nasm
	A_FLAGS = -Iinc/ -O3 -f elf64
	ARCH = $(shell uname -m)
else
ifeq ($(PLATFORM), mingw)
	DIR_INC = /usr/x86_64-w64-mingw32/include
	DIR_LIB = /usr/x86_64-w64-mingw32/lib
	DIR_BIN = /usr/x86_64-w64-mingw32/bin
	CC := x86_64-w64-mingw32-cc
else
all: $(error platform `$(PLATFORM)` not supported)
endif
endif

DIR_OBJ = obj-$(PLATFORM)
SRC = $(shell find src -name '*.c') 
OBJ = $(SRC:src/%.c=$(DIR_OBJ)/%.o)

all: $(DIR_OBJ)/ $(OBJ)

DIR_INSTALL_INC = $(DIR_INSTALL)$(DIR_INC)
DIR_INSTALL_LIB = $(DIR_INSTALL)$(DIR_LIB)
DIR_INSTALL_BIN = $(DIR_INSTALL)$(DIR_BIN)

C_FLAGS = -Iinc/ -O3

%/:
	mkdir -p $@

DIRS = $(DIR_INSTALL_INC)/pul/ \
       $(DIR_INSTALL_LIB)/pul/ \
       $(DIR_INSTALL_BIN)/

ifeq ($(ARCH), x86_64)
$(DIR_OBJ)/%.o: src/%.asm
	$(AC) $< -o $@ $(A_FLAGS)
endif

$(DIR_OBJ)/%.o: src/%.c
	$(CC) -c $< -o $@ $(C_FLAGS)

install: uninstall all $(DIRS)
	cp -r inc/* $(DIR_INSTALL_INC)/pul/
	cp -r $(DIR_OBJ)/* $(DIR_INSTALL_LIB)/pul/
	cp bin/pul $(DIR_INSTALL_BIN)

uninstall:
	rm -rf $(DIR_INSTALL_INC)/pul/
	rm -rf $(DIR_INSTALL_LIB)/pul/
	rm -rf $(DIR_INSTALL_BIN)/pul

clean:
	rm -rf $(DIR_OBJ)

endif

