/**

You are given an integer n. There is an undirected graph with n nodes, numbered from 0 to n - 1. 
You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

Return the number of pairs of different nodes that are unreachable from each other.

Input: n = 7, edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
Output: 14
Explanation: There are 14 pairs of nodes that are unreachable from each other:
[[0,1],[0,3],[0,6],[1,2],[1,3],[1,4],[1,5],[2,3],[2,6],[3,4],[3,5],[3,6],[4,6],[5,6]].
Therefore, we return 14


*/

class Solution {
public:
    typedef long long ll;
    void dfs(int node, unordered_map<int,vector<int>>& m, ll& cnt, vector<int>& vis){
        vis[node] = 1;
        cnt++;
        for(auto& i: m[node]){
            if(vis[i]==0) dfs(i,m,cnt,vis);   
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> m; // making adjacency list
        for(int i=0;i<edges.size();i++){
            m[edges[i][0]].push_back(edges[i][1]);
            m[edges[i][1]].push_back(edges[i][0]);
        }
        ll ans = ((ll)n*(n-1))/2;
        
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){ // as node is not visited, we find the no. of nodes in current component.
                ll cnt = 0;
                dfs(i,m,cnt,vis);
                ans -= (cnt*(cnt-1))/2;
            }
        }
        return ans;
    }
};


/**

Total no. of ways to pick 2 nodes from n nodes = nC2 = n*(n-1)/2;
Here we should not pick 2 nodes from the same component, so we find the number of nodes in each component. 
And subtract the no. of ways to pick 2 nodes from that component.
To find no. of nodes in a component, we can just do a DFS traversal and maintain a cnt to maintain no. of nodes visited in that dfs call




*/
