SRC  		:= $(wildcard src/*.c)
CC      := gcc
CFLAGS  := -Iinclude
CFLAGS  += -Wall -O3 -std=gnu17
BINARY  := ecsj

.PHONY: dev clean compile

default: compile

dev:
	bear -- make compile
	rm $(BINARY)

clean:
	$(RM) *.o $(BINARY)

compile: $(SRC)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $(BINARY)
