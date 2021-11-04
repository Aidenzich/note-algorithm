#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 300000

int main()
{
    // ASKII CODE
    char str[MAX_LENGTH], ch;
    int i, key, tmp;
    
    

    // https://stackoverflow.com/questions/1247989/how-do-you-allow-spaces-to-be-entered-using-scanf    
    scanf("%d %[^\n]", &key, str);

    if (abs(key) > 26){
        key = key % 26;
    }
    // printf("%d\n", key);
    
    for(i = 0; str[i] != '\0'; ++i){    
        ch = str[i];
        if(ch >= 'a' && ch <= 'z'){
            tmp = ch + key;
            if( tmp > 'z'){
                tmp = tmp - 'z' + 'a' - 1;            
            }
            if (tmp < 'a'){
                tmp = tmp +26;
            }
            
            str[i] = tmp;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            tmp = ch + key;            
            if(tmp > 'Z'){
                tmp = tmp - 'Z' + 'A' - 1;
            } else if (ch < 'A'){
                ch = ch + 26;
            }
            if (tmp < 'A'){
                tmp = tmp + 26;
            }
            str[i] = tmp;
        }        
    }
    printf("%s", str);
    return 0;
}