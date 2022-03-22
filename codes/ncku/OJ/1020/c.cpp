#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iterator>  
#include <numeric>
#include <tuple>
using namespace std;
 using DT = long long;

DT sol(DT n, DT k){
vector< pair<DT, DT> > h;
    
    // return 999;2
    for(int i=0; i<n; ++i){
        DT a,b;
        cin >>a;
        cin >>b;
        h.push_back(make_pair(a,b));    
    }

    while(true){
        sort(h.begin(), h.end());
        for(int i=0;i<h.size(); ++i);
        auto dis = h[0].second - h[0].first;
        auto b = h[0].second;
        int f=1;
        while(h[f++].first == h[0].first);
        --f;
        
        if(dis * f > k){
            auto o = k / f;
            return h[0].first + o;
        }
        k -= dis *f ;
        for(int i=0; i<f; ++i){
            h[i] = make_pair(b+1, h[i].second);
        }

        while(h[0].second < h[0].first){
            h.erase(h.begin());
        }

    }
}

int main() {
    int n,k;
    cin >> n;
    cin >> k;
    // cout << "123123\n";
    cout << sol(n,k)<<'\n';

}