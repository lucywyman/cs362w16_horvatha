#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

int main(int argc, char* argv[]){

    struct gameState *state;
    state = malloc(sizeof(struct gameState));
    srand(time(NULL));
    int k[10];
    int seed = rand();
    int i, j, temp, numPlayers, money, handPos, card;
    for(i = 0; i < 10; ){
        temp = rand()%(treasure_map + 1 - 7) + 7;
	for(j = 0; j < 10; j++){
	     if(k[j] == temp){
                 break;
	     }
	}
	if(j == 10){
            k[i] = temp;
            i++;
        }    
    }
    for(i = 0; i < 10; i++){
         printf("DEBUG: k[%d] = %d\n", i, k[i]);
    }

    numPlayers = rand()%(4 + 1 - 2) + 2;
    printf("DEBUG: number of players is %d\n", numPlayers);
    initializeGame(numPlayers, k, seed, state);

    while(!isGameOver(state)){
        money = 0;
        for(i = 0; i < numHandCards(state); i++){
            if((handCard(i, state)) == copper){
                money++;
            }
	    else if((handCard(i, state)) == silver){
                money += 2;
	    }
            else if((handCard(i, state)) == gold){
                money += 3;
	    }

	}
	for(i = 0; i < numPlayers; i++){
	    handPos = rand()%numHandCards(state);
	    if(handPos > 6){
	        if(playCard(handPos, -1, -1, -1, state) < 0){
                    printf("DEBUG: card was unable to be played\n");
	        }
	        else{
		    card = handCard(handPos, state);
                    printf("Player %d played card %d\n", i, card);
	        }

	    }
	    money = 0;
	    for(j = 0; j < numHandCards(state); j++){
                if(handCard(j, state) == copper){
                    playCard(j, -1, -1, -1, state);
		    money++;
		}
		else if(handCard(j, state) == silver){
                    playCard(j, -1, -1, -1, state);
		    money += 2;
		}
		else if(handCard(j, state) == gold){
                    playCard(j, -1, -1, -1, state);
		    money += 3;
		}
	    }
	    if(money >= 8){
                printf("Player %d bought province\n", i+1);
                buyCard(province, state);
	    }
	    else{
		card = k[rand()%10];
                //printf("Player %d bought %d\n", i+1, card);
		if(buyCard(card, state) < 0){
                    printf("Player %d failed in buying a card\n", i+1);
		}
		else{
                    printf("Player %d bought %d\n", i+1, card);
		}
	    }
	    printf("End player %d's turn\n", i+1);
	    endTurn(state);
	}
 	
    }


    printf("Ended game\n");

    return 0;

}
