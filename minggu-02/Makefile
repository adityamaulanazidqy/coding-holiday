CC = g++
CFLAGS = -Wall -std=c++11

SRCS = main.cpp
PROGS = main

DEPS = src/utils.cpp

all: $(PROGS)

$(PROGS): $(SRCS) $(DEPS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(PROGS)

run: main
	./main
