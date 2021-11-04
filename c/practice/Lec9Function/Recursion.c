// In Henry’s dream, there are 10000 treasure boxes. A mysterious sound says: past paper of PD1 is in the nth treasure box.

// Each treasure box has its own passcode. The rule of the passcode is as following:

// The passcode of the 1st treasure box is 1
// For other boxes, if n is an even number, the passcode is the same as the(n/2)th treasure box.
// If n is an odd number, the passcode is the sum of the passcode of (n + 1)th treasure box and that of (n - 1)th treasure box.

// Please help Henry to find the passcode.

// After Henry has found the passcode and opened the treasure box, there is a letter:
// Here are all of the past paper, but the questions in this midterm are all newly set by the TAs. XD


#include <stdio.h>

int recursion( int n){
    if (n % 2==0){
        return recursion(n/2);
    } else {        
        return (n==1) ? 1 : recursion(n-1) + recursion(n+1);
    }

}

int main(){
    int ans, input;
    scanf("%d", &input);
    ans = recursion(input);
    printf("%d", ans);
}