#include<stdio.h>
#include<stdbool.h>


void lineup_again (char line[]);
void swap(char *a, char *b);
void reverse_caterpillar(char *l, char *r);

int main() {
    char line[1000000];
    scanf("%s", line);
    lineup_again(line);
    printf("%s", line);
}

void lineup_again(char line[]){
    int left = 0;
    int right = 0;
    int is_caterpillars = 0;
    
    for (int i=0; i < 1000000; i++){
        if (line[i]=='A' || line[i]=='Z'){
            is_caterpillars++;
            if (is_caterpillars==1){
                left = i;
            }
            
            if (is_caterpillars==2){
                right = i;                
                is_caterpillars=0;                
                if (line[left] != 'A'){
                    reverse_caterpillar(&line[left], &line[right]);
                }
            }
        }

        if (line[i] == '\0'){   // check char is not null            
            break;
        }                
    }
}

void swap(char *a, char *b){
    char tmp = *a;
    *a = *b;
    *b = tmp;    
}


void reverse_caterpillar(char *l, char *r){    
    for (int i=0; i<=((r-l)/2); i++){
        swap(l+i, r-i);
    }
}