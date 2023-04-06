/**
Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally
(all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.

 

Example 1:



Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation: 
Islands in gray are closed because they are completely surrounded by water (group of 1s).
*/

//----------------------------------------------------------------------------DFS---------------------------------------------------------------------------------

class Solution {
private:
    bool isClosed(vector<vector<int>>& grid, int i, int j) {
        // Out of bounds are not considered close
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size())return false;
        
        // Return true if it's water or a visited cell
        if (grid[i][j] == 1 || grid[i][j] == 2) return true;

        // Mark current land as visited
        grid[i][j] = 2;

        // Check if all 4 directions are closed recursively.
        bool isLeftClosed = isClosed(grid, i, j - 1);
        bool isRightClosed = isClosed(grid, i, j + 1);
        bool isTopClosed = isClosed(grid, i + 1, j);
        bool isBottomClosed = isClosed(grid, i - 1, j);

        return isLeftClosed && isRightClosed && isTopClosed && isBottomClosed;
    }

public:
    // T:O(n*m), S:O(n*m)
    int closedIsland(vector<vector<int>>& grid) {
        int islands = 0;

        // Go through all cells in a grid
        for(int i = 0; i < grid.size(); i++) { // O(n)
            for(int j = 0; j < grid[i].size(); j++) { // O(m)
                if(grid[i][j] == 0 && isClosed(grid, i, j)) {
                    islands++;
                }
            }
        }
        return islands;
    }
};

//---------------------------------------------------------------------------BFS--------------------------------------------------------------------------------

class Solution {
public:
    int closedIsland(vector<vector<int>>& g) {
        queue<pair<int,int>>q;
        int n=g.size(),m=g[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if(g[i][j]==0){
                    g[i][j]=1;
                    q.push({i,j});}
                }
            }
        }
        while(q.size()){
            auto l=q.front();
            q.pop();
            int x=l.first;
            int y=l.second;
            int dx[4]={1,-1,0,0};
            int dy[4]={0,0,1,-1};
            for(int i=0;i<4;i++){
                int nx=dx[i]+x;
                int ny=dy[i]+y;
                if(nx>=0 && nx<n && ny>=0 && ny<m && g[nx][ny]==0){
                    g[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
        int ct=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!g[i][j]){
                    ct++;
                      q.push({i,j});
                       while(q.size()){
            auto l=q.front();
            q.pop();
            int x=l.first;
            int y=l.second;
            int dx[4]={1,-1,0,0};
            int dy[4]={0,0,1,-1};
            for(int i=0;i<4;i++){
                int nx=dx[i]+x;
                int ny=dy[i]+y;
                if(nx>=0 && nx<n && ny>=0 && ny<m && g[nx][ny]==0){
                    g[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
                }
            }
        }
        return ct;
    }
};
