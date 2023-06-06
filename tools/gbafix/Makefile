CC = gcc
.PHONY: clean all

SRCS = gbafix.c

all: gbafix
	@:

gbafix: $(SRCS)
	$(CC) $(SRCS) -o $@ $(LDFLAGS)

clean:
	$(RM) gbafix gbafix.exe
