CC := g++
CFLAGS := -Wall -Wextra -g
TARGET := main

all: run

src/main.lex.yy.c: src/main.lex
	 flex --noyywrap -o src/main.lex.yy.cpp  src/main.lex 

src/main.tab.c: src/main.y
	bison -o src/main.tab.cpp --defines=src/main.tab.h -v src/main.y

src/pch.h.gch: src/pch.h
	g++ -x c++-header -o src/pch.h.gch -c src/pch.h

lex: src/main.lex.yy.c
yacc: src/main.tab.c

main: src/pch.h.gch
	$(CC) $(CFLAGS) $(shell ls ./src/*.cpp) -o main

.PHONY: all clean main run lex yacc test debug

run: lex yacc main

clean: main
	rm src/main.lex.yy.cpp src/main.tab.cpp src/main.tab.h src/main.output src/pch.h.gch $(TARGET) *.o -f

test: 
	./main test/test.txt > result.txt

debug: lex
	bison -o src/main.tab.cpp --defines=src/main.tab.h -vy src/main.y --debug --report=all
	$(CC) $(CFLAGS) $(shell ls ./src/*.cpp) -o main
