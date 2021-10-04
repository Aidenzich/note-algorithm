#include <iostream>
#include <vector>
using namespace std;

long long maxsum(const vector<int>& v, int l, int r) {
    cout << v[l] << " " << v[r] <<endl;

    if (r - l == 1) {
        return v[l];        
    }
    
    int m{(l + r) / 2};
    
    long long sum{0}, mx{v[m - 1]};
    

    // 先計算從中間往左邊的最大連續和
    for (int i{m - 1}; i >= l; --i) {
        mx = max(mx, sum += v[i]);        
    }

    // 再加上中間往右邊的最大連續和
    sum = mx, mx = sum + v[m];
    
    for (int i{m}; i < r; ++i){
        mx = max(mx, sum += v[i]);
    } 
    
    return max(mx, max(maxsum(v, l, m), maxsum(v, m, r)));
}
int main(){
    vector<int> v{1, 2, 3, 4, 5};
    cout<< maxsum(v, 0, 5);
}