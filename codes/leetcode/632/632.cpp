#include <iostream>
#include <vector>
#include <queue>
#include <climits>

// 632. Smallest Range Covering Elements from K Lists
using namespace std;
vector<int> smallestRange(vector<vector<int>>& nums) {
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
    int mx=INT_MIN;
    int cans=INT_MAX;
    int left=INT_MIN, right=INT_MAX;

    for (int i=0;i<nums.size();i++){
        mx=max(mx,nums[i][0]);
        q.push({nums[i][0],{i,0}});
    }

    while(!q.empty())
    {
        auto x=q.top();
        q.pop();
        int na=mx-x.first+1;
        if(cans>na)
        {
            cans=na;
            left=x.first;
            right=mx;
        }
        if(x.second.second>=nums[x.second.first].size()-1)
            break;
        q.push({nums[x.second.first][x.second.second+1],{x.second.first,x.second.second+1}});
        mx=max(mx,nums[x.second.first][x.second.second+1]);
    }
    return {left,right};
}

int main(){
    int n, x, tempNum;
    cin >> n;

    vector<vector<int> > vectorSpace;
    
    for(int i = 0;i < n;i ++){
        cin >> x;
        vector<int> temp;
        for(int j = 0;j < x;j ++){
            cin >> tempNum;
            temp.push_back(tempNum);
        }
        vectorSpace.push_back(temp);
    }
    vector<int> ans = smallestRange(vectorSpace);
    cout << ans[0] << " " << ans[1];
}


