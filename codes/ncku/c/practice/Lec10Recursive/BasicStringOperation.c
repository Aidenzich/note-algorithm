#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
char str[1025];

void print (){    
    printf("%s\n", str);
}

void reverse(int begin, int end)
{
   char c;
   if (begin >= end)
      return;

   c  = *(str+begin);
   *(str+begin) = *(str+end);
   *(str+end) = c;

   reverse(++begin, --end);
}

void toUpper(){    
    for (int i=0; i<1025; i++){
        str[i] = toupper(str[i]);
    }
}

void toLower(){
    for (int i=0; i<1025; i++){
        str[i] = tolower(str[i]);
    }
}

void removeChar(char remove){
    
    int i, j;
    int len = strlen(str);    
    for (i=0; i<len; i++){
        if(str[i] == remove){
            for(j=i; j<len; j++){
                str[j] = str[j+1];
            }
            len--;
            i--;
        }
    }    
}

void compress(){
    int n = 1025;
    char tmpStr[1025];
    char tmp[1025];
    
    for (int i = 0; i < n; i++) {        
        if (str[i]=='\0') break;

        int count = 1;
        while (i < n - 1 && str[i] == str[i + 1]) {
            count++;
            i++;
        }
                
        snprintf(tmp, sizeof(tmp), "-%c%d", str[i], count);
        strcat(tmpStr, tmp);
    }
    
    strcpy(str, tmpStr);
}
 

int main () {
    char c;
    int strIndex = 0, operateNum = 0;
    char operate[100];
    while((c = getchar()) != '\n' && c != EOF){
        str[strIndex] = c;
        strIndex++;
    }

    scanf("%d", &operateNum);
    for (int i=0; i<operateNum; ++i){
        scanf("%s", operate);        
        if (strcmp(operate, "PRINT") == 0){
            print();
        }

        if (strcmp(operate, "REVERSE") == 0){
            reverse(0, strlen(str)-1);
            print();
        }

        if (strcmp(operate, "TO_UPPER") == 0){
            toUpper();
            print();
        }
        
        if (strcmp(operate, "TO_LOWER") == 0){
            toLower();
            print();
        }
        
        if (strcmp(operate, "REMOVE") == 0){                       
            getchar();
            char c = getchar();            
            removeChar(c);
            print();
        }
        if (strcmp(operate, "COMPRESS") == 0){                       
            compress();
            print();
        }
    }
    return 0;
}
