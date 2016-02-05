#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"


int main(int argc, char* argv[]){

    struct gameState *state = malloc(sizeof(struct gameState));
    int ret;

    fprintf(stdout, "Testing gardens card\n");

    ret = cardEffect(gardens, 0, 0, 0, state, 0, 0);

    assert(ret == -1);

    fprintf(stdout, "Test passed!\n");

    return 0;



}
