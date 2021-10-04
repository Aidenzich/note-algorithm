#include <iostream>
#include <vector>
using namespace std;
 
// how to find 

// This function prints the
// longest palindrome substring
// It also returns the length
// of the longest palindrome
int main()
{
    string s = "cbbd";
    int max{1}; // max is the Longest Palindrome String's length
    pair<int, int> ans{0, 0};
    
    for (int i{0}; i < s.length(); ++i) {
        // Start with 3 length (block)
        // e.g.
        // babad
        // |bab|ad
        //   ^  -> i=1, founded
        // in this place, u can think that l is start index, r is end index
        // use --l and ++r tofind S_2 = aS_1a or not
        for (int l{i - 1}, r{i + 1}; l >= 0 && r < s.length(); --l, ++r) {
            if (s[l] != s[r]) break; // which means the substring in [l, r] is not Palindrome
            if (r - l + 1 > max) {
                max = r - l + 1, ans = {l, r}; 
            }
        }

        // Start with 2 length -> which means input string is not start at the char in Palindrome.
        // e.g.
        // cbbd
        // \cb\bd
        //   ^      -> i=1, not found
        // c\bb\d
        //   ^      -> i=2, founded
        for (int l{i - 1}, r{i}; l >= 0 && r < s.length(); --l, ++r) {
            if (s[l] != s[r]) break;
            if (r - l + 1 > max){
                max = r - l + 1, ans = {l, r};
                cout << "max" << "\n";
            }
        }
    }
}