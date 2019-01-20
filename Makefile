# Variable declaration
CC=	g++
CFLAGS=	-Iincludes
SOURCE=	*.cpp
INCUDE=	includes/*.hpp


.PHONY: all
all:debug release

debug: $(SOURCE) $(INCLUDE)
	$(CC) $(SOURCE) -g -o debug $(CFLAGS) 
release: $(SOURCE) $(INCLUDE)
	$(CC) $(SOURCE) -O3 -o release $(CFLAGS)

.PHONY: clean
clean :
	rm debug release
