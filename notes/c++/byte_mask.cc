// The iostream file contains code that allows a C++ program 
// to display output on the screen and read input from the keyboard.
#include <iostream>
using namespace std;


int main(){
    int x = 27;
    int y;
    // int is 4bytes, which is 2^32 bit
    // (~127) means not 127 -> 
    // 127 in binary is     01111111 
    // ~127 in binary is    10000000
    // &(~127) can be seen as mask
    // 27+127 = 154 is 10011010
    // 10011010 &
    // 10000000 =
    // 10000000
    // which is 128 in int.
    y = (x+127)&(~127);

    cout << y;  // return is 128


    return 0;
}