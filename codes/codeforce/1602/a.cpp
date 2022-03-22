// https://codeforces.com/contest/1581/problem/A
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int round;     
    string input;
    cin >> round;

    for (int t =0; t < round; t++){        
        cin >> input;
        int n = input.length();
        vector<char> c_arr(n);
        vector<char> o_arr(n);
        
        int i = 0;
        for (char & c : input){
            c_arr[i] = c;
            o_arr[i] = c;
            i++;
        }

        sort(c_arr.begin(), c_arr.end());
        char sm;
        for (char c: c_arr){
            cout << c << " ";
            sm = c;
            break;
        }
        
        int count = 0;
        for (char c: o_arr){
            if (c==sm && count == 0){
                // cout << "true" << count << "\n";
                count++;
                continue;
            }
            
            cout << c;
            
        }
        cout << "\n";
    }
        
    return 0;
}

