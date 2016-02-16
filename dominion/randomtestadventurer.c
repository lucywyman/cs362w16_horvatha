#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define MAX_TESTS 1200

//This randomly tests Adventurer

int main() {

	  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};

	  int ret, handPos, coinCount, discardCount, i, j, n, players, player, handCount, deckCount, seed, address;
	  struct gameState state;

	  srand(time(NULL));

	  printf("Running Random Adventurer Test\n");

	  /*
										--- Author's Note ---
	  So, I had problems running out of memory when I used the same gameState variable more than 12 times, and
	  I honestly don't know why. I momentarily solved this problem by adding more for loops and creating more gamestates;
	  I was still able to get decent coverage, though not up to the amount of tests I originally had in mind.

	  */

	  for (i = 0; i < MAX_TESTS; i++) {
	     for(j = 0; j < 4; j++){	  
	          state.deckCount[j] = 0; //Pick random deck size out of MAX DECK size
		  state.discardCount[j] = 0;
		  state.handCount[j] = 0;
                  state.coins = 0;
		  //handPos = 0;
		  coinCount = 2;
                  state.whoseTurn = j;
		  //Copy state variables
		  handCount = rand()%(MAX_HAND - 1);
		  deckCount = rand()%(MAX_DECK - handCount);
		  handPos = rand()%(handCount + 1);
		  discardCount = rand()%(MAX_DECK - deckCount);

		  for(n = 0; n < handCount; n++){
		      state.hand[j][n] = rand()%(treasure_map + 1);
		      state.handCount[j]++;
		  }

		  for(n = 0; n < deckCount; n++){
		      state.deck[j][n] = rand()%(treasure_map + 1);
		      state.deckCount[j]++;
		  }

		  for(n = 0; n < discardCount; n++){
		      state.discard[j][n] = rand()%(treasure_map + 1);
		      state.discardCount[j]++;
		  }

		  //1 in 3 chance of making empty deck for coverage
		 if(rand()% 3 == 0) {
			state.deckCount[j] = 0;
		 }
                 state.hand[j][handPos] = adventurer;
                 ret = cardEffect(adventurer, 0, 0, 0, &state, handPos, 0);
		 assert(ret == 0);
		
		}

	  }
	  
	  printf("Tests Complete\n");

	  return 0;
}
