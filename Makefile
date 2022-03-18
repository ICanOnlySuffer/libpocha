
AC = nasm
A_FLAGS = -f elf64
C_FLAGS = -O3

PUTILS = $(foreach obj, str put vec dic lng, build/$(obj).o)
TESTS = $(foreach bin, lang vector dictionary, tests/$(bin).bin)

all: build $(PUTILS)

build:
	mkdir build

build/%.o: putils/%.c
	$(CC) $(C_FLAGS) -Iputils -o $@ $< -c

build/%.o: putils/%.asm
	$(AC) $(A_FLAGS) -Iputils -o $@ $<

tests: all tests/tester.o $(TESTS)

tests/tester.o: tests/tester.c
	$(CC) $(C_FLAGS) -Itests -o $@ $< -c

tests/%.bin: tests/%.c
	$(CC) $(C_FLAGS) $(PUTILS) tests/tester.o -Itests -o $@ $<

clean:
	$(RM) tests/tester.o
	$(RM) -r build
	$(RM) $(TESTS)

