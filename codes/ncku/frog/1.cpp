#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    int n, x;
    cin >> n;

    for (int i=0; i<n; ++i){
        int r, l;
        cin >> r >> l;

        int mx = 0, cur_pos = 0;
        // 青蛙會來回跳，因此剛才算的方式，只能找出
        // 不考慮小石頭理論上的最大值，如果將小石頭算進來，
        // 理論上最大值會更小

        for (int j=0; j<r; ++j){
            char size;
            int pos;
            cin >> size >> pos;
            
            mx = max(mx, pos - cur_pos);
            
            cur_pos = pos;
            cout << mx << "\n";

            if (size == 'b'){
                
            } else {

            }
        
        }

        
        mx = max(mx, l - cur_pos);
        cout << mx << "\n";
    }
}