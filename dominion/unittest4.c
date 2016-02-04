#include <stdio.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdlib.h>

int main(int argc, char* argv[]){

    int ret;
    int expectedCoinCount = 6;
    
    struct gameState *state = malloc(sizeof(struct gameState));
    
    fprintf(stdout, "Beginning unit test 4 for updateCoins\n");
    
    state->handCount[0] = 3;
    state->hand[0][0] = copper;
    state->hand[0][1] = silver;
    state->hand[0][2] = gold;
    ret = updateCoins(0, state, 0);

    assert(expectedCoinCount == state->coins);

    assert(ret == 0);

    fprintf(stdout, "All tests passed.\n");


    return 0;



}
