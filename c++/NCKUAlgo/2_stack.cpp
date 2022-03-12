#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <iterator>
#include <algorithm>
using namespace std;

int N;
vector<set<int> > V_SPACE;
map<set<int>, int> POSITION_MAP;
stack<int> STACK;
set<int> POP1, POP2, RESULT;


int setAndGetPosition(set<int> newSet){
    if (!POSITION_MAP.count(newSet)){
        V_SPACE.push_back(newSet);
        POSITION_MAP[newSet] = V_SPACE.size() - 1;
    }

    return POSITION_MAP[newSet];
}

void popOut(){
    POP1 = V_SPACE[STACK.top()];
    STACK.pop();

    POP2 = V_SPACE[STACK.top()];
    STACK.pop();
}

void unionSet(){
    popOut();
    set_union(
        POP1.begin(), POP1.end(),
        POP2.begin(), POP2.end(),
        inserter(RESULT, RESULT.begin())
    );
    STACK.push(setAndGetPosition(RESULT));
}

void intersectSet(){
    popOut();
    set_intersection(
        POP1.begin(), POP1.end(),
        POP2.begin(), POP2.end(),
        inserter(RESULT, RESULT.begin())
    );
    STACK.push(setAndGetPosition(RESULT));
}

void addSet(){
    popOut();
    POP2.insert(POSITION_MAP[POP1]);
    STACK.push(setAndGetPosition(POP2));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string STR;

    cin >> N;
    while (N--){
        cin >> STR;
        if (STR[0]=='P')
            STACK.push(setAndGetPosition(set<int>()));
        if (STR[0]=='D')
            STACK.push(STACK.top());
        if (STR[0]=='U')
            unionSet();
        if (STR[0]=='I')
            intersectSet();
        if (STR[0]=='A')
            addSet();

        cout << V_SPACE[STACK.top()].size() << "\n";
    }

    return 0;
}