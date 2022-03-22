#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

/* external variables */
int num_in_rank[NUM_RANKS];

/* prototypes */
void read_cards(void);
void analyze_hand(void);
void print_result(void);

int main(){

}

void read_cards(){
    // store information into several external variables
    while (cards_read < NUM_CARDS){
        bad_card = false;
        rank_ch = getchar();
        switch (rank_ch) {
            case '0': exit(EXIT_SUCCESS);
            case '2': rank = 0; break;
            case '3': rank = 1; break;
            case '4': rank = 2; break;
            case '5': rank = 3; break;
            case '6': rank = 4; break;
            case '7': rank = 5; break;
            case '8': rank = 6; break;
            case '9': rank = 7; break;
            case 't': case 'T': rank = 8; break;
            case 'j': case 'J': rank = 9; break;
            case 'q': case 'Q': rank = 10; break;
            case 'k': case 'K': rank = 11; break;
            case 'a': case 'A': rank = 12; break;
            default: bad_card = true;
        }
        suit_ch = getchar();
        switch (suit_ch){
            case 'c': case 'C': suit = 0; break;
            case 'd': case 'D': suit = 1; break;
            case 'h': case 'H': suit = 2; break;
            case 's': case 'S': suit = 3; break;
            default: bad_card = true;

        }
    }
}

void analyze_hand(){
    // need to know how many cards are in each rank and each suit
}