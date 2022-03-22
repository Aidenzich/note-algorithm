#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x;
    cin >> x;
    long long nodes;    
    long long  ans;    
    
    ans =  6 * ( pow( 2 , (long long)(pow( 2, (x + 1)) - 4) % 1000000007 )) ;
    ans =  ans % 1000000007;

    // cout << ans % 1000000007;
    cout << ans;    
    
    return 0;
}