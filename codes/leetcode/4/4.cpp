#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<int> nums1 = { 1,3 };
    vector<int> nums2 = {2};
    nums1.insert(nums1.end(), nums2.begin(), nums2.end());    
    sort(nums1.begin(), nums1.end());
    // for (int i: nums1){
    //     cout << i << "\n";
    // }
    int idx = 0;
    int idx1 = 0;
    int idx2 = 0;
    double ans = 0;
    if (nums1.size() == 1){
        ans = nums1[0];
    }
    else if (nums1.size()%2 == 0)
    {
        idx = nums1.size() / 2;                
        ans = (1.0 * nums1[idx-1] + 1.0* nums1[idx])/2;
    } else {
        idx = (nums1.size() + 1) / 2;
        ans = nums1[idx-1];
    }
    cout << ans << endl;
    return 0; 
}