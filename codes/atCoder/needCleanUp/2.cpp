#include <iostream>
using namespace std;

int main() {
    int round;
    cin >> round;
    int input[round];
    for (int i =0; i < round; i++){
        cin >> input[i];
        // cin >> input[i];
    }

    int temp = input[0] ;
    for (int i =0; i< round; i++){
        if (input[i] >= input[i+1]) break; 
        temp = input[i+1];
        
    }
    cout << temp;
}