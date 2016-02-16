CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

testDominion:
	gcc -fprofile-arcs -ftest-coverage -Wall -coverage -std=c99 dominion.c testDominion.c rngs.c -o testDominion -lm -g

testdominion.out:
	./playdom 2
	./testDominion 10 1 &> testdominion.out
	gcov ./playdom 10 >> testdominion.out

gameResults.out:

.PHONY: all testDominion testdominion.out gameResults.out clean

all: playdom testDominion testdominion.out gameResults.out

clean:
	rm -f *.o playdom rng dominion testDominion testdominion.out gameResults.out *.gcov *.gcda *.gcno *.so
