CC = g++
CFLAGS = -Wall -std=c++11

SRCS = $(wildcard soal*.cpp)
PROGS = $(patsubst %.cpp,%,$(SRCS))

DEPS = src/utils.cpp

all: $(PROGS)

%: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(PROGS)

run1: soal1
	./soal1
run2: soal2
	./soal2
run3: soal3
	./soal3
run4: soal4
	./soal4
run5: soal5
	./soal5
run6: soal6
	./soal6
run7: soal7
	./soal7
