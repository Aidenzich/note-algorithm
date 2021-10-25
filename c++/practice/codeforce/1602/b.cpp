// https://codeforces.com/contest/1602/problem/B
// Hint: It can be shown that after at most 𝑛 steps of transformation, array 𝑎 becomes repetitive. There is even a better lower bound: it can be shown that after at most log(𝑛) steps 𝑎 becomes repetitive, so we use either of these two facts to simulate the process and answer the queries.
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int round;
    cin >> round;
    for (int r=0; r < round; r++){
        int length, q;
        cin >> length;
        vector<int> arr(length);        
        for (int j=0; j<length; j++){
            long long tmp;
            cin >> tmp;
            arr[j] = tmp;
        }
        
        cin >> q;
        vector<int> x_arr(q);
        vector<int> k_arr(q);
         
        for (int j=0; j<q; j++){
            long long x, k;
            cin >> x >> k;
            x_arr[j] = x;
            if (k> length){
                k = length+1;
            }
            k_arr[j] = k;
        }

        int max_k = *max_element(k_arr.begin(), k_arr.end());

        vector<vector<int>> trans_results(max_k+1);
        if (max_k > length){
            max_k = length + 1;
        }
        for (int i=0; i <= max_k; i++){
            std::map<int, int> counts;
            vector<int> trans_arr(length);
            if (i == 0){
                trans_results[i] = arr;
                continue;
            }
            
            for (int l=0; l < length; l++){
                counts[trans_results[i-1][l]]++;
            }

            for (int l=0; l<length; l++){
                trans_arr[l] = counts[trans_results[i-1][l]];
            }

            trans_results[i] = trans_arr;            
        }
        
        
        
        for (int i=0; i < q; i++){            
            cout <<trans_results[k_arr[i]][x_arr[i] - 1] <<  "\n";
        }

    }

    return 0;
}
