// unit test for council room card
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
	int numBuys;
	int otherPlayersHand[4];
	struct gameState *state = malloc(sizeof(struct gameState));
	time_t t;

	printf("Unit test 6 for council room card in dominion.c \n");
	srand((unsigned)time(&t));
	state->numPlayers = MAX_PLAYERS;
	for(k = 0; k < 1000; k++){		
		for(i = 0; i < MAX_PLAYERS; i++){
			state->deckCount[i] = 0;
			state->handCount[i] = 0;
			handPos = 0;
			state->numBuys = rand()%5;
			numBuys = state->numBuys+1;
			state->whoseTurn = i;
			handPos = rand()%(MAX_HAND-4); //can't draw more than max hand
			for(j = 0; j < handPos; j++){
				randomCard = rand()%(treasure_map+1); 
				state->hand[i][j] = randomCard;
				state->handCount[i]++;
			}
			for(j = 0; j < (MAX_DECK-handPos); j++){
				state->deck[i][j] = randomCard;
				state->deckCount[i]++;
			}
			state->hand[i][handPos] = council_room; 
			state->handCount[i]++;
			handCount = state->handCount[i]+3;
			for(j = 0; j < MAX_PLAYERS; j++){
				if(j != i){
					state->discardCount[j] = 0;
					state->handCount[j] = rand()%MAX_HAND;
					state->deckCount[j] = 10;
					otherPlayersHand[j] = state->handCount[j]+1;
				}
			}
			ret = cardEffect(council_room, 0, 0, 0, state, handPos, 0);
			assert(ret == 0);
	//		printf("%d : %d || %d : %d ;%d\n", handCount, state->handCount[i], handPos, state->deckCount[i], ret);
			assert(handCount == state->handCount[i]);
//			printf("%d : %d \n", state->numBuys, numBuys);
			assert(numBuys == state->numBuys);
			for(j = 0; j < MAX_PLAYERS; j++){
				if(j != i){
				//	printf("%d : %d \n", state->handCount[j], otherPlayersHand[j]);
					assert(state->handCount[j] == otherPlayersHand[j]);
				}
			}
		}
	}
	printf("All tests passed! \n\n");
	return 0;
}
