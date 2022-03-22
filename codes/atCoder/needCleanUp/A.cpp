#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
int main() {
    
    int n, k, a, m, ans;
        
    cin >> n >> k >> a;
    m = (k % n);
    
    // if (n == 1 || n == 0){
    //     cout << n << "\n";
    //     return 0;
    // }
    
    // if (m == 0){    
    //     ans = a + k;
    // } else {
    //     ans = a + m;
    // }
    
    
    // if (ans > k){
    //     ans = ans % k;
    // }
    // cout << ans - 1 << "\n";
    cout << ((k-1 + a-1) % n) + 1 <<'\n';
                
    return 0;
}