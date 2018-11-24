CC := g++
CFLAGS := -Wall -Wextra -g
TARGET := main

all: run

src/main.lex.yy.c: src/main.lex
	 flex --noyywrap -o src/main.lex.yy.cpp -l src/main.lex

src/main.tab.c: src/main.y
	bison -o src/main.tab.cpp --defines=src/main.tab.h -vy src/main.y

src/pch.h.gch: src/pch.h
	g++ -x c++-header -o src/pch.h.gch -c src/pch.h

lex: src/main.lex.yy.c
yacc: src/main.tab.c

main: src/pch.h.gch
	$(CC) $(CFLAGS) $(shell ls ./src/*.cpp) -o main

.PHONY: all clean	run lex yacc main test

run: lex yacc main

clean:
	rm src/main.lex.yy.cpp src/main.tab.cpp src/main.tab.h src/main.output src/pch.h.gch $(TARGET) *.o -f

test: ./main
	./main test.txt > result.txt
