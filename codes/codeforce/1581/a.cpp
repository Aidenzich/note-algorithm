#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Problem https://codeforces.com/problemset/problem/1581/A
int main(){
    int n;
    cin >> n;
    
    std::vector<int> v(n);  // must be int
    
    for(auto&  x:v){
        cin >> x;
    }

    for (int x:v){
        long long ans = 1;
        int len = 2*x;
        
        for (int i = 0; i<=len; i++){        
            if (i > 2){
                ans = (ans * i) % 1000000007;
            }
        }
        cout<< ans << endl;
    }

    return 0;
}