//---------------------------------------------------------------------GRAPH---------------------------------------------------------------------------------

/**
Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) 
forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).

Example 1:

Input:
grid[][] = {{1, 1, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 0, 0, 1, 1}}
Output:
1
Explanation:
grid[][] = {{1, 1, 0, 0, 0}, 
            {1, 1, 0, 0, 0}, 
            {0, 0, 0, 1, 1}, 
            {0, 0, 0, 1, 1}}
Same colored islands are equal.
We have 2 equal islands, so we 
have only 1 distinct island.

Example 2:

Input:
grid[][] = {{1, 1, 0, 1, 1},
            {1, 0, 0, 0, 0},
            {0, 0, 0, 0, 1},
            {1, 1, 0, 1, 1}}
Output:
3
Explanation:
grid[][] = {{1, 1, 0, 1, 1}, 
            {1, 0, 0, 0, 0}, 
            {0, 0, 0, 0, 1}, 
            {1, 1, 0, 1, 1}}
Same colored islands are equal.
We have 4 islands, but 2 of them
are equal, So we have 3 distinct islands.
*/



//THIS PROBLEM IS BASICALLY EXTENSION OF NUMBER OF ISLAND PROBLEM. WE HAVE TO FIND 1S IN THE MATRIX THAT ARE UNVISITED AND PERFORM A BFS OR DFS FROM THAT ON ITS 4 
//DIRECTION. BUT HERE WE HAVE TO STORE THE SHAPE OF THE ISLANDS TOO WHICH WE DO BY TAKING A BASE COORDINATE AND SUBSTRACT THAT FROM ALL OTHER NODES BEFORE STORINMG
//BASICALLY THE DISSERENCE WOULD BE SAME FOR ISLANDS THAT HAVE SAME SHAPE

class Solution {
  public:
  
  void dfs(int r,int c,vector<vector<int>>&grid,vector<vector<int>>&vis,vector<pair<int,int>>&v,int baseRow,int baseCol){
    vis[r][c]=1;
     int m=grid.size(),n=grid[0].size();
     v.push_back({r-baseRow,c-baseCol});
     int delrow[]={-1,0,+1,0};
  int delcol[]={0,-1,0,+1};
     for(int i=0;i<4;i++){
         int nr=r+delrow[i];
         int nc=c+delcol[i];
         if(nr>=0 && nr<m && nc>=0 && nc<n && vis[nr][nc]==0 && grid[nr][nc]==1){
             dfs(nr,nc,grid,vis,v,baseRow,baseCol);
         }
     }
  }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        set<vector<pair<int,int>>>st;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 && grid[i][j]==1){
                    vector<pair<int,int>>v;
                    dfs(i,j,grid,vis,v,i,j);
                    st.insert(v);
                }
            }
        }
        return st.size();
        
    }
};
