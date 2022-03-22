#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
int main(){
    int N, ans;
    cin >> N;
    for (int a=1; a <= N; a++){
        for (int b=1; a <= b && b<= N; b++){
            for (int c=1; b <=c && c<=N; c++){
                cout << "a:" << a << " b:" << b << " c:" << c << "\n";
                // if (b < a || c < a || b < c){
                //     continue;
                // }
                // if (a*b*c > N){
                //     continue;
                // }else {
                //     ans++;
                // }
            }
        }
    }
    // cout << ans;

    return 0;
}