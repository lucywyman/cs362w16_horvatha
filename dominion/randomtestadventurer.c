#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define MAX_TESTS 12

//This randomly tests Adventurer

int main() {

	  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};

	  int i, j, n, players, player, handCount, deckCount, seed, address;
	  //struct gameState state;
	  struct gameState state;
	  struct gameState stat;
	  struct gameState sta;

	  srand(time(NULL));

	  printf("Running Random Adventurer Test\n");

	  /*
										--- Author's Note ---
	  So, I had problems running out of memory when I used the same gameState variable more than 12 times, and
	  I honestly don't know why. I momentarily solved this problem by adding more for loops and creating more gamestates;
	  I was still able to get decent coverage, though not up to the amount of tests I originally had in mind.

	  */

	  for (i = 0; i < MAX_TESTS; i++) {

	   players = rand() % 4;

	   seed = rand();		//pick random seed
		
	   initializeGame(players, k, seed, &state);	//initialize Gamestate 

	   //Initiate valid state variables
	        for(j = 0; j < players; j++){
		    state.deckCount[j] = rand() % MAX_DECK + 2; //Pick random deck size out of MAX DECK size
		  state.discardCount[j] = rand() % MAX_DECK;
		  state.handCount[j] = rand() % MAX_HAND;


		  //Copy state variables
		  handCount = state.handCount[j];
		  deckCount = state.deckCount[j];

		  //1 in 3 chance of making empty deck for coverage
		  if (seed % 3 == 0) {

			state.deckCount[j] = 0;
		  }
		 // if(seed % 10 == 0){
                        state.deck[j][deckCount] = copper;
		  //}
		  //if(seed % 11 == 0){
                        state.deck[j][deckCount - 1] = silver;
		  //}
		  //if(seed % 12 == 0){
                        state.deck[j][deckCount - 2] = gold;
		  //}
		}
		  cardEffect(adventurer, 1, 1, 1, &state, 0, 0);		//Run adventurer card
	  }

	  fprintf(stdout, "made it through first loop\n");
	  
	   for (i = 0; i < MAX_TESTS; i++) {

  		  players = rand() % 4;
		  seed = rand();		//pick random seed
		
		  initializeGame(players, k, seed, &stat);	//initialize Gamestate

		  //Initiate valid state variables
		  for(j = 0; j < players; j++){
		      stat.deckCount[j] = rand() % MAX_DECK; //Pick random deck size out of MAX DECK size
		      stat.discardCount[j] = rand() % MAX_DECK;
		      stat.handCount[j] = rand() % MAX_HAND;


		  //Copy state variables
		      handCount = stat.handCount[j];
		      deckCount = stat.deckCount[j];

		  //1 in 3 chance of making empty deck for coverage
		      if (seed % 3 == 0) {

			stat.deckCount[j] = 0;
		      }
		  }

		  cardEffect(adventurer, 1, 1, 1, &stat, 0, 0);		//Run adventurer card
	  }

	   fprintf(stdout, "made it through second loop\n");

	   for (i = 0; i < MAX_TESTS; i++) {

  		  players = rand() % 4;
		  seed = rand();		//pick random seed
		
		  initializeGame(players, k, seed, &sta);	//initialize Gamestate
                  for(j = 0; j < players; j++){
		  //Initiate valid state variables
		      sta.deckCount[j] = rand() % MAX_DECK; //Pick random deck size out of MAX DECK size
		      sta.discardCount[j] = rand() % MAX_DECK;
		      sta.handCount[j] = rand() % MAX_HAND;


		  //Copy state variables
		      handCount = sta.handCount[j];
		      deckCount = sta.deckCount[j];

		  //1 in 3 chance of making empty deck for coverage
		      if (seed % 3 == 0) {

			sta.deckCount[j] = 0;
		      }
		  }
		  cardEffect(adventurer, 1, 1, 1, &sta, 0, 0);		//Run adventurer card

	   }

	  printf("Tests Complete\n");

	  return 0;
}
