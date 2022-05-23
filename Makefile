
MAYOR = 0
MINOR = 6
PATCH = 0

PLATFORM := gnu+linux

ifeq ($(PLATFORM), gnu+linux)
	PREFIX := $(if $(PREFIX),$(PREFIX),/usr)
	INC_DIR = $(PREFIX)/include
	LIB_DIR = $(PREFIX)/lib
else
ifeq ($(PLATFORM), mingw)
	PREFIX := /usr/x86_64-w64-mingw32
	INC_DIR = $(PREFIX)/include
	LIB_DIR = $(PREFIX)/lib
	CC := x86_64-w64-mingw32-cc
else
all: $(error platform `$(PLATFORM)` not supported)
endif
endif

OBJ_DIR = obj-$(PLATFORM)
SRC = $(shell find src -type f ! -name ver.c) 
OBJ = $(SRC:src/%.c=$(OBJ_DIR)/%.o)

all: inc/ver.h $(OBJ_DIR)/ $(OBJ)

INSTALL_INC_DIR = $(INSTALL_DIR)$(INC_DIR)
INSTALL_LIB_DIR = $(INSTALL_DIR)$(LIB_DIR)

C_FLAGS = -O3 -Wall -pedantic

%/:
	mkdir -p $@

inc/ver.h: src/ver.c
	printf "`cat $<`" $(MAYOR) $(MINOR) $(PATCH) > $@

ifeq ($(PLATFORM)-$(shell uname -m),gnu+linux-x86_64)
$(OBJ_DIR)/%.o: src/%.asm
	fasm $< $@
endif

$(OBJ_DIR)/%.o: src/%.c
	$(CC) -c $< -o $@ $(C_FLAGS)

install: uninstall all $(INSTALL_INC_DIR)/pul/ $(INSTALL_LIB_DIR)/pul/
	cp -r inc/* $(INSTALL_INC_DIR)/pul/
	cp -r $(OBJ_DIR)/* $(INSTALL_LIB_DIR)/pul/

uninstall:
	rm -rf $(INSTALL_INC_DIR)/pul/
	rm -rf $(INSTALL_LIB_DIR)/pul/

clean:
	rm -rf inc/ver.h $(OBJ_DIR)/

