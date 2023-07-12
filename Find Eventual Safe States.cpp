/**
There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph 
where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal 
node (or another safe node).

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

 

Example 1:

Illustration of graph
Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]
Explanation: The given graph is shown above.
Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.
Example 2:

Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
Output: [4]
Explanation:
Only node 4 is a terminal node, and every path starting at node 4 leads to node 4.
*/

class Solution {
public:
//BASICALLY CYCLE DETECTION IS HAPPENING , TAKING THE NODES WHICH DO NOT END UP IN A CYCLE
    void solve(vector<vector<int>>&graph,vector<int>&vis,int i){
        vis[i]=2;
        for(auto it:graph[i]){
            if(vis[it]==0){
                solve(graph,vis,it);
            }
            if(vis[it]==2)
            return;
        }
        vis[i]=1;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,0);
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(vis[i]==0)
            solve(graph,vis,i);
        }
        for(int i=0;i<n;i++)
        {
            if(vis[i]==1)
            ans.push_back(i);
        }
        return ans;
        

    }
};

/**
Iterate for all nodes and call the solve function for those nodes which have not been visited yet.
Mark the current node as vis[i]=2 and call the solve function for all it's unvisited neighbours.
Now, check if any of its neighbour have vis[neigbour]==2, it simply tells us that the current path that we have traced is a cycle and we have revisited the already 
visited node again in the same path. Therefore, we have detected a cycle and all the nodes coming in this cycle have been marked as vis[node]=2, return the solve functon.
If we don't revisit to any of these nodes again and reach at a terminal node from which we can't iterate to any further nodes then we will mark those nodes 
as vis[i]=1, which implies that they lead to a terminal node.
*/
