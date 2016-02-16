// unit test for updateCoins function in dominion.c
#include <stdio.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdlib.h>
#include <time.h>
int main(){

	printf("Unit test 2 for the updateCoins function in dominion.c \n");
	int randCoin;
	int coinCount = 0;
	struct gameState *g = malloc(sizeof(struct gameState));
	time_t t;

	srand((unsigned)time(&t));

	
	for(int i = 0; i < MAX_PLAYERS; i++){
		coinCount = 0;
		g->coins = rand()%100;// check that it is actually being reset
		g->handCount[i]  = rand()%(MAX_HAND+1);
	
		for(int j = 0; j < g->handCount[i]; j++){
			randCoin = rand()%3;	
			if(randCoin == 0){
				g->hand[i][j] = copper;
				coinCount += 1;
			}
			else if(randCoin == 1){
				g->hand[i][j] = silver;
				coinCount += 2;
			}
			else if(randCoin == 2){
				g->hand[i][j] = gold;
				coinCount += 3;
			}
		//	printf("%d\n", coinCount);
		}
		
		updateCoins(i, g, 0);
		printf("\tExpected coin Count without bonus: %d, actual coin Count %d \n", coinCount, g->coins);
		assert(coinCount == g->coins);
		updateCoins(i, g, 1);
		printf("\tExpected coin Count with bonus of 1: %d, actual coin Count %d \n", coinCount+1, g->coins);
		assert(coinCount+1 == g->coins);
	}
	printf("All tests passed!\n\n");
	return 0;
}


