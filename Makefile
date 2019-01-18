CC=g++
CFLAGS=-Wall -Wextra -Wpedantic -Werror -Iincludes
SOURCES=debug release
OBJECTS=*cpp -std=c++17

.PHONY: all
all: $(SOURCES)

debug: *.cpp includes/*.hpp
	$(CC) $(OBJECTS) $(CFLAGS) -g -o debug

release: *.cpp includes/*.hpp
	$(CC) $(OBJECTS) $(CFLAGS) -O3 -o release

.PHONY: clean
clean:
	rm $(SOURCES)
