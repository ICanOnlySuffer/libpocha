
OBJECTS = str.o put.o vec.o dic.o lng.o

AC = nasm -f elf64

all: $(OBJECTS)

str.o:
	$(AC) str.asm

put.o:
	$(AC) put.asm

vec.o:
	$(CC) vec.c -c

dic.o:
	$(CC) dic.c -c

lng.o:
	$(CC) lng.c -c

clean:
	$(RM) $(OBJECTS)

