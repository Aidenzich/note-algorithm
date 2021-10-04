
https://codeforces.com/contest/1578/problem/E
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long n;
    long k = 0, cut = 0;

    cin >> n;
    
    for (int i=0; i<n; i++){
        cin >> k >> cut;
        
        long long tmp = 0, remain = 0, ans = 0;
        
        for (int j=0; j<k; j++){
            tmp = pow(2, j);
            tmp = tmp + remain;
            
            if (tmp < cut){
                remain = 0;
                ans++;
            } else {
                ans += tmp / cut;            
                remain = tmp % cut;
            }
        }

        if (remain != 0) ans++; // notice this

        cout << ans << endl;
    }
        
    
    return 0;
}