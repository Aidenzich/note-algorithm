#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void combination(vector<long> arr, long data[],
                    long start, long end,
                    long index, long r);
 

void prlong(vector<long> arr, long n, long r)
{
    long data[r];
    combination(arr, data, 0, n-1, 0, r);
}
 
void combination(vector<long> arr, long data[], long start, long end, long index, long r)
{    
    if (index == r)
    {
        for (long j = 0; j < r; j++){
            if (j == r-1){
                cout << data[j];
            } else {
                cout << data[j] << " ";
            }
        }
            
        cout << "\n";
        return;
    }
 
    for (long i = start; i <= end && end - i + 1 >= r - index; i++)
    {
        data[index] = arr[i];
        combination(arr, data, i+1, end, index+1, r);
    }
}

int main()
{        

    vector<long> arr;
    bool getFirst = false;
    long k;
    long temp;
    cin >> k;
    while (cin>> temp){        
        arr.push_back(temp);        
    }
    
    
    sort(arr.begin(), arr.end());
    arr.erase(
        unique(
            arr.begin(), arr.end()
        ), arr.end()
    );
    
    long r = 6;
    long n = arr.size();
    prlong(arr, n, r);


}
