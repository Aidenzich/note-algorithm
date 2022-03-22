#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
int main() {
    int n, h, t, o;
        
    cin >> n ;
    h = n / 100;
    t = (n - h*100) / 10;
    o =  (n - h*100 - t*10 );

    // cout << h << "\n" << t << "\n" << o<<'\n';
    cout << 100*h + 10*t + o + 100*t + 10*o + 1*h + 100*o + 10*h + t;


    return 0;
}