#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include <assert.h>
#include "dominion_helpers.h"

int main(int argc, char* argv[]){


    int i, ret, handPos, handNum;
    struct gameState *state = malloc(sizeof(struct gameState));

    fprintf(stdout, "Beginning test for smithy card\n");

    state->deckCount[0] = 0;
    state->handCount[0] = 0;
    handPos = rand()%(MAX_HAND-3);
    state->whoseTurn = 0;
    for(i = 0; i < handPos; i++){
        state->hand[0][i] = rand()%(treasure_map+1);
        state->handCount[0]++;
    }
    for(i = 0; i < (MAX_DECK - handPos); i++){
        state->deck[0][i] = state->hand[0][handPos - 1];
	state->deckCount[0]++;
    }
    state->hand[0][handPos] = smithy;
    state->handCount[0]++;
    handNum = state->handCount[0] + 2;
    ret = cardEffect(smithy, 0, 0, 0, state, handPos, 0);
    assert(ret == 0);
    //fprintf(stdout, "handNum: %d, state->handCount[0]: %d\n", handNum, state->handCount[0]);
    assert(handNum == state->handCount[0]);

    fprintf(stdout, "Tests passed!\n");

    return 0;

}
