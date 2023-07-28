/**
You are given an integer array nums. Two players are playing a game with this array: player 1 and player 2.

Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a score of 0. At each turn, the player takes one of the numbers 
from either end of the array (i.e., nums[0] or nums[nums.length - 1]) which reduces the size of the array by 1. The player adds the chosen number to their score. 
The game ends when there are no more elements in the array.

Return true if Player 1 can win the game. If the scores of both players are equal, then player 1 is still the winner, and you should also return true. 
You may assume that both players are playing optimally.

 

Example 1:

Input: nums = [1,5,2]
Output: false
Explanation: Initially, player 1 can choose between 1 and 2. 
If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2). 
So, final score of player 1 is 1 + 2 = 3, and player 2 is 5. 
Hence, player 1 will never be the winner and you need to return false.
*/


class Solution {
public:
    int solve(vector<vector<int>>&dp,vector<int>&v,int i,int j,int k){
        if(i>j)return 0;
      //If we have already stored the answer for the current first and last indexes in the dp table, then simply return it.
        if(dp[i][j]!=-1)return dp[i][j];
        int first=0,last=0,ans=0;
        if(k%2==0){// it's player 1's turn
            first=v[i]+solve(dp,v,i+1,j,k+1); // pick the first element and add it to the score of player 1
            last=v[j]+solve(dp,v,i,j-1,k+1); // pick the last element and add it to the score player 1
            ans=max(first,last);//store the ans which will return the max score for player 1 
        }
        else{// it's player 2's turn
            first=-v[i]+solve(dp,v,i+1,j,k+1); // pick the first element and subtract it from the score of player 1
            last=-v[j]+solve(dp,v,i,j-1,k+1); // pick the lastelement and subtract it from the score of player 1
            ans=min(first,last);//store the ans which will return the min score for player 1 
        }
        return dp[i][j]=ans;
    }
    bool PredictTheWinner(vector<int>&v) {
        int i,n=v.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(dp,v,0,n-1,0)>=0; // ans >=0 implies player 1's score is greater than player 2's score
    }
};
