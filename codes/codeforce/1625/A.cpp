#include <math.h>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;
int calcul(const vector<int> &intArray, int len)
{
    int size = intArray.size();
    int m = size / 2;
    int answer = 0;

    int cntArr[len];

    fill(cntArr, cntArr + len, 0);

    for (int x : intArray) {
        for (int i = 0; i < len; ++i) {
            cntArr[i] += (x >> i) & 0x1;
        }
    }

    
    for (int i = 0; i < len; ++i) {
        answer |= (cntArr[i] <= m ? 0 : 1) << i;
    }

    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int round;

    cin >> round;

    while(round--){
        int i1, i2;
        cin >> i1;
        cin >> i2;

        vector <int> intArray;

        for (int i = 0; i < i1; ++i) {
            int i3;
            cin >> i3;
            intArray.push_back(i3);
        }

        cout << calcul(intArray, i2) << '\n';
    }

    return 0;
}
