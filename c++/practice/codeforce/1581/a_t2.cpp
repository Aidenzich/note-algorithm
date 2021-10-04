// when submit use this
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool arrsame(int* arr, int len, int num) {
	int i;
	for (i = 0; i < len; i++)
		if (arr[i] == num)
			break;
	return i != len;
}
bool next_perm(int* perm, const int k, const int n) {
	int i = k - 1;
	do{
        perm[i]++;
    }		
	while (arrsame(perm, i, perm[i]) || (perm[i] >= n && i--));
	if (perm[0] >= n)
		return 0;
	for (int num = 0, seat = i + 1; seat < k; num++)
		if (!arrsame(perm, i + 1, num))
			perm[seat++] = num;
	return 1;
}

int main(){
    int n;
    cin >> n;

    std::vector<int> v(n); // This vector is use for save input
    
    for(auto&  x:v){
        cin >> x;
    }

    for (int x:v){        
        int len = 2*x;
        int result = 0;
        int* perm = new int[len];
        for (int i = 0; i < len; i++){
            perm[i] = i;
        }            
        do{
            int count = 0;
            for (int i = 0; i < len; ++i){
                // cout << perm[i] + 1;
                if (i>0){
                    if (perm[i] > perm[i-1]){
                        count++;
                        if (count >= x){
                            result+=1;
                            break;
                        }
                    }                    
                }
            }
        }
        while (next_perm(perm, len, len));
        cout <<result<<"\n";
        delete[] perm;
    }
    return 0;
}