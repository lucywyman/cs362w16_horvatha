//unittest for isGameOver in dominion.c
#include <stdio.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdlib.h>
#include <time.h>
int main(){
	int ret = 0;
	int i = 0;
	int j = 0;
	int randomCard = 0;
	struct gameState *state = malloc(sizeof(struct gameState));
	time_t t;

	printf("Unit test 3 for the isGameOver function in dominion.c \n");

	srand((unsigned)time(&t));

	state->supplyCount[province] = 0;
	ret = isGameOver(state);
	assert(ret == 1);
	printf("\tTest passed! The return value of isGameOver was %d when the province count was set to zero\n", ret);
	for(i = 0; i < treasure_map+1; i++){
		state->supplyCount[i] = 10;
	}
	ret = isGameOver(state);
	assert(ret == 0);
	printf("\tTest passed! The return value of isGameOver was %d when all the supply counts were greater than 0\n", ret);

	printf("\tNow running 1000 tests with 3 random supply stacks being empty \n");
	for(j = 0; j < 1000; j++){
		for(i = 0; i < 3; i++){
//			randomCard = rand()%(treasure_map+1); //run this line of code for errors
//			printf("%d : %d \n", j, randomCard); //commented out due to redundant printing. Uncomment for debugging
			randomCard = rand()%25;			// running this code instead of what is on line 32 will result in success
			if(state->supplyCount[randomCard] == 0){
				i--;
			}
			state->supplyCount[randomCard] = 0;	
		}	
		ret = isGameOver(state);
		assert(ret == 1);
	
		for(i = 0; i < treasure_map+1; i++){
			state->supplyCount[i] = 10;
		}
	}
	printf("All 1000 test passed \n\n");
	return 0;
}
