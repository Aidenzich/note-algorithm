#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int round;
    cin >> round;
    while(round--){
        long long zeros = 0, ones = 0;        
        long long len = 0;
        string input;

        cin >> len >> input;
        vector<long long> tmp;
        // loop inputs
        for (const auto &item: input) {
            if (item=='0') {
                zeros++;
            }
            else {
                ones++;
            }
        }
         
        for (int i = 0; i < zeros; ++i) {
            if (input[i]!='0') tmp.push_back(i+1);
        }
        for (int i = zeros; i < len; ++i) {
            if (input[i]!='1') tmp.push_back(i+1);
        }


        if(tmp.size()==0){
            cout << "0" << "\n";
            continue;
        } else {
            cout << "1" <<"\n";
        }
        
        cout << tmp.size();
        for (const auto &item: tmp) {
            cout << " " << item;
        }
        cout <<"\n";
    }
    return 0;
}