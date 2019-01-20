CXX=g++
CXXFLAGS=-std=c++17 -Wall -Wextra -Wpedantic -Werror
IFLAGS=-I inc
SOURCES=*.cpp

.PHONY: all
all: debug release

debug: $(SOURCES)
	$(CXX) $^ $(CXXFLAGS) $(IFLAGS) -g -o $@

release: $(SOURCES)
	$(CXX) $^ $(CXXFLAGS) $(IFLAGS) -O3 -o $@

.PHONY: clean
clean:
	rm debug release
