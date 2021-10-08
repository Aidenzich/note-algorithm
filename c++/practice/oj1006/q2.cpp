#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iterator>  
#include <numeric>
using namespace std;
long long highestPowerof2(long long n)
{
    long long res = 0;
    for (long long i=n; i>=1; i--)
    {        
        if ((i & (i-1)) == 0)
        {
            res = i;
            break;
        }
    }
    return res;
}

int main() {
    // 1073741824 1048576
    long long n, k, tmp, sum, on;
    int tidx;
    cin >> n;
    cin >> k;
    on = n;
    std::vector<long long> v(k);
    
    // cout << highestPowerof2(n);
    // return 0;
    if (n%1024 == 0 && k%1024 == 0){
        for(long long i = 0; i < k; i++){
            if (i != (k-1)){
                cout<< n/k << " ";
            }else{
                cout<< n/k << "";
            }
        }
        return 0;
    }



    if (k > n){
        cout << "NO";
        return 0;
    }
    tmp = highestPowerof2(n);

    for (int i =0; i<k; i++){
        tmp = highestPowerof2(n);
        
        if (tmp != 0){
            v[i] = tmp;
            n -= v[i];
        }
        else
        {
            tidx = distance( v.begin(), max_element(v.begin(), v.end()) );            
            if (v[tidx] < 2 ){
                cout << "NO";
                return 0;
            }
            tmp = v[tidx]/2;
            v[i] = tmp;
            v[tidx] = tmp;
        }
    }

    sum = std::accumulate(v.begin(), v.end(), 0);
    if (sum == on){
        cout << "YES" << "\n";
        for(long long i = 0; i < k; i++){
            if (i != (k-1)){
                cout<< v[i] << " ";
            }else{
                cout<< v[i] << "";
            }
        }
    }else{
        cout << "NO" << "\n";
    }        
}