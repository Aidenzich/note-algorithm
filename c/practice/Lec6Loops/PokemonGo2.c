// Description
// Ariel likes to play Pokémon Go! She had many battles in pokémon gym. She needs a tool to record the battle's result.
// She had n battles. Each battle is three-on-three and each pokémon has combat power(CP). If the combat power of Ariel's pokémon is more than competitor's, then Ariel's pokémon wins. If Ariel has more wins than competitor, she wins the battle. Please record each battle is "Win", "Tie", or "Lose" and calculate the win rates.

// For example,

// Ariel had a battle. Her three pokémons' combat power are 200, 300 and 400, and the competitor's three pokémons' combat power are 100,350 and 400. Then,

// 200>100 Win

// 300<350 Lose

// 400=400 Tie

// Because Ariel and competitor had the same number of wins, this battle is "Tie". Ariel had one battle and the number of wins is 0, then the win rates is 0/1 = 0.00%

#include <stdio.h>
#include <math.h>
int main(void){    
    float height;
    scanf("%f", &height);
    float g = 9.8;
    int time = 0;
    float ouput;
    while (height > (g * pow(time, 2))/2)
    {        
        ouput = height - (g * pow(time, 2))/2;
        time++;
        printf("%.1f\n", ouput);           
    }
    
}