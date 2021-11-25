#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 300000


// PD1 is zzzzzz awesome!!
int main()
{
    
    char order = 'a';
    char str[MAX_LENGTH], ch;
    long long i, key, tmp;
    scanf("%lld %c %[^\n]", &key, &order, str);

    

    for(i = 0; str[i] != EOF; ++i){
        if (llabs(key) > 26){
            key = key % 26;
        }    
        ch = str[i];
        if(ch >= 'a' && ch <= 'z'){
            tmp = (int)ch + key;                        
            if( tmp > 'z'){
                tmp = tmp - 'z' + 'a' - 1;            
            }
            if (tmp < 'a'){
                tmp = tmp +26;
            }
            // printf("ch: %d ", (int)ch);
            // printf("key: %lld ", key);
            // printf("tmp: %lld", tmp);
            // printf("\n");
            str[i] = tmp;
            
            if (order == 'a'){
                key++;
            } else if (order == 'd'){                
                key--;
            }
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
            if (order == 'a'){
                key++;
            } else if (order == 'd'){
                key--;
            }
        }
        
    }
    printf("%s", str);
    return 0;
}