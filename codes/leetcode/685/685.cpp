#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> roots(n+1, 0);
        vector<int> parents(n+1, 0);
        vector<int> sizes(n+1, 1);
        
        vector<int> answer1;
        vector<int> answer2;

        for (auto& x: edges){
            int u = x[0];
            int v = x[1];

            // when parents[v] != 0, means v has plural parents
            if (parents[v] != 0) {
                answer1 = {parents[v], v};  // {v's parent 1, v} {2, 1}
                answer2 = x;                // {v's parent 2, v} {3, 1}

                x[0] = x[1] = -1;           // remove the later edge
            }
            parents[v] = u;
        }

        for (auto& x: edges){        
            int u = x[0], v = x[1];

            if (u < 0 || v < 0 ) continue;
            
            // init roots table
            if (!roots[u]) roots[u] = u;
            if (!roots[v]) roots[v] = v;

            int parent_u = find(u, roots);
            int parent_v = find(v, roots);

            // Both u and v are already merged, means the graph is a ring when add the edge x
            if (parent_u == parent_v){
                return answer1.empty() ? x : answer1; // empty means there is no plural parents
            }

            // Union, merge smaller set to large set            
            if (sizes[parent_v] > sizes[parent_u] ){
                swap(parent_u, parent_v);
            }

            roots[parent_v] = roots[parent_u];     // mark roots
            sizes[parent_u] += sizes[parent_v];    // add smaller set size to large set size
        }

        return answer2;
    }
private:
    int find(int i, vector<int>& roots){
        while (roots[i] != i){
            roots[i] = roots[roots[i]];
            i = roots[i];
        }
        return i;
    }
};