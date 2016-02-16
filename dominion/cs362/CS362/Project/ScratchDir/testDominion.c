#include <stdio.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]){
//adventurer 7, treasure map 26
//printf("%d \t %d \n", adventurer, treasure_map);
	int kingdomCards[10];
	int money, numPlayers, randomCard, numCards = 0, i, k, alreadyTaken = 0, seed, choice1, choice2, choice3;	
	struct gameState *state = malloc(sizeof(struct gameState));
	//time_t t;
	printf("Kingdom cards: ");
//	srand((unsigned)time(&t));
	srand(10);
	while(numCards < 10){
		randomCard = rand()%(treasure_map-6);
		randomCard += 7; //any card before adventurer is not a kingdom card
		if(randomCard < adventurer || randomCard > treasure_map){
			printf("TOOOO BIG  \t");
		}
		for(i = 0; i < numCards; i++){
			if(randomCard == kingdomCards[i]){
				alreadyTaken = 1;
				break;
			}
		}
		if(0 == alreadyTaken){	
			kingdomCards[numCards] = randomCard;
			printf("%d \t", kingdomCards[numCards]);
			numCards++;
		}
		alreadyTaken = 0;
	}
	numPlayers = rand()%3;
	numPlayers++;
	seed = atoi(argv[1]);
	initializeGame(numPlayers, kingdomCards, seed, state);
	printf("\n\n");
	while(!isGameOver(state)){
		printf("Taking turn player %d \n", state->whoseTurn+1);
		money = 0;
		for(i = 0; i < numHandCards(state); i++){
			randomCard = handCard(i, state);
			if(randomCard == copper){
				money++;
			}
			else if(randomCard == silver){
				money+=2;
			}
			else if(randomCard == gold){
				money+=3;
			}
			else{
				for(k = 0; k < 10; k++){
					if(randomCard == kingdomCards[k]){
						choice1 = rand()%3;
						choice2 = rand()%3;
						choice3= rand()%3;
						if(randomCard == feast){
				//			choice2 = rand()%10;
				//			choice1 = kingdomCards[choice2];
				//			choice2 = 0;
				//			choice3 = 0;
							break;
						}
						printf("Playcard: %d, choice1- %d, choice2- %d, choice3- %d \n", randomCard, choice1, choice2, choice3);
						playCard(i, choice1, choice2, choice3, state);
						break;
					}
				}
			}		
			if(state->numActions < 1){
				break;
			}
		}
		while(state->numBuys > 0){
			choice1 = rand()%2;
			if(choice1 == 1){
				i = rand()%10;
				if(getCost(kingdomCards[i]) <= money){
					buyCard(kingdomCards[i], state);
					printf("Bought card %d\n", kingdomCards[i]);
				}
			}
			else{
				i = rand()%6;//want to go for cards in range 1-6
				i++;
				if(getCost(i) <= money){
				choice2 = rand()%3;
					if((i == copper || i == estate)&& choice2 != 0){
						printf("No buy \n"); 		//avoid only buying copper
						break;
					}
					buyCard(i, state);
					printf("Bought card %d\n", i);
				}
			}
		}
		endTurn(state);
		for(i = 0; i < numPlayers; i++){
			printf("Score for Player #%d: %d\n", i, scoreFor(i, state));
		}
		printf("\n");
	}
	printf("Game Over! \n");
	for(i = 0; i < numPlayers; i++){
		printf("Score for Player #%d: %d\n", i, scoreFor(i, state));
	}
	return 0;
}
