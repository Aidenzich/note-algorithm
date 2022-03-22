#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <math.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    long long u = 0, v = 0;    
    cin >> t;
    while (t--){
        cin >> u >> v;
        long long y = 0;
        double x = 0;
        bool found = false;
        while (!found){
            if (x == 0 && y==0 ){
                y = v;
                continue;
            }
            

            x = - y * (pow(u, 2) / pow(v, 2));
            if (x == (long)x){
                cout << x << " "<< y << "\n";
                break;
            }   
            
            x = y * (pow(u, 2) / pow(v, 2));
            
            if (x == (long) x ){
                y = -y;
                cout << x << " "<< y << "\n";
                break;
            }

            y = y*y;

            
        }        
    }                
    return 0;
}