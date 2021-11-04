// Input
// Integer n represents the number of boxes.

// Then, there are n lines.

// In each line, an integer x(1<=x<=10^9) and a character y(could be any ASCII character) represent the box's number and the plan's name respectively.

// Output
// From plan A to Z, output the plan is found or not.

// For example, output "Plan A is in box 12." if the plan A is found in box 12. Otherwise, output "Not found plan B." if the plan B is not found.

// Limits
// Your program needs to finish task in 1 second.

// Your program can only use memory less than 5000 KB.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int round, box_num;
    char plan;
    scanf("%d", &round);
    
    int space[26] = {0};
    

    for (int i=0; i<round; i++){
        box_num = 0;
        scanf("%d %c", &box_num, &plan);
        if (plan >= 'A' && plan<='Z'){
            space[(int)plan-'A'] = box_num;
        }
    }

    for (int i=0; i<26; i++){
        
        if (space[i]!=0){
            printf("Plan %c is in box %d.\n", ('A'+i), space[i]);
        } else {
            printf("Not found plan %c.\n", ('A'+i));
        }
    }
    
}