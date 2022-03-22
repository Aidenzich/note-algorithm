#include <iostream>
#include <vector>

using namespace std;
// int main(){
//     vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};    
//     int mx = 0;
        
//     for (int i=0; i < height.size(); i++){
//         for (int j=i; j<height.size(); j++){
//             mx = max( (j-i) * min(height[i], height[j]), mx);
//         }
//     }
//     cout<< mx;
//     return mx;
// }


int main(){
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};    
    int mx = 0;
    int i=0; 
    int j=height.size()-1;
    while (i < j){        
        mx = max((j - i) * min(height[i], height[j]), mx);
        if (height[j] > height[i]){
            i++;            
        } else {
            j--;
        }
    }
    cout << mx;
    return mx;
}