CXX=g++
CXXFLAGS=-Wall -Wextra -Wpedantic -Werror -Iincludes -std=c++17
SOURCES=*cpp.

.PHONY: all
all: $<

debug: *.cpp includes/*.hpp
	$(CXX) $(SOURCES) $(CXXFLAGS) -g -o $@

release: *.cpp includes/*.hpp
	$(CXX) $(SOURCES) $(CXXFLAGS) -O3 -o $@

.PHONY: clean
clean:
	rm $<
