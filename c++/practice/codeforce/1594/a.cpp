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
    long long  input;
    cin >> round;

    for (int t =0; t < round; t++){
        cin >> input;
        cout << -1 * (input-1) << " " << input << endl;
    }
        
    return 0;
}