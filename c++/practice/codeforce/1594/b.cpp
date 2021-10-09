// https://codeforces.com/problemset/problem/1594/B
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    
    int round;
    long long n, k, power, ans;
    long long inf = 1e9+7;
    priority_queue<int> pq;
            
    cin >> round;

    while (round--){        
        cin >> n >> k;
        power = 1;
        ans = 0;
        for (long long i = 0; i < 31; i++){
            cout << i << " i<<i: " << (1<<i) << "\n";
            if (k & (1<<i)){
                ans = (ans + power) % inf;
                // cout << ans << "\n";
            }            
            power *= n;     // this will generate n^0 ~ n^31
            power %= inf;
        }
        cout << ans << "\n";
    }
        
    return 0;
}