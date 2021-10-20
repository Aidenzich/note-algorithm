#include <stdio.h>
#include <string.h>

int main(void){
    char input1[20], re_input[20];
    // https://www.includehelp.com/c/c-program-to-read-string-with-spaces-using-scanf-function.aspx
    scanf("%[^\n]", input1);
    
    int sum, tmp = 0;
    int j = 0;
    for (int i = 0; i < strlen(input1); i++){
        if (input1[i] != ' '){
            re_input[j] = input1[i];
            j++;
        }        
    }

    for (int i = 0; i < strlen(re_input); i++){
        char tmp = re_input[i];
        int char_num;
        sscanf(&tmp, "%d", &char_num); 
        if (i % 2 != 0){
            sum += 3 * char_num;
        } else {
            sum += char_num;
        }
    }
    
    int ans;
    ans = ((((sum -1)/10) * 10) + 10) - sum;

    printf("%d", ans);
    return 0;
}