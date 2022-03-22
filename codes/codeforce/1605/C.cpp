#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
int main() {
    int round, len;
    int a, b, c;
    int left_a = -1;
    int right_a = -1;
    string input;
    cin >> round;

    while(round--){
        cin >> len;
        cin >> input;
        left_a = -1;
        // for (int i = 0; i < len; ++i) {
        //     if (input[i] == 'a' ) a++;
        //     if (input[i] == 'b' ) b++;
        //     if (input[i] == 'c' ) c++;
        // }

        for (int i=0; i<len; ++i){
            if (input[i] == 'a'){
                if (left_a == -1){
                    left_a = i;
                }
                right_a = i;
            }
        }

        string tmp = input.substr(left_a, right_a+1);
        cout<< tmp << "\n";
        for (int i=0; i< tmp.length(); ++i){
            if (input[i] == 'a' ) a++;
            if (input[i] == 'b' ) b++;
            if (input[i] == 'c' ) c++;
        }
        if (tmp.length() << 3){
            
        }


        if (tmp.length() >= 2 && a > b && a > c){
            cout << tmp.length() << "\n";
            continue;
        }
        if (a <= b && a <= c){
            cout << "-1\n";
        }


        // cout << len << " " << input << "\n";
        // cout << a << " " << b << " " << c <<"\n";
    }
    return 0;
}
