#include <stdio.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdlib.h>
#include <time.h>

int main(){
	int i;
	int j;
	int handPos;
	int randomCard;
	int handCount;
	int ret = 0;
	struct gameState *state = malloc(sizeof(struct gameState));
	time_t t;

	printf("Unit test 8 outpost card in dominion.c \n");
	srand((unsigned)time(&t));
	for(i = 0; i < MAX_PLAYERS; i++){
		state->outpostPlayed = 0;
		state->deckCount[i] = 0;
		state->handCount[i] = 0;
		handPos = 0;
		state->whoseTurn = i;
		handPos = rand()%(MAX_HAND) + 1; 
		for(j = 0; j < handPos; j++){
			randomCard = rand()%(treasure_map+1); 
			state->hand[i][j] = randomCard;
			state->handCount[i]++;
		}
		for(j = 0; j < (MAX_DECK-handPos); j++){
			state->deck[i][j] = randomCard;
			state->deckCount[i]++;
		}
		state->hand[i][handPos] = outpost; 
		state->handCount[i]++;
		handCount = state->handCount[i]-1;
		ret = cardEffect(outpost, 0, 0, 0, state, handPos, 0);
		assert(ret == 0);
		assert(state->outpostPlayed == 1);
		assert(handCount == state->handCount[i]);
	}
	printf("All tests passed! \n\n");
	return 0;
}
