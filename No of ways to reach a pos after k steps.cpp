/**
----------------------------------------------------------------DYNAMIC PROGRAMMING with MEMOISATION-------------------------------------------------------------------

You are given two positive integers startPos and endPos. Initially, you are standing at position startPos on an infinite number line. With one step, 
you can move either one position to the left, or one position to the right.

Given a positive integer k, return the number of different ways to reach the position endPos starting from startPos, such that you perform exactly k steps. 
Since the answer may be very large, return it modulo 109 + 7.

Two ways are considered different if the order of the steps made is not exactly the same.

Note that the number line includes negative integers.

 

Example 1:

Input: startPos = 1, endPos = 2, k = 3
Output: 3
Explanation: We can reach position 2 from 1 in exactly 3 steps in three ways:
- 1 -> 2 -> 3 -> 2.
- 1 -> 2 -> 1 -> 2.
- 1 -> 0 -> 1 -> 2.
It can be proven that no other way is possible, so we return 3.



*/

class Solution {
public:
      long long int solve(int sp,int ep,int k,vector<vector<int>>&dp){
        //base case if target is reached
        if(k==0){
            if(sp==ep)
                return 1;
           
        }
        //base case if target is not reached
       if(k<=0)
           return 0;
        
        //memoization
          if(dp[sp][k]!=-1) return dp[sp][k];
        
      long long int ans=0;
        
        //going right
       ans=ans+solve(sp+1,ep,k-1,dp);
        //going left
       ans=ans+solve(sp-1,ep,k-1,dp);
       
        return dp[sp][k]=ans;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>>dp(startPos+endPos+10000,vector<int>(10000,-1));
        return solve(startPos,endPos,k,dp);
    }
};
