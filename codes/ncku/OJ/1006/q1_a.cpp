#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

struct cake{
    int d, c;
    bool operator<(const cake &a)const{
        return (long long)d * a.c > (long long)a.d * c;
    }
} a[200000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n, k;
    double ans = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i].d >> a[i].c;
    sort(a, a + n);
    for(int i = 0; i < n && (k > 0 || a[i].c == 0); k -= a[i].c, i++)
        if(k >= a[i].c || a[i].c == 0)
            ans += a[i].d;
        else
            ans += a[i].d * (double(k) / a[i].c);
    cout << fixed << setprecision(12) << ans << "\n";
}