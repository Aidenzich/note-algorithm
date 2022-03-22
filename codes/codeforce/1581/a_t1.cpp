// when submit use this
// #include <bits/stdc++.h> 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Question
struct prem {
	int len;
	vector<int> used, position;
	function<void(vector<int>1&)> action;
	prem(int l = 0, function<void(vector<int>&)> a = [](vector<int>& position) {}) : len(l), used(l, -1), position(l), action(a) {}
	void run(int now = -1) {
		if (now == len - 1) {
			action(position);
			return;
		}
		int next = now + 1;
		for (int i = 0; i < len; i++) {
			if (used[i] == -1) {
				used[i] = next;
				position[next] = i+1;
				run(next);
				used[i] = -1;
			}
		}
	}
};

int main(){
    int n;        
    cin >> n;

    std::vector<int> v(n); // This vector is use for save input
    
    for(auto&  x:v){
        cin >> x;
    }

    for (int x:v){
        // ios::sync_with_stdio(false), cin.tie(0);
        int len = 2*x;
        int result = 0;
        
        prem p(len, [&](vector<int>& p) {
            int count = 0;
            for (int i = 0; i < len; i++) {
                // cout << p[i] << " ";
                if (i>0){
                    if (p[i] > p[i-1]){
                        count++;
                    }
                }
            }
            if (count >= x){
                result+=1;
            }
        });        
        p.run();        
        cout <<result <<"\n";
        
    }
    return 0;
}