#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include "rngs.h"
#include "my_assert.h"

int main(int argc, char *argv[]){

    /*
     *generate random values for handPos and the fields within gameStruct (phase = 0, numActions >= 1, whoseTurn 0 || 1), choice 1 2 and 3 should all be -1
     *assert that it returns 0
     *
     */ 

    srand(time(NULL));
    fprintf(stdout, "Testing PlayCard\n");

    int ret;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    int handPos = 0;
    int supplyPos = 0;
    int seed = rand()%100;
    struct gameState *state = malloc(sizeof(struct gameState));
    initializeGame(2, k, seed, state);
    state->handCount[0] = 5;
    state->phase = 0;
    state->numActions = 2;
    state->whoseTurn = 0;
    state->numBuys = 2;
    state->coins = 8;
    state->hand[0][0] = council_room;
    ret = playCard(handPos, -1, -1, -1, state);

    assert(ret == 0);

    fprintf(stdout, "Passed test\n");




    return 0;

}
