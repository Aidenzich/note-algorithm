#include <iostream>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string s;
    cin >> N >> s;

    long long x{0}, y{0}, ans{0};
    for (int i{0}; i < N; ++i)
        if (s[i] == 'T')
            ++y;

    for (int i{0}; i < N; ++i) {
        if (s[i] == 'B') ++x;
        else if (s[i] == 'T') --y;
        else ans += x * y;  // s[i] == 'N'
    }

    cout << ans << '\n';

    return 0;
}
