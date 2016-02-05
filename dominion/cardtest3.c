#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <assert.h>
#include <time.h>

int main(int argc, char* argv[]){
    
    srand(time(NULL));
    struct gameState *state = malloc(sizeof(struct gameState));
    int handNum, ret, randCard, handPos, i;
    
    fprintf(stdout, "Testing outpost card\n");
    
    state->deckCount[0] = 0;
    state->outpostPlayed = 0;
    state->whoseTurn = 0;

    handPos = 3;
    for(i = 0; i < handPos; i++){
	randCard = rand()%(treasure_map + 1);
        state->hand[0][i] = randCard;
	state->handCount[0]++;
    }
    for(i = 0; i < (MAX_DECK - handPos); i++){
        state->deck[0][i] = randCard;
	state->deckCount[0]++;
    }

    state->hand[0][handPos] = outpost;
    state->handCount[0]++;
    handNum = state->handCount[0] - 1;
    ret = cardEffect(outpost, 0, 0, 0, state, handPos, 0);
    assert(ret == 0);
    assert(state->outpostPlayed == 1);
    assert(handNum == state->handCount[0]);

    fprintf(stdout, "Tests passed\n");
    





    return 0;

}
