#include <stdio.h>
#include <string.h>

#define NAME_LEN 50

typedef struct Addresses {
    char name[NAME_LEN+1];
    char street[100];
    char city[50]; 
    int pin;
} Address;

int main(){
    Address NCKU;
    strcpy(NCKU.name, "National Cheng Kung University");
    strcpy(NCKU.street, "East District");
    strcpy(NCKU.city, "Tainan City");
    
    printf("%s\n", NCKU.name);
    printf("%s\n", NCKU.street);
    printf("%s\n", NCKU.city);
}

