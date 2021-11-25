#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
int main() {
    int t;
    int s, wrong=0, count=0;
    vector<int> ans;
    for (int a = 1; a< 200; a++){
        for (int b=1; b<200; b++){
            ans.push_back(4*a*b + 3*a + 3*b);            
        }
    }
    cin >> t;
    while (t--){        
        cin >> s;
        if (!std::count(ans.begin(), ans.end(), s)){
            wrong++;
        };
    }
    cout << wrong;
        
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
    
                
    return 0;
}