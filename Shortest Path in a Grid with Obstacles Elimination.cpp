//--------------------------------------------------------------------------LEETCODE HARD----------------------------------------------------------------------------
/**
You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle). You can move up, down, left, or right from and to an empty cell in one 
step.

Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1) given that you can eliminate at most k obstacles. If it is not possible to find such walk return -1.

 

Example 1:


Input: grid = [[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]], k = 1
Output: 6
Explanation: 
The shortest path without eliminating any obstacle is 10.
The shortest path with one obstacle elimination at position (3,2) is 6. Such path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).
*/

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
      //visited array to store the number of obstacles that we can still remove after walking through that cell
        vector<vector<int>>vis(m,vector<int>(n,-1));
      //queue for BFS traversal through the grid because that will help in finding the shortest path
        queue<vector<int>>q;
        //i,j,current path lenght,no. of obstacles we can still remove
        q.push({0,0,0,k}); 
        
        while(q.empty()==false){
            auto curr=q.front();
            q.pop();
            int i=curr[0],j=curr[1],pathLen=curr[2],curr_k=curr[3];
          //rejecting the current path if it gies outside the grid
            if(i<0 || j<0 ||i>=m || j>=n)
                continue;
          //---------------------destination found---------------------------
            if(i==m-1 && j==n-1)
                return pathLen;
          
          //if the current grid is an obstacle we remove it we can remove it else we reject the current path
            if(grid[i][j]==1){
               if(curr_k>0)
                   curr_k--;
                else
                    continue;
            }
            
            //our goal is to reach destination and it doesn't matter which path helps to do so. If you have two paths, you would always go forward with the 
          //one who can remove more obstacles in the future so we dont choose the current path if the previous path visits same grid and has removed lesser 
          //obstacles 
            if(vis[i][j]!=-1 && vis[i][j]>=curr_k)
                continue;
          
          //since the current node is not visited we store how many more obstacles we can still remove walking from that cell
            else
                vis[i][j]=curr_k; 
          
          //pushing all 4 direction moves into the queue along with increasing the path length
            q.push({i+1,j,pathLen+1,curr_k});
            q.push({i,j+1,pathLen+1,curr_k});
            q.push({i-1,j,pathLen+1,curr_k});
            q.push({i,j-1,pathLen+1,curr_k});
        }
      //if no such path found we return -1
        return -1;
    }
};
