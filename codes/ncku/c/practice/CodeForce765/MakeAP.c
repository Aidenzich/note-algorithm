// #include <stdio.h>
// #include <math.h>
// #include <stdlib.h>
// #include <stdbool.h>
// int main(){
//     int ArrayNum;
//     scanf("%d", &ArrayNum);
//     while(ArrayNum-- > 0){
//         int inputArray[3];
//         for (int i=0; i<3; i++){
//             scanf("%d", &inputArray[i]);
//         }
//         bool result = false;
//         for (int i=0; i<3; i++){
//             int temp;
//             if (i == 1){
//                 temp = abs(inputArray[0] - inputArray[2]);                
//                 if (temp % inputArray[i] == 0 && temp != 1) {
//                     result = true;
//                 }
//             }
//             if (i == 0){
//                 temp = abs(inputArray[2] - inputArray[1]);
//                 if (temp == 0){
//                     if (inputArray[2] % inputArray[i] == 0){
//                         result= true;
//                     }
//                 }
//                 if (temp % inputArray[i] == 0 && temp != 1) {
//                     result = true;
//                 }
//             }
            
//             if (i == 2){                
//                 temp = abs(inputArray[0] - inputArray[1]);                                
//                 if (temp == 0){
//                     if (inputArray[0] % inputArray[i] == 0){
//                         result= true;
//                     }
//                 }
//             }
            
            
            

            
            
//         }
        

        
        
//         if (result){
//             printf("YES\n");
//         } else {
//             printf("NO\n");
//         }


        


//     }
// }

// // gcc MakeAp.c -o B.o && ./B.o < B.in