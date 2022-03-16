
PUTILS = $(foreach obj, ioe str put vec dic lng, ../putils/$(obj).o)
TESTER = tester.o
OBJECTS = $(PUTILS) $(TESTER)

TESTS = lang.bin vector.bin dictionary.bin

CBIN = $(CC) $(OBJECTS) -O3

all: $(OBJECTS) $(TESTS)

$(PUTILS):
	$(MAKE) -C ../putils

$(TESTER):
	$(CC) tester.c -c

lang.bin:
	$(CBIN) lang.c -o lang.bin

vector.bin:
	$(CBIN) vector.c -o vector.bin

dictionary.bin:
	$(CBIN) dictionary.c -o dictionary.bin

clean:
	$(RM) $(TESTS)
	$(RM) $(OBJECTS)

