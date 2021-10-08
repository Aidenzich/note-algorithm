#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n, k, a[64] = {}, cnt = 0;
    bool flag = 0;
    cin >> n >> k;
    for(long long i = 0, tmp = 1; i < 64; tmp <<= 1, i++)
        if(tmp & n)
            a[i] = 1, cnt++;
    if(cnt > k || n < k)
        return cout << "NO\n", 0;
    for(int i = 63; i > 0; i--)
        if(cnt < k){
            int tmp = min(k - cnt, a[i]);
            a[i] -= tmp;
            a[i - 1] += tmp * 2;
            cnt += tmp;
        }
    cout << "YES\n";
    for(long long i = 0, tmp = 1; i < 64; tmp <<= 1, i++)
        for(int j = 0; j < a[i]; j++){
            if(flag)
                cout << " ";
            else
                flag = 1;
            cout << tmp;
        }
    cout << "\n";
}