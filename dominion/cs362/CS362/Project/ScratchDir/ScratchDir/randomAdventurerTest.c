
//Random test for adventurer card in dominion.c
#include <stdio.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdlib.h>
#include <time.h>

int main(){
	int i, j, k , ret, handPos, coinCount, discardCount, handCount, deckCount, randomCard;
	struct gameState *state = malloc(sizeof(struct gameState));
	time_t t;
	
	srand((unsigned)time(&t));
	printf("Random Test for adventurer card in dominion.c \n");
	
	for(i = 0; i < 1000; i++){
		for(j = 0; j < MAX_PLAYERS+1; j++){	
			state->deckCount[j] = 0;
			state->handCount[j] = 0;
			state->discardCount[j]  = 0;
			state->coins = 0;
			handPos = 0;
			coinCount = 0;
			state->whoseTurn = j;
		
			handCount = rand()%(MAX_HAND-1);//can't draw more than max hand	
			deckCount = rand()%(MAX_DECK-handCount);
			handPos = rand()%(handCount+1);
			discardCount = rand()%(MAX_DECK - deckCount);
		
			for(k = 0; k < handCount; k++){
				randomCard = rand()%(treasure_map+1);
				state->hand[j][k] = randomCard;
				state->handCount[j]++;
			}	
			for(k = 0; k < deckCount; k++){
				randomCard = rand()%(treasure_map+1);
				state->deck[j][k] = randomCard;
				state->deckCount[j]++;
			}	
			for(k = 0; k < discardCount; k++){
				randomCard = rand()%(treasure_map+1);
				state->discard[j][k] = randomCard;
				state->discardCount[j]++;
			}	
			state->hand[j][handPos] = adventurer;
			coinCount = state->coins +2;	
			printf("\tBefore CardEffect\n");
			printf("\t\tHand %d : Deck %d : Discard %d : Coins %d || state->hand %d : state->deck %d : state->discard %d : state->coins %d\n", handCount, deckCount, discardCount, coinCount, state->handCount[j], state->deckCount[j], state->discardCount[j], state->coins);
			ret = cardEffect(adventurer, 0, 0, 0, state, handPos, 0);
			printf("\tAfter CardEffect\n");
			discardCount = ret;
			printf("\t\tHand %d : Deck %d : Discard %d : Coins %d || state->hand %d : state->deck %d : state->discard %d : state->coins %d || Return %d\n", handCount, deckCount, discardCount, coinCount, state->handCount[j], state->deckCount[j], state->discardCount[j], state->coins, ret);
	//		assert(discardCount == state->discardCount[j]);
	//		assert(coinCount == state->coins);
		}
	}
	return 0;
}
