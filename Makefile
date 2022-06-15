
MAYOR = 0
MINOR = 7
PATCH = 0

PLATFORM := gnu+linux

ifeq ($(PLATFORM),gnu+linux)
	PREFIX := $(if $(PREFIX),$(PREFIX),/usr)
	INC_DIR = $(PREFIX)/include
	LIB_DIR = $(PREFIX)/lib
	TARGET  = libpocha.a
else
ifeq ($(PLATFORM),mingw)
	PREFIX := /usr/x86_64-w64-mingw32
	INC_DIR = $(PREFIX)/include
	LIB_DIR = $(PREFIX)/lib
	TARGET  = libpocha.dll
	CC     := x86_64-w64-mingw32-cc
	AR     := x86_64-w64-mingw32-ar
else
all: $(error platform `$(PLATFORM)` not supported)
endif
endif

OBJ_DIR = obj-$(PLATFORM)
SRC = $(shell find src -type f -name '*.c' ! -name ver.c) 
OBJ = $(SRC:src/%.c=$(OBJ_DIR)/%.o)

INSTALL_INC_DIR = $(INSTALL_DIR)$(INC_DIR)
INSTALL_LIB_DIR = $(INSTALL_DIR)$(LIB_DIR)

C_FLAGS = -O3 -Wall -pedantic

all: inc/ver.h $(OBJ_DIR)/$(TARGET)

%/:
	mkdir -p $@

inc/ver.h: src/ver.c
	printf "`cat $<`" $(MAYOR) $(MINOR) $(PATCH) > $@

ifeq ($(PLATFORM)-$(shell uname -m),gnu+linux-x86_64)
$(OBJ_DIR)/%.o: src/%.asm
	@mkdir -p $(OBJ_DIR)/
	fasm $< $@
endif

$(OBJ_DIR)/%.o: src/%.c
	$(CC) -c $< -o $@ $(C_FLAGS)

$(OBJ_DIR)/$(TARGET): $(OBJ)
	$(AR) rcs $@ $(OBJ_DIR)/*

install: uninstall all
	@mkdir -p $(INSTALL_INC_DIR)/pocha/
	@mkdir -p $(INSTALL_LIB_DIR)/
	cp -r inc/* $(INSTALL_INC_DIR)/pocha/
	cp -r $(OBJ_DIR)/$(TARGET) $(INSTALL_LIB_DIR)/$(TARGET)

uninstall:
	rm -rf $(INSTALL_INC_DIR)/pocha/
	rm -rf $(INSTALL_LIB_DIR)/$(TARGET)

clean:
	rm -rf inc/ver.h $(OBJ_DIR)/

