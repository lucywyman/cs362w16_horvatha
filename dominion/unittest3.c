#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <assert.h>

int main(int argc, char* argv[]){


    int i;
    int ret;
    fprintf(stdout, "Testing getCost\n");

    for(i = 0; i < 27; i++){
	ret = getCost(i);
	switch(i){
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
    }




    fprintf(stdout, "Test passed\n");

    return 0;

}
