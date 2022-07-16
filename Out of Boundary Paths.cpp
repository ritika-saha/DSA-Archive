/**
LEETCODE 576 DP ON GRIDS

There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn].
ou are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). 
You can apply at most maxMove moves to the ball.

Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. 
Since the answer can be very large, return it modulo 109 + 7.

 

Example 1:


Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
Output: 6



*/

//---------------------------------------------------------------Recursion + memoization-----------------------------------------------------------------------
class Solution {
public:
      long long mod = 1e9 + 7;
    int solve(int m,int n,int mm,int sr,int sc,int dp[99][99][99]){
        if(sr < 0 || sr >= m || sc < 0 || sc >= n)
            return 1;
        
        // if no moves are remaining
        
        if(mm <= 0)
            return 0;
        if(dp[sr][sc][mm] !=-1)
            return dp[sr][sc][mm];
        int down=solve(m,n,mm-1,sr+1,sc,dp);
        int right=solve(m,n,mm-1,sr,sc+1,dp);
        int up=solve(m,n,mm-1,sr-1,sc,dp);
        int left=solve(m,n,mm-1,sr,sc-1,dp);
       return dp[sr][sc][mm]=(up%mod + down%mod + right%mod + left%mod)%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int dp[99][99][99];
        memset(dp,-1,sizeof(dp));
        return solve(m,n,maxMove,startRow,startColumn,dp);
    }
};


// Time complexity- O(m*n*moves)
//Space Complexity- o(m*n)+o(m*n*moves)
