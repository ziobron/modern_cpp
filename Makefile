CC=g++
CFLAGS=-std=c++17 -Wall -Wextra -Wpedantic -Werror
LDFLAGS=-I inc
SOURCES=*.cpp

.PHONY: all
all: debug release

debug: $(SOURCES)
	$(CC) $(SOURCES) $(CFLAGS) $(LDFLAGS) -g -o $@

release: $(SOURCES)
	$(CC) $(SOURCES) $(CFLAGS) $(LDFLAGS) -O3 -o $@

.PHONY: clean
clean:
	rm debug release
