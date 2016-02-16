//unittest for fullDeckCount in dominion.c
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
	int randomCard;
  	int count = 0;
	int randomPile;	
	struct gameState *state = malloc(sizeof(struct gameState));
	time_t t;
	srand((unsigned)time(&t));

	printf("Unit test 4 for the fullDeckCount function in dominion.c \n");
	for(j = 0; j < MAX_PLAYERS; j++){
		for(i = 0; i < treasure_map+1; i++){
			state->deckCount[j] = 0;
			state->handCount[j] = 0;
			state->discardCount[j] = 0;
			count = 0;
			for(k = 0; k < MAX_DECK; k++){
				randomCard = rand()%treasure_map+1;
					if(randomCard == i){
						count++;				
					}
					randomPile = rand()%3;
					if(randomPile == 0){
						state->deck[j][state->deckCount[j]] = randomCard;
						state->deckCount[j]++;
					}
					else if(randomPile == 1){
						state->hand[j][state->handCount[j]] = randomCard;
						state->handCount[j]++;
					}
					else if(randomPile == 2){
						state->discard[j][state->discardCount[j]] = randomCard;
						state->discardCount[j]++;
					}
			}	
			ret = fullDeckCount(j, i, state);
	//	printf("%d : %d || %d : %d \n", ret, count, i, j);
			assert(ret == count);
		}
	}
	printf("All test passed! \n\n");
	return 0;
}
