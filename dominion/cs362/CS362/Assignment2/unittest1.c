/* unit test for getCost function in dominion.c */
#include <stdio.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"

int main(){
	int i;
	int ret;
	printf("\nUnit test 1 for the getCost function in dominion.c \n");
	for(i = -5; i < 30; i++){
		ret = getCost(i);
	switch( i ) 
    {
    case curse:
   		assert(ret == 0);
	 	break;
    case estate:
		assert(ret == 2);
	 	break;
    case duchy:
      assert(ret == 5);
	 	break;
    case province:
      assert(ret == 8);
	 	break;
    case copper:
      assert(ret == 0);
	 	break;
    case silver:
      assert(ret == 3);
	 	break;
    case gold:
      assert(ret == 6);
	 	break;
    case adventurer:
      assert(ret == 6);
	 	break;
    case council_room:
      assert(ret == 5);
	 	break;
    case feast:
		assert(ret == 4);
	 	break;
    case gardens:
      assert(ret == 4);
	 	break;
    case mine:
      assert(ret == 5);
	 	break;
    case remodel:
      assert(ret == 4);
	 	break;
    case smithy:
      assert(ret == 4);
	 	break;
    case village:
      assert(ret == 3);
	 	break;
    case baron:
      assert(ret == 4);
	 	break;
    case great_hall:
      assert(ret == 3);
	 	break;
    case minion:
      assert(ret == 5);
	 	break;
    case steward:
      assert(ret == 3);
	 	break;
    case tribute:
      assert(ret == 5);
	 	break;
    case ambassador:
      assert(ret == 3);
	 	break;
    case cutpurse:
      assert(ret == 4);
	 	break;
    case embargo: 
      assert(ret == 2);
	 	break;
    case outpost:
      assert(ret == 5);
	 	break;
    case salvager:
      assert(ret == 4);
	 	break;
    case sea_hag:
      assert(ret == 4);
	 	break;
    case treasure_map:
      assert(ret == 4);
	 	break;
	}
	if (i > 26 || i < 0){
		assert(ret == -1);
	}
	printf("\tTest passed with input i: %d, and return value from getCost: %d \n", i, ret);
}

	printf("All tests passed!\n\n");
	return 0;
}
