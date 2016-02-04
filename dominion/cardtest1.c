#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdlib.h>
#include <assert.h>
#include <time.h>

int main(int argc, char* argv[]){

    srand(time(NULL));
    struct gameState *state = malloc(sizeof(struct gameState));
    int ret;
    int i;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    int seed = rand()%100;
    int choice1 = ambassador;
    int choice2 = adventurer;
    initializeGame(2, k, seed, state);
    // todo: make sure there is at least one adventurer in the supplyCount


    fprintf(stdout, "Testing cardEffect of remodel\n");
    state->hand[0][0] = remodel;
    state->hand[0][1] = ambassador;
    //state->handCount[0] = 2;

    ret = cardEffect(remodel, choice1, choice2, 0, state, 0, 0);


    /*for(i = 0; i < state->handCount[0]; i++){
        fprintf(stderr, "card %d: %d\n", i, state->hand[0][i]);
    }*/
    assert(ret == 0);
    fprintf(stdout, "Test passed\n");





    return 0;

}
