#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());        
        sort(nums1.begin(), nums1.end());        
        int idx = 0;
        if (nums1.size() == 1){
            return nums1[0];
        }
        else if (nums1.size()%2 == 0)
        {
            idx = nums1.size() / 2;                
            return (1.0 * nums1[idx-1] + 1.0* nums1[idx])/2;
        } else {
            idx = (nums1.size()+1) / 2;
            return nums1[idx-1];
        }        
    }
};