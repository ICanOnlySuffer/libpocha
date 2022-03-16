
PUTILS = $(foreach obj, ioe str put vec dic lng, ../putils/$(obj).o)
TESTER = tester.o
OBJECTS = $(PUTILS) $(TESTER)

TESTS = vector.bin str-cpy.bin # dictionary.bin

CBIN = $(CC) $(OBJECTS) -O3

all: $(OBJECTS) $(TESTS)

$(PUTILS):
	$(MAKE) -C ../putils

$(TESTER):
	$(CC) tester.c -c

vector.bin:
	$(CBIN) vector.c -o vector.bin

str-cpy.bin:
	$(CBIN) str-cpy.c -o str-cpy.bin

dictionary.bin:
	$(CBIN) dictionary.c -o dictionary.bin

clean:
	$(RM) $(TESTS)
	$(RM) $(OBJECTS)

