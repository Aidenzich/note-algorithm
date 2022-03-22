#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <deque>
#include <math.h>
using namespace std;

// Problem https://codeforces.com/contest/1579/problem/E1
int main(){    
    int n;
    cin >> n;        
    for (int i = 0; i < n; i++){
        int t;
        cin >> t;
        std::vector<long long> v(t);
        deque<long long> l;
        for (auto& x:v){
            cin >> x;
        }

        long long tmp = 1e9;
        for (int j{0}; j<t; j++){
            tmp = min(tmp, v[j]);
            if (tmp == v[j]){
                l.push_front(v[j]);
            } else {
                l.push_back(v[j]);
            }

        }
        for (auto &j: l){
            cout << j << " ";
        }
        cout << endl;
    }
}