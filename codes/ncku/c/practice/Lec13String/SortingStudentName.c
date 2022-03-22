#include<stdio.h>
#include<string.h>
#include <ctype.h>
// void sortStringByFirstChar(char input[][100], int num);
// void stringSwap(char *a , char *b);

int main(){
    int studentNum;
    
    scanf("%d", &studentNum);
    
    char studentNames[studentNum][100];

    for (int i=0; i < studentNum; ++i){        
        scanf("%s", studentNames[i]);        
    }
    
    // Sorting of a Set of Strings in Ascending alphabetical order
    for (int i =0; i<studentNum; i++){
        for (int j = i; j<studentNum; j++){
            char tempA[100], tempB[100];                
            for(int itr = 0; itr < 100; itr++){                    
                tempA[itr] = tolower(studentNames[i][itr]);
                tempB[itr] = tolower(studentNames[j][itr]);
            }            
            if (strcmp(tempA, tempB) > 0){
                char tempC[100];
                strcpy(tempC, studentNames[i]);
                strcpy(studentNames[i], studentNames[j]);
                strcpy(studentNames[j], tempC); 
            }    
    
        }
    }

    for (int i=0; i<studentNum; ++i){        
        printf("%s\n", studentNames[i]);
    }

    // char **ptr = names;
    // for (int i=0; i<student_num; i++){
    //     printf("%s", ptr[i]);
    // }
    // int temp_pointer = *names[0];
    // *temp_pointer = 'f';
    // stringSwap(names[0], names[1]);

    // for (int i=0; i<student_num; ++i){        
    //     printf("%s\n", names[i]);
    // }

    // sortStringByFirstChar(names, student_num);
    return 0;   
}


// void sortStringByFirstChar(char input[][100], int num){
//     for (int i=0; i< num; i++){
//         if (input[i][0] > 90){
//             printf("%d \n", (input[i][0] - 32));
//         } else {
//             printf("%d \n", input[i][0]);
//         }                
//     }
//     printf("\n");
// }

// void stringSwap(char *a , char *b){
//     char temp[100] = a;  
//     // printf("\n%s\n", temp);      
//     a = b;
//     b = temp;    
//     // printf("\n%s\n", a);
// }