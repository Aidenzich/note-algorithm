// Description
// Ariel likes to play Pokémon GO! Everyday, she will earn n poké balls and want to catch one pokémon. According to the Pokémon’s combat ability cp, health points hp, and speed s when the pokémon runs away, Ariel needs to use some poké balls to catch the pokémon. Please tell her whether she can catch the pokémon successfully. If yes, how many poké balls will remain?

// If the pokémon's combat ability is less than 100, Ariel only needs to use one poké ball.

// If the pokémon's combat ability is between 100 and 600 (including 100 and 600), she needs to use 5 poké balls. Furthermore, she has to use another 3 poké balls if the pokémon's health points are more than 100.

// If the pokémon's combat ability is more than 600, she needs to use 15 poké balls. Furthermore, she has to use another 10 poké balls if the pokémon's health points are more than 200.

// If the pokémon's speed is more than 4, the pokémon runs away after Ariel has used 6 poké balls. It means that she can't catch the pokémon anymore!

// Input
// An integer n represents the number of Poké Balls.(1<=n<=50)

// Two integer cp, hp represents the Pokémon's combat power and health points, respectively.(1<=cp<=1000, 1<=hp<=1000)

// An integer s represents the Pokémon's speed.(1<=s<=10)

// Output
// Output "NO" if Ariel can't catch Pokémon. Otherwise, Output "YES" and remaining Poké Balls.

// Limits
// Your program needs to finish task in 1 second.

// Your program can only use memory less than 5000 KB.

#include<stdio.h>

int main () {
    int n, cp, hp , s, req;
    scanf("%d%d%d%d", &n, &cp, &hp, &s);
    // printf("%d %d %d %d", n, cp, hp, s);

    if (cp < 100){
        req= 1;
    } else if ( cp >=100 && cp <=600 ){
        req= 5;
        if (hp > 100){
            req=8;
        }
    } else if ( cp > 600 ){
        req = 15;
        if (hp > 200){
            req = 25;
        }
    }
    if (s > 4 & req>6){
        printf("NO");
        return 0;
    }

    if ( n >= req){        
        printf("YES\n");
        printf("%d", (n - req));
    } else {
        printf("NO");
    }

    return 0;
}
