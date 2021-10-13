// https://codeforces.com/problemset/problem/1593/B
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <list>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    
    long long round;
    long long input;

    string inputStr;
    cin >> round;

    while (round--){
        cin >> input;
        int remove_num = 0, remove_5 = 0, remove_0 = 0; 
        
        bool five = false, find5 = false, find0 = false;

        inputStr = std::to_string(input);
        
        for (int i = 0; i < inputStr.size(); i++){
            int index = (inputStr.size() -1) - i;

            if (inputStr[index] == '0' ){
                if (find0 == true) break;
                remove_5 ++;
                find0 = true;
                continue;
            }
            if (inputStr[index] == '5' ){
                if (find0) break;
                if (find5){
                    remove_5++;
                } else {
                    find5 = true;
                }
                remove_0++;
                continue;
            }
            if (inputStr[index] == '2' || inputStr[index] == '7'){
                if (find5){
                    five = true;
                    break;
                }
            }
            remove_5++;
            remove_0++;
        }

        if (five){ 
            cout << remove_5 << "\n";
        }else{
            cout << remove_0 << "\n";
        }
    }
        
    return 0;
}