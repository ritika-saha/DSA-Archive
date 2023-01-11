/**
Given an undirected tree consisting of n vertices numbered from 0 to n-1, which has some apples in their vertices. You spend 1 second to walk over one edge of the tree.
Return the minimum time in seconds you have to spend to collect all apples in the tree, starting at vertex 0 and coming back to this vertex.

The edges of the undirected tree are given in the array edges, where edges[i] = [ai, bi] means that exists an edge connecting the vertices ai and bi. Additionally, 
there is a boolean array hasApple, where hasApple[i] = true means that vertex i has an apple; otherwise, it does not have any apple.

 

Example 1:


Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,true,true,false]
Output: 8 
Explanation: The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows.  
*/

class Solution {
public:
    int dfs(vector<int> adj[], vector<bool> &hasApple, int node, int parent) {
        int distance = 0; //total time to collect all apples from the root.
        for(auto i:adj[node]) {
            if(i!=parent) {
                int temp=dfs(adj, hasApple, i, node); //store whether root's child has an apple or not.
                if(hasApple[i]) { //if root's child has an apple, then we will add 2 to the time, as you have to come back.
                    distance+=(2+temp);
                    hasApple[node]=true; //hasApple[node] has been changed to true because its child has an apple, so for sure you will be returning back.
                }
            } 
        }
        return distance;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> adj[n];
      //creating adjacency list
        for(int i=0;i<edges.size();i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        return dfs(adj, hasApple, 0, 0);
    }
};
