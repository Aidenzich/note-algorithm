#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char *temp = malloc(7);
    char *tempCapture = malloc(3);
    strcpy(temp, "HELLO!");    

    strncpy(tempCapture, temp, 3);
    printf("%s", tempCapture);
}
