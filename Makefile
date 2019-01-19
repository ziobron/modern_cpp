CXX= g++
CXXFLAGS= -std=c++17 -Wall -Wpedantic -Wextra
SOURCES= *.cpp
OBJECTS= $(SOURCES:.cpp=.o)
INCLUDES= includes/*.hpp
include_dirs= -Iincludes
all_target= debug release

.PHONY: all
all: $(all_target)

debug: $(SOURCES) $(INCLUDES)
	$(CXX) $< $(CXXFLAGS) -g -o $@ $(include_dir)  

release: $(SOURCES) $(INCLUDES)
	$(CXX) $< $(CXXFLAGS) -O3 -o $@ $(include_dir)

.PHONY: clean
clean:
	rm $(all_target) 
