// unit test to check garden
#include <stdio.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdlib.h>

int main(){
	
	int ret=0;
	struct gameState *state =  malloc(sizeof(struct gameState));
	
	printf("Unit test 7 for garden in dominion.c \n");
	ret = cardEffect(gardens, 0, 0, 0, state, 0, 0);
	assert(ret == -1);

	printf("Test Passed! Card Effect returned -1 for gardens\n\n");

	return 0;
}
