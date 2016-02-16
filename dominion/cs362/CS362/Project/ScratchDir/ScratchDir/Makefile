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
	./testDominion 10 1 &> testdominion.out
	gcov ./playdom 10 >> testdominion.out

randomSteward:
	gcc -fprofile-arcs -ftest-coverage -Wall -coverage -std=c99 dominion.c randomStewardTest.c rngs.c -o randomSteward -lm -g

randomAdventurer:
	gcc -fprofile-arcs -ftest-coverage -Wall -coverage -std=c99 dominion.c randomAdventurerTest.c rngs.c -o randomAdventurer -lm -g

unit1: 
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest1.c rngs.c -o unittest1 -lm -g

unit2:
	gcc -fprofile-arcs -ftest-coverage --coverage -Wall -std=c99 dominion.c unittest2.c rngs.c -o unittest2 -lm -g

unit3:
	gcc -fprofile-arcs -ftest-coverage --coverage -Wall -std=c99 dominion.c unittest3.c rngs.c -o unittest3 -lm -g

unit4:
	gcc -fprofile-arcs -ftest-coverage --coverage -Wall -std=c99 dominion.c unittest4.c rngs.c -o unittest4 -lm -g

card1:
	gcc -fprofile-arcs -ftest-coverage --coverage -Wall -std=c99 dominion.c cardtest1.c rngs.c -o cardtest1 -lm -g

card2:
	gcc -fprofile-arcs -ftest-coverage --coverage -Wall -std=c99 dominion.c cardtest2.c rngs.c -o cardtest2 -lm -g

card3:
	gcc -fprofile-arcs -ftest-coverage --coverage -Wall -std=c99 dominion.c cardtest3.c rngs.c -o cardtest3 -lm -g

card4:
	gcc -fprofile-arcs -ftest-coverage --coverage -Wall -std=c99 dominion.c cardtest4.c rngs.c -o cardtest4 -lm -g

unittestresult:
	./unittest1 &> unittestresult.out
	./unittest2 >> unittestresult.out
	./unittest3 >> unittestresult.out
	./unittest4 >> unittestresult.out
	./cardtest1 >> unittestresult.out
	./cardtest2 >> unittestresult.out
	./cardtest3 >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	


.PHONY: all unit1 unit2 unit3 unit4 card1 card2 card3 card4 unittestresult testDominion testdominion.out randomSteward randomAdventurer clean

all: playdom testDominion testdominion.out randomSteward unit1 unit2 unit3 unit4 card1 card2 card3 card4 unittestresult randomAdventurer

clean:
	rm -f *.o playdom rng dominion testDominion testdominion.out randomSteward randomAdventurer unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 unittestresult.out *.gcov *.gcda *.gcno *.so
