// Everybody! Cirno's math class is about to begin! Do your best to become a genius!
// Not only the math class, Cirno also operates a bus company "Gensokyo Bus",
// One day she wants to know how many passengers is onboard when the bus passes each station,
// but everybody knows cirno is a "⑨. Baka" (a.k.a. an idiot),
// so please help her to calculate this.

// Problem:

// A bus left the Scarlet Devil Mansion (say, X station); A people boarded at the start
// At Hakugyokurou (say, Y station), B left and C people boarded
// At Yakumo-san's house (say, Z station), D people left; so how many passengers is on board after each station?
// To help cirno understand the number, please left-padding each number to 4 digits with 0
#include <stdio.h>
#include <math.h>
int main(void){    
    int arr[4];
    int res[3];
    for (int i=0; i<4; i++){
        scanf("%d", &arr[i]);
    }
    res[0] = arr[0];
    res[1] = res[0] - arr[1] + arr[2];
    res[2] = res[1] - arr[3];

    printf("%.4d %.4d %.4d", res[0], res[1], res[2]);        
    return 0;
}