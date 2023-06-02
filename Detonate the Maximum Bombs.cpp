/**
You are given a list of bombs. The range of a bomb is defined as the area where its effect can be felt. This area is in the shape of a circle with the center as the location of the bomb.

The bombs are represented by a 0-indexed 2D integer array bombs where bombs[i] = [xi, yi, ri]. xi and yi denote the X-coordinate and Y-coordinate of the location of the ith bomb, whereas ri denotes the radius of its range.

You may choose to detonate a single bomb. When a bomb is detonated, it will detonate all bombs that lie in its range. These bombs will further detonate the bombs that lie in their ranges.

Given the list of bombs, return the maximum number of bombs that can be detonated if you are allowed to detonate only one bomb.

 

Example 1:


Input: bombs = [[2,1,3],[6,1,4]]
Output: 2
Explanation:
The above figure shows the positions and ranges of the 2 bombs.
If we detonate the left bomb, the right bomb will not be affected.
But if we detonate the right bomb, both bombs will be detonated.
So the maximum bombs that can be detonated is max(1, 2) = 2.
*/

class Solution {
public:
    void dfs(int node,vector<int>&vis,vector<int>adj[],int &cnt){
        vis[node]=1;
        cnt++;
        for(auto it:adj[node]){
            if(vis[it]==0){
                dfs(it,vis,adj,cnt);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<int>adj[n];
        //making adjacency list for each node with their connected component as the nodes that lie within that radius area
        for(int i=0;i<n;i++){
            long long int xcurr,ycurr,rcurr;
            xcurr=bombs[i][0];
            ycurr=bombs[i][1];
            rcurr=bombs[i][2];
            for(int j=0;j<n;j++){
                //not considering same node 
                if(i!=j){
                    long long int x,y;
                    x=bombs[j][0];
                    y=bombs[j][1];
                    long long int distx,disty;
                    //distance between both nodes
                    distx=abs(x-xcurr);
                    disty=abs(y-ycurr);
                    //calculating is the current node distance is covering less area than target node area that is is it inside the range
                    if(distx*distx + disty*disty <=rcurr*rcurr)
                    adj[i].push_back(j);
                }
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            int cnt=0;
            vector<int>vis(n,0);
            //doing a dfs to find out how many nodes are connected to each node and taking the max as answer 
            dfs(i,vis,adj,cnt);
            ans=max(ans,cnt);
        }
        return ans;
    }
};
