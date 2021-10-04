#include <iostream>
#include <vector>
using namespace std;


// in this case RangeSum = PrefixSum(j) - PrefixSum(i-1)
// PrefixSum(i-1) must not include the current i value

int main(){
    int n;
    cin >> n;
    vector<long long> v(n+1);
    for (int i=1; i<=n; ++i){ // v[0] must be 0
        cin >> v[i];
    }

    // calculate prefix sum:
    // prefix sum : ps[i] = v[0] + ... + v[i]
    vector<long long> ps(n+1);
    
    ps[0]=0;
    for (int i=1; i<=n; ++i){
        ps[i] = ps[i-1] + v[i];
    }
    
    long long ans{v[1]};
    for (int i=0; i<=n; ++i){
        for (int j=i; j<=n; ++j){            
            ans = max(ans,  ps[j] - ps[i-1]);            
        }
    }
}