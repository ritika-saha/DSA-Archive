//---------------------------------------------------DP MEMOIZATION TABULATION------------------------------------------------------------------------------------
/**
Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are 
perfect squares while 3 and 11 are not.

 

Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
*/

//--------------------------------------------------------------------------MEMOIZATION------------------------------------------------------------------------------
class Solution {
public:
    int solve(int num,vector<int>&dp){
        if(num==0){
            return 0;
        }
        if(dp[num]!=-1) return dp[num];
        int minCnt=INT_MAX;
        for(int i=1;i<=sqrt(num);i++){
            int currCnt=1+solve((num-(i*i)),dp);
            minCnt=min(minCnt,currCnt);
        }
        return dp[num]=minCnt;
    }
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);  
    }
};

//-----------------------------------------------------------------------TABULATION----------------------------------------------------------------------------------
class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+1,INT_MAX);
         dp[0]=0;
        for(int i=1;i<=n;i++){
            int minCnt=INT_MAX;
            for(int j=1;j<=sqrt(i);j++){
            int currCnt=1+dp[i-(j*j)];
            minCnt=min(minCnt,currCnt);
            }
            dp[i]=minCnt;
        }
        return dp[n];
    }
};
