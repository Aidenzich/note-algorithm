#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20000

void find_fruit(char input[],char fruit[][15]);

int main(void) {
	char fruit[20][15] = {
        "guava",
        "litchi",
        "longan",
        "watermelon",
        "pomelo",
        "pear",
        "banana",
        "papaya",
        "pumpkin",
        "tomato",
        "mango",
        "kiwi",
        "persimmon",
        "cantaloupe",
        "strawberry",
        "grape",
        "peach",
        "orange",
        "coconut",
        "lemon"
    };
    char input[N];
    scanf("%s", input);
    find_fruit(input,fruit);
    return 0;
}


void find_fruit(char input[],char fruit[][15]){
    char fruitName[10];
    int fruitNameCount = 0;
    int countList[20]={0};
    char maxFruit[20][15] = {};

    for (int i=0; i<20000; i++){
                
        if (input[i] == '+' || input[i] == EOF || input[i]=='\0'){        
            i+=2;            
            // printf("%s\n", fruitName);
            for (int i2=0; i2<20; i2++){
                
                if (strcmp(fruitName, fruit[i2]) == 0){
                    // printf("===%s++===\n", fruit[i2]);
                    countList[i2]++; // Count Fruit Value
                    break;
                }
            }

            //Reset Fruit Name
            fruitNameCount=0;
            memset(fruitName, 0, sizeof(fruitName));
        } else {
            fruitName[fruitNameCount] = input[i];
            fruitNameCount++;
        }

        if (input[i] == EOF || input[i] == '\0'){
            break;
        }
    }


    int maxCount = 0;

    for (int i=0; i<20; i++){
        // printf("%s : %d\n", fruit[i], countList[i]);
        if (countList[i] > maxCount){
            maxCount = countList[i];
        }
    }

    // printf("%d", maxCount);
    int maxElementIndex = 0;
    for (int i=0; i<20; i++){        
        if (countList[i] == maxCount){
            strcpy(maxFruit[maxElementIndex], fruit[i]);
            maxElementIndex++;
        }
    }

    for (int i=0; i< 20; i++){
        if (maxFruit[i][0] != '\0' && maxFruit[i][0] != EOF){
            printf("%s\n", maxFruit[i]);
        }
    }
}