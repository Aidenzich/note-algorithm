// https://codeforces.com/problemset/problem/1593/A
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    
    long long round;
    
    long long diff = 0;
    
    
    cin >> round;

    while (round--){
        vector<long long> v(3);
        vector<long long> diffv(3);
        for(auto&  x:v){
            cin >> x;
        }      
        long long max = *max_element(std::begin(v), std::end(v));
        if (v[0] == v[1] && v[1] == v[2] && v[2]== v[0]){
            cout << "1 1 1" << "\n";
            continue;
        }
        int repeat_max = 0;
        int count = 0;
        for (auto x:v){
            
            diff = max - x;
            if (diff != 0){
                diff++;
            }else {
                repeat_max++;
            }
            diffv[count] = diff;
            count ++;
        }
        // cout << "repeat_amx" << repeat_max << "\n";
        for (auto x:diffv){
            
            if (repeat_max > 1 && x == 0){
                cout << x + 1 << " ";
            } else {
                cout << x << " ";
            }
        }

        cout << "\n";
    }
        
    return 0;
}