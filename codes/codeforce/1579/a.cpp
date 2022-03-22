#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem https://codeforces.com/contest/1579/problem/A
int main(){
    int n;        
    cin >> n;

    std::vector<string> v(n);
    
    for(auto&  x:v){
        cin >> x;
    }
    
    for (string s: v){
        size_t a = std::count(s.begin(), s.end(), 'A');
        size_t b = std::count(s.begin(), s.end(), 'B');
        size_t c = std::count(s.begin(), s.end(), 'C');
        if (a + c == b){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }                
    }
}