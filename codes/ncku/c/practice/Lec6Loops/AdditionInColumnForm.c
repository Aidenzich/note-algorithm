// Description


#include <stdio.h>

int main(void){    
    int round, cp1, cp2;
    scanf("%d", &round);
    int round_win = 0;
    int win, loss;
    for (int r = 0; r < round; r++){
        win = 0;
        loss = 0;
        for (int i = 0; i < 3; i++){            
            scanf("%d %d", &cp1, &cp2);
            if (cp1 > cp2){
                win++;
            }
            if (cp1 < cp2){
                loss++;
            }
        }
        if (win > loss){
            printf("Win\n");
            round_win++;
        }
        else if (loss > win){
            printf("Loss\n");
        }
        else {
            printf("Tie\n");
        }        
    }
    printf("%.2f%%", (100 * (float)round_win/round));
}