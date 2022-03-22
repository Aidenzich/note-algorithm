#include <iostream>
using namespace std;

int main() {
    int n, x, mx = 0;
    cout<<"Hello World, C++ \n";
    cout<<"Input Run time: \n";
    cin >> n;
    for(int i = 0; i < n; i++){
        cout<<"New Input: \n";
        cin >> x;
        if(x > mx) mx = x;
    }
    cout << mx << "\n";
}

