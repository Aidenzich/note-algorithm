#include <iostream>
#include <vector>
using namespace std;
 
class Solution {
public:
    string longestPalindrome(string s) {
        int max{1}; // max is the Longest Palindrome String's length
        pair<int, int> ans{0, 0};

        for (int i{0}; i < s.length(); ++i) {            
            for (int l{i - 1}, r{i + 1}; l >= 0 && r < s.length(); --l, ++r) {
                if (s[l] != s[r]) break;
                if (r - l + 1 > max) max = r - l + 1, ans = {l, r}; 
            }            
            for (int l{i - 1}, r{i}; l >= 0 && r < s.length(); --l, ++r) {
                if (s[l] != s[r]) break;
                if (r - l + 1 > max) max = r - l + 1, ans = {l, r};
            }
        }
        string ans_str;
        for (int i = get<0>(ans); i <= get<1>(ans); ++i)
            ans_str += s[i];
        cout << ans_str;
        return ans_str;
    }        
};