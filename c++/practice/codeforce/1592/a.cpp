// https://codeforces.com/contest/1581/problem/A
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int round;

    long long w_num = 0;    
    long long health = 0;
    cin >> round;
    
    for (int t=0; t<round; t++){                
        cin >> w_num >> health;

        std::vector<long long> v(w_num);
        for(auto& d:v){
            cin >> d;
        }

        long long ans = 0;

        // long long max1 = *max_element(std::begin(v), std::end(v));
        // v.erase(std::remove(v.begin(), v.end(), max1), v.end());
        // long long max2 = *max_element(std::begin(v), std::end(v));
        sort(v.begin(), v.end(), [](long long a, long long b) {return a > b; });
        long long max1 = v[0];
        long long max2 = v[1];
        
        long long total = max1 + max2;
        
        if (health >= (total)){
            ans = (health/total)*2;
            health = health%(total);
        }

        if (health > 0) {
            health = health- max1;
            ans++;
        }

        if (health > 0) {
            health = health - max2;
            ans++;
        }

        cout << ans << endl;
    }
        
    
    return 0;
}