#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
class node{
    public:
    int start, end;
};

bool cmp(node a, node b){
    return a.end < b.end;
}

int main(){
    int round, x;
    cin >> round;
    for(int i = 0;i < round; ++i){
        cin >> x;
        vector<node> vs;
        node tmp;
        for(int i=0; i< x; ++i){
            cin >> tmp.start >> tmp.end;
            vs.push_back(tmp);
        }
        sort(vs.begin(), vs.end(), cmp);
        int now = -1, answer = 0;
        for(int i=0; i < x; ++i){
            if (vs[i].start >= now){
                answer++;
                now = vs[i].end;
            }
        }
        cout << answer << '\n';
    }
}