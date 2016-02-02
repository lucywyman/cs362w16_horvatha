#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>
#include "rngs.h"
#include "my_assert.h"

int main(int argc, char* argv[]){

    /*
     *create random numbers for arguments for buyCard (including randomly assigning values to gameState Struct fields: whoseTurn, numBuys, coins, and set phase to 0)
     *call buyCard
     *check if it returned 0
     */ 

    srand(time(NULL));

    int ret;
    int supplyPos = rand()%5;
    struct gameState *state = malloc(sizeof(struct gameState));
    state->whoseTurn = 0;
    state->numBuys = rand()%2;
    state->coins = rand()%15;
    state->phase = 0;

    ret = buyCard(supplyPos, state);

    assert(ret == 0);

    fprintf(stdout, "Test passed\n");

    return 0;

}