//Graph bfs

/**
You are given an n x m binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Find the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

Example 1:

Input:
grid[][] = {{0, 0, 0, 0},
            {1, 0, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}}
Output:
3
Explanation:
0 0 0 0
1 0 1 0
0 1 1 0
0 0 0 0
The highlighted cells represents the land cells.
*/


class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
      //string the lands that are on the border of the grid so we can bfs from those points to trvaerse all the lands connected to them
        queue<pair<int,int>>q;
      
      //insering all the border lands in queue and marking them visited
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0|| i==m-1||j==n-1){
                    if(grid[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=1;
                    }
                }
            }
        }
        
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
      
      //no doing a bfs from the border lands on all 4 sides of that point we visit all the possible nodes we can visit
        while(q.empty()==false){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+delrow[i];
                int nc=c+delcol[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && vis[nr][nc]==0 && grid[nr][nc]==1)
                {
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
        int ans=0;
      //after bfs the nodes that remain are unvisited are the nodes that are surrounded on all sides by water which means they are part of the answer so we count'em
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 && grid[i][j]==1)
                ans++;
            }
        }
        return ans;
    }
};
