#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int round;
    cin >> round;

    while(round--){
        long long input;
        vector<long long> inputs;
        for (int i = 0; i < 3; ++i) {
            cin >> input;
            inputs.push_back(input);
        }
        sort(
            inputs.begin(), 
            inputs.end()
        );

        if ( abs(inputs[0] + inputs[2] - (inputs[1]*2))  % 3 == 0 ) {
            cout << 0 << "\n";
        } else {
            cout << 1 << "\n";
        }         
    }
    return 0;
}