// Flashing Number Mental Arithmetic（フラッシュ暗算）is a competitive game originated from Japanese zhusuan circle. The calculator (a human, that is) will see several numbers rapidly appear and disappear on the screen, after it, he/she have to answer the sum of all appeared numbers in a few seconds. Sounds simple? Try it out at https://www.youtube.com/watch?v=Q7Jd3Mbzup0 !

// Chao from CSIE thinks that, "Yup, its way too easy". So, he designed the rules for a "advanced" version:

// The numbers appear on the monitor might be in Base-6(SEN), Base-8(OCT), Base-10(DEC), or Base-16(HEX).

// Value of every number will be in between 0 and 999,999,999.

// Since the final number might be extremely large, you have to answer in modular 1,000,000,007.

// E.g., if the sum is 1,000,000,010, since that 3 ≡ 1,000,000,010 mod 1,000,000,007, you have to answer "3".

// At the same time, Chao also created some problems, but they are waaaaay too easy for him to solve. Help him design a program that calculates the correct answer.

// ※ All number in this problem description, unless specified, are in Base-10(Decimal) ! ※

// Input
// First line consist of a integer N, represents how many number to sum.

// 1 <= N <= 1,000

// Followed by N lines, each consists of 2 integers, S and K.

// S denotes the base of K.

// S ∈ {6, 8, 10, 16} , 0 <= K <= DEC999,999,999

// If K is Base-6, or Base-10, its written normally.

// If K is Base-8, it will have prefix "0". (e.g. 0123, 0777)

// If K is Base 16, it will have prefix "0x". (e.g. 0x41414141, 0xDEADBEAF)

// Output
// output a integer, that is the sum of all input K, mod 1,000,000,007.

// Limits
// Your program needs to finish task in 2 seconds.

// Your program can only use memory less than 65536 KB.


#include<stdio.h>

int main () {
    unsigned long sum = 0;
    unsigned long K;
    unsigned int times, S;
    
    char ch;
    scanf("%d", &times);
    for (int i=0; i < times; i++){
        unsigned long  tmp = 0;
        scanf("%d", &S);
        
    	switch (S){
            case 6: //senary                                
                do {
                    ch = getchar();
                    if ('0' <= ch && ch < '6'){
                        tmp = tmp * 6 + ch - '0';
                    }
                }while(ch != '\n' && ch != EOF ); // Exit the loop if we receive EOF ("end of file")

                sum = sum + tmp;
                break;
            
            case 8: //Octal
                scanf("%lo", &K);
                sum = sum + K;
                break;

            case 10: // Decimal
                scanf("%ld", &K);
                sum = sum + K;
                break;

            case 16: // Hexadecimal
                scanf("%lx", &K);
                sum = sum + K;
                break;
        }
        
    }
    sum = sum % 1000000007;
    printf("%ld", sum);
       
    return 0;
}
