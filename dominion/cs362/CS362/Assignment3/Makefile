CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

randomSteward:
	gcc -fprofile-arcs -ftest-coverage -Wall -coverage -std=c99 dominion.c randomStewardTest.c rngs.c -o randomSteward -lm -g

randomAdventurer:
	gcc -fprofile-arcs -ftest-coverage -Wall -coverage -std=c99 dominion.c randomAdventurerTest.c rngs.c -o randomAdventurer -lm -g

randomtestcard.out:
	./playdom 2
	./randomSteward &> randomtestcard.out
	gcov ./playdom >> randomtestcard.out
		

randomtestadventurer.out:
	./playdom 2
	./randomAdventurer &> randomtestadventurer.out
	gcov ./playdom >> randomtestadventurer.out
	
.PHONY: all randomAdventurer randomSteward randomtestcard.out randomtestadventurer.out clean

all: playdom randomSteward randomAdventurer randomtestcard.out randomtestadventurer.out

clean:
	rm -f *.o playdom randomSteward randomAdventurer randomtestcard.out randomtestadventurer.out *.gcov *.gcda *.gcno *.so
