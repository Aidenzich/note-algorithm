#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define Int long long
#define x first
#define y second
using namespace std;


void solve(){
  int n;
  cin >> n;
  string str;
  cin >> str;
  vector<int> A(n);
  for(int i = 0; i < n; i++) {
    if(str[i] == 'A') A[i] = 2;
    if(str[i] == 'T') A[i] = 1;
    if(str[i] == 'C') A[i] = -2;
    if(str[i] == 'G') A[i] = -1;
  }
  int ans = 0;
  for(int c = 1; c <= 2; c++) {
    for(int i = 1; i < n-c; i++) {
      int cnt = 0, j = 1;
      while((i+c-1+j) < n && (i-j) >= 0) {
        int tmp = A[i+c-1+j] + A[i-j];
        if(tmp == 3 || tmp == -3) cnt++;
        j++;
      }
      ans = max(ans, cnt);
    }
  }
  cout << ans << endl;
}
int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int t=1;
  //cin >> t;
  while(t--) solve();
  return 0;
}