#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
class Solution {
public:
    int hammingDistance(int x, int y) {
        int c = 0;
        int t = 31;
        while(t--){
            if (((1<<t) & x) != ((1<<t) & y)){
                c++;
            }
        }
        return c;
    }
};∆