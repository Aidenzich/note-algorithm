#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
 
    int ltimes = 0;
 
    cin >> ltimes;
 
    long long  av_weapons, en_health;
 
    for (int t = 0; t < ltimes; t++) {
 
        cin >> av_weapons >> en_health;
 
        vector<long long > weapon_damages(av_weapons, 0);
 
        long long  temp;
 
        for (int i = 0; i < av_weapons; i++) {
            cin >> temp;
            weapon_damages[i] = temp;
        }
 
        sort(weapon_damages.begin(), weapon_damages.end(), [](long long a, long long b) {return a > b; });
 
 
        if (en_health <= weapon_damages[0]) {
            cout << 1 << "\n";
            continue;
        };
 
        if (en_health <= weapon_damages[0] + weapon_damages[1]) {
            cout << 2 << "\n";
            continue;
        };
 
        long long  ans =  ( en_health / (weapon_damages[0]+ weapon_damages[1]))*2  ;
 
        long long res = en_health % (weapon_damages[0] + weapon_damages[1]);
 
        if (res > 0) {
            res -= weapon_damages[0];
            ans++;
        }
 
        if (res > 0) {
            res -= weapon_damages[1];
            ans++;
        }
 
        cout << ans << "\n";
    }
}