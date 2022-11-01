/**
You have a 2-D grid of size m x n representing a box, and you have n balls. The box is open on the top and bottom sides.

Each cell in the box has a diagonal board spanning two corners of the cell that can redirect a ball to the right or to the left.

A board that redirects the ball to the right spans the top-left corner to the bottom-right corner and is represented in the grid as 1.
A board that redirects the ball to the left spans the top-right corner to the bottom-left corner and is represented in the grid as -1.
We drop one ball at the top of each column of the box. Each ball can get stuck in the box or fall out of the bottom. A ball gets stuck if it hits a "V" shaped 
pattern between two boards or if a board redirects the ball into either wall of the box.

Return an array answer of size n where answer[i] is the column that the ball falls out of at the bottom after dropping the ball from the ith column at the top, 
or -1 if the ball gets stuck in the box.

 

Example 1:



Input: grid = [[1,1,1,-1,-1],[1,1,1,-1,-1],[-1,-1,-1,1,1],[1,1,1,1,-1],[-1,-1,-1,-1,-1]]
Output: [1,-1,-1,-1,-1]
Explanation: This example is shown in the photo.
Ball b0 is dropped at column 0 and falls out of the box at column 1.
Ball b1 is dropped at column 1 and will get stuck in the box between column 2 and 3 and row 1.
Ball b2 is dropped at column 2 and will get stuck on the box between column 2 and 3 and row 0.
Ball b3 is dropped at column 3 and will get stuck on the box between column 2 and 3 and row 0.
Ball b4 is dropped at column 4 and will get stuck on the box between column 2 and 3 and row 1.
*/

//--------------------------------------------------------------RECURSIVE SOLUTION -------------------------------------------------------------------------
class Solution {
public:
    int m,n;
    int solve(int r,int c,vector<vector<int>> &grid){
      //if we've reached the last row means we've got out answer
        if(r==m)return c;
      //if we're directed to move right 
        if(grid[r][c]==1){
          //if moving right makes us go out of the grid or the right grid has left means a V is formed which will make us get stuck so return -1
            if(c+1>=n || grid[r][c+1]==-1)return -1;
          //else we recursively call dfs with r and column moved to next row right
            return solve(r+1,c+1,grid);
        }
        if(c-1<0 || grid[r][c-1]==1)return -1;
        return solve(r+1,c-1,grid);
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        vector<int> ans(n,-1);
      //calling dfs function for each node in the first row because we gotta move balls from 1st row to last row
        for(int c=0;c<n;c++){
            ans[c]=solve(0,c,grid);
        }
        return ans;
    }
};

//--------------------------------------------------------------MEMOIZED SOLUTION (bottom Up)-----------------------------------------------------------------------

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
      //dp to calculate values bottom up
        vector<vector<int>>dp(m+1,vector<int>(n,-1));
      //filling the last row to get started assuming we reach the target
        for(int i=0;i<n;i++) dp[m][i]=i;
      
      //traversing the array bottom up
        for(int i=m-1;i>=0;i--){
            for(int j=0;j<n;j++){
              //for right
                if(grid[i][j]==1){
                    bool canMoveRight=(j+1>=n)?false:(grid[i][j+1]==1);
                    if(canMoveRight)
                        dp[i][j]=dp[i+1][j+1];
                }
              //for left
                else if(grid[i][j]==-1){
                    bool canMoveLeft=(j-1<0)?false:(grid[i][j-1]==-1);
                    if(canMoveLeft)
                        dp[i][j]=dp[i+1][j-1];
                }
            }
        }
      //the first row of the dp array will have the answer after all the iterations are completed
        return  dp[0];
    }
};
