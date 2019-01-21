#phony is used to specify that target is not a file 
#(to avoid conflicts when there are files named clean or all)

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror
HEADERSFLAG = -Iinc

SRCS = *.cpp
INCS = inc/*.hpp

.PHONY: all 
all: debug release

debug: $(SRCS) $(INCS) 
	$(CXX) $(CXXFLAGS) $(HEADERSFLAG) -g -o $@ $(SRCS)

release: $(SRCS) $(INCS)
	$(CXX) $(CXXFLAGS) $(HEADERSFLAG) -O3 -o $@ $(SRCS)

.PHONY: clean
clean:
	rm debug release
