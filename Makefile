CXX=g++
CXXFLAGS=-Wall -Wextra -Wpedantic -Werror -Iincludes -std=c++17
SOURCES=*.cpp
INCLUDES=includes/*.hpp

.PHONY: all
all: $<

debug: $(SOURCE) $(INCLUDES)
	$(CXX) $(SOURCES) $(CXXFLAGS) -g -o $@

release: $(SOURCE) $(INCLUDES)
	$(CXX) $(SOURCES) $(CXXFLAGS) -O3 -o $@

.PHONY: clean
clean:
	rm $<
