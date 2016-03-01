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
    int i, j, temp, numPlayers, money, moneyPos, handPos, card;
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
		moneyPos = i;
            }
	    else if((handCard(i, state)) == silver){
                money += 2;
	    }
            else if((handCard(i, state)) == gold){
                money += 3;
	    }

	}
	for(i = 0; i < numPlayers; i++){
	    if(numHandCards(state) != 0){
	        handPos = rand()%numHandCards(state);
	        printf("DEBUG: value of handPos is: %d\n", handPos);
	    }
	    else{
	        endTurn(state);
	    }
	    if(handCard(handPos, state) > 6){
	        card = handCard(handPos, state);
		switch(card){
		     case feast:
                         playCard(handPos, duchy, -1, -1, state);
			 break;
		     case mine:
			 playCard(handPos, moneyPos, silver, -1, state);
			 break;
		     case remodel:
			 playCard(handPos, 0, -1, -1, state);
			 break;
		     case baron:
			 playCard(handPos, 1, -1, -1, state);
			 break;
		     case minion:
			 playCard(handPos, 1, -1, -1, state);
			 break;
		     case steward:
			 playCard(handPos, 1, -1, -1, state);
			 break;
		     case ambassador:
			 playCard(handPos, 0, 2, -1, state);
			 break;
		     case embargo:
			 playCard(handPos, k[rand()%10], -1, -1, state);
			 break;
		     case salvager:
			 playCard(handPos, rand()%numHandCards(state), -1, -1, state);
			 break;
		     default:
			 //playCard(handPos, -1, -1, -1, state);
			 break;
		}
	        printf("DEBUG: in first if before playCard and we're going to play %d\n", card);
	        if(playCard(handPos, -1, -1, -1, state) < 0){ // try hardcoding certain playCard calls dependent upon the type of card
                    printf("DEBUG: card was unable to be played\n");
	        }
	        else{
		    card = handCard(handPos, state);
                    printf("Player %d played card %d\n", i + 1, card);
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
	    else if(money > 0){
		card = k[rand()%10];
                //printf("Player %d bought %d\n", i+1, card);
		if(buyCard(card, state) < 0){
                    printf("Player %d failed in buying a card\n", i+1);
		}
		else{
                    printf("Player %d bought %d\n", i+1, card);
		}
	    }
	    else{
	        buyCard(copper, state);
		printf("Player %d bought copper\n", i+1);
	    }
	    printf("End player %d's turn\n", i+1);
	    
	    endTurn(state);
	}
 	
    }


    printf("Ended game\n");

    return 0;

}
