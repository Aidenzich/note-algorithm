#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 100

int secret_number;

/* prototypes */
void initialize_number_geneator(void);
void choose_new_secret_number(void);
void read_guesses(void);


int main(void){
    char command;
    initialize_number_geneator();
    do {
        choose_new_secret_number();
        read_guesses(secret_number);
        scanf(" %c", &command);
    } while ( command == 'y' || command == 'Y')
        
}


void initialize_number_geneator(void){
    srand((unsigned) time(NULL));
}

void choose_new_secret_number(void){
    secret_number = rand() % MAX_NUMBER + 1;
}

void read_guesses(void){
    int guess, num_gusses = 0;
    for (;;) {
        num_gusses++;
        scanf("%d", &guess);
        if (guess == secret_number){
            return ;
        } else if (guess < secret_number)
            printf("Too low; try again.\n");
        else
            printf("Too high; try again.\n");        
    }
}

