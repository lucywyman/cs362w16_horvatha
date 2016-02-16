//unit test for smithy card
#include <stdio.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdlib.h>
#include <time.h>

int main(){
	int i;
	int j;
	int k;
	int ret;
	int handPos;
	int randomCard;
	int handCount;
	struct gameState *state = malloc(sizeof(struct gameState));
	time_t t;

	printf("Unit test 5 for smithy card in dominion.c \n");
	srand((unsigned)time(&t));
	for(k = 0; k < 1000; k++){		
		for(i = 0; i < MAX_PLAYERS; i++){
			state->deckCount[i] = 0;
			state->handCount[i] = 0;
			handPos = 0;
			state->whoseTurn = i;
			handPos = rand()%(MAX_HAND-3); //can't draw more than max hand
			for(j = 0; j < handPos; j++){
				randomCard = rand()%(treasure_map+1); 
				state->hand[i][j] = randomCard;
				state->handCount[i]++;
			}
			for(j = 0; j < (MAX_DECK-handPos); j++){
				state->deck[i][j] = randomCard;
				state->deckCount[i]++;
			}
			state->hand[i][handPos] = smithy; 
			state->handCount[i]++;
			handCount = state->handCount[i]+2;
			ret = cardEffect(smithy, 0, 0, 0, state, handPos, 0);
			assert(ret == 0);
	//		printf("%d : %d || %d : %d ;%d\n", handCount, state->handCount[i], handPos, state->deckCount[i], ret);
			assert(handCount == state->handCount[i]);
		}
	}
	printf("All test passed! In all cases the player drew three cards and discarded smithy\n\n");
	return 0;
}
