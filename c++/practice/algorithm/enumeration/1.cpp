#include <iostream>
#include <vector>
using namespace std;

// Question
// 1 <= i <= j <= n


int main(){
    int n;
    cin >> n;
    std::vector<long long> v(n); // This vector is use for save input
    
    for(auto&  x:v){
        cin >> x;
    }

    // int must be at least 16 bits
    // long must be at least 32 bits
    // long long must be at least 64 bits
    long long ans{v[0]}; // 確保並非空區間

    for (int i{0}; i < n; ++i)
        for (int j{i}; j < n; ++j) {
            long long sum{0};
            for (int k{i}; k <= j; ++k) sum += v[k];
            ans = max(ans, sum);
        }

    cout << ans;
}