#target which is not a file
.PHONY: all 
all: debug release

debug: *.cpp inc/*.hpp
	g++ *.cpp -std=c++17 -Wall -Wextra -Werror -g -o debug -Iinc

release: *.cpp inc/*.hpp
	g++ *.cpp -std=c++17 -Wall -Wextra -Werror -O3 -o release -Iinc

.PHONY: clean
clean:
	rm debug release
