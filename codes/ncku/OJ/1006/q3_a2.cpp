#include <iostream>
#include <array>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string s;
    cin >> N >> s;

    array<long long, 3> cnt{};
    for (int i{0}; i < N; ++i) {
        if (s[i] == 'B')
            ++cnt[0];
        else if (s[i] == 'N')
            cnt[1] += cnt[0];
        else  // s[i] == 'T'
            cnt[2] += cnt[1];
    }

    cout << cnt[2] << '\n';

    return 0;
}