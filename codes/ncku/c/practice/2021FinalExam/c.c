// gcc c.c -o c && ./c < c.in
#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define GOODS_SIZE 120
#define MAX_ORDER_SIZE 30
#define MAX_NAME_LEN 15

void recovering_order(char *, char **);

char names[GOODS_SIZE][MAX_NAME_LEN] = {
    "aluminum", "ammunition", "orange", "aspirin", "ax",
    "basketball", "zipper", "bell", "blanket", "drum",
    "canvas", "flute", "eraser", "mirror", "comb",
    "eggplant", "diamond", "zucchini", "door", "butter",
    "egg", "dart", "chair", "encyclopedia", "china",
    "fan", "glue", "elevator", "flower", "hat",
    "garlic", "strawberry", "glove", "flour", "ice",
    "ship", "hammer", "fur", "key", "honey",
    "grape", "icecream", "lock", "iron", "ivory",
    "jacket", "oil", "uniform", "kiwi", "pan",
    "helmet", "keyboard", "yoyo", "jet", "knife",
    "tie", "lemon", "xerox", "ink", "mutton",
    "newspaper", "melon", "coconut", "motorcycle", "longan",
    "nail", "rice", "magnet", "peanut", "ointment",
    "oar", "jeans", "nut", "arrow", "oven",
    "jewel", "wool", "noodle", "pencil", "lamp",
    "refrigerator", "needle", "roast", "vest", "yarn",
    "saw", "hamburger", "soap", "glass", "wine",
    "tangerine", "pillow", "umbrella", "zinc", "train",
    "uglifruit", "toast", "underwear", "vanilla", "jeep",
    "unicycle", "vase", "rope", "violin", "warship",
    "volleyball", "water", "yogurt", "submarine", "passionfruit",
    "yacht", "rose", "window", "yolk", "kite",
    "liquor", "xylophone", "toothbrush", "battery", "doll"
};

int main(void) {
    char order[500] = "", *result = NULL;
    scanf("%s", order);
    recovering_order(order, &result);
    printf("%s", result);
    free(result);
    return 0;
}

int strins(char *name, char *split){
    int count =0, pos =0;
    int nlen = strlen(name), slen = strlen(split);
    for (int i=0; i<=nlen; i++){
        if (*(name+i) == *(split+count)){
            count++;
            if (count >= slen){
                return i;
            }
        }
    }
    
    return 1000000;
}

void recovering_order(char *order, char **result) {
    // printf("%s %s\n", order, *result);
    
    char * split = strtok(order, ":");
    char splitArr[GOODS_SIZE][350];
    *result = malloc(45000);
    int splitCount = 0;
    while (split != NULL){
        int min = 1000000;
        char guess[MAX_NAME_LEN];
        // printf("%s\n", split);
        for (int i=0; i<120; i++){
            int sindex = strins(names[i], split);
            if (min > sindex){
                min = sindex;
                strcpy(guess, names[i]);
            }   
            if (min == sindex){
                int oldlen= strlen(guess);
                int newlen= strlen(names[i]);
                if (newlen < oldlen){
                    strcpy(guess, names[i]);
                }
                if (newlen == oldlen){
                    
                    if (strcmp(guess, names[i]) > 0){
                        strcpy(guess, names[i]);
                    }
                }
            }
        }
        
        
        strcpy(splitArr[splitCount], guess);
        splitCount++;
        split = strtok(NULL, ":");
        
    }
    
    for (int i=0; i<splitCount; i++){
        // printf("%s\n", splitArr[i]);
        if (i != splitCount -1){
            strcat(splitArr[i], "+");    
        }
        strcat(*result, splitArr[i]);
    }


    
    
    // printf("%d", resultTemp);
    return;
}


