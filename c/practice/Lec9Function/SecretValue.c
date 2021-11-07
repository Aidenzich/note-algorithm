// David is trying to calculate the "secret value" of numbers.
// The secret value of integer N is calculated as:

// If N is a one-digit integer, the secret value is itself.

// Split the number into upper part and lower part.
// If there are an odd number of digits, the middle digit belongs to the lower part.

// The integer 121088 gets divided into 121 and 088.

// The integer 12345 gets divided into 12 and 345

// Both the upper part and lower part are guaranteed NOT to be 0.

// Find the two parts' greatest common divisor(GCD). The result is called k.

// Sum up N itself and the secret value of k.

// David hate huge numbers, so you MUST answer in modular 10007.
// Your work will be judged by running the loader section, so please implement the functions provided!

// Example (Sample Input 1)
// For N = 2424, we can split it into 24 and 24, whose GCD is also 24, so the result k of 2424 is 24.
// Now we need to know the secret number of 24 to sum up with N.

// For N= 24, we can split it into 2 and 4, whose GCD is 2, so the result k of 24 is 2.

// Since 2 has only one digit, the secret value of 2 is 2

// Hence, we can get the secret value of 2424 = 2424 + secret value of 24 = 2424 + 24 + secret value of 2 = 2450

// Input
// A single integer N

// 1 ≦ N ≦ 2,147,483,647

// Output
// The secret value of N, mod 10007

// Limits
// Your program needs to finish task in 1 second.

// Your program can only use memory less than 5000 KB.

#include <stdio.h>
#include <string.h>
#include <math.h>


int gcd(int a, int b){
	if (b){
        while((a %= b) && (b %= a));
    }            
	return a + b;
}
// https://stackoverflow.com/questions/2620146/how-do-i-return-multiple-values-from-a-function-in-c
void split_num(int n, long* a_left, long* a_right){
    int cn = n;
    int count = 0;
    long left = 0, right = 0;

    while (cn != 0){
        cn /= 10;
        ++count;
    }

    long numArr[1000] = {0};
    
    int i = 0;
    while(n > 0) {
        int mod = n % 10;       //split last digit from number
        numArr[(count - i - 1)] = mod;        
        n = n / 10;             //divide num by 10. num /= 10 also a valid one 
        i++;        
    }

    
    for (int j = 0; j < count; j++){
        if (count % 2 == 0){
            if ( (count - j - 1 ) >= count/2){                        
                left += numArr[j] * pow(10, (count/2 - j - 1));
            } else {            
                right += numArr[j] * pow(10, (count - j - 1));
            }
        } else {
            // If there are an odd number of digits, the middle digit belongs to the lower part.
            if ( (count - j - 2) >= count/2){
                left += numArr[j] * pow(10, (count/2 - j - 1));
            } else {            
                right += numArr[j] * pow(10, (count - j - 1));
            }
        }
        
    }
    // assert(a_left);
    // assert(a_right);
    *a_left = left;
    *a_right = right;
}


int getSecret(int n ){
    long left = 0;
    long right = 0;
    long sum = 0;
    long g = 0;
    sum += n;
    
    while ( n / 10 >= 1){
        split_num(n, &left, &right);
        g = gcd(left, right);
        sum += g;
        n = g;
        // printf("%d\n", n);
    }
        
    return sum % 10007;
}



int main(){
    long n = 0;
    scanf("%ld", &n);
	printf("%d", getSecret(n));    
    
}