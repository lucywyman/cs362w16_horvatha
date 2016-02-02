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
    struct gameState *state = malloc(sizeof(struct gameState));
    state->whoseTurn = 0;








    return 0;

}
