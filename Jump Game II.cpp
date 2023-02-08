/**
You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
*/

class Solution {
public:
    int n;
    int solve(int i, vector<int> &nums,vector<int>&dp)
    {
        if(i == n-1)  
            return 0; //if reached last index then no need to move further so no steps required
        if(dp[i]!=-1) return dp[i];
        int mini = INT_MAX-1;    //-1 bc in loop 1 + solve(), if solve() returns INT_MAX, 1+INT_MAX will result stack overflow                  
        for(int j=1; j<=min(n-1 - i, nums[i]); j++) //possible steps we can take from i
        {
            int temp = 1 + solve(i+j, nums,dp); //at i take 1 step of length j, so we reach i+j
            mini = min(mini, temp); //we take minimum of all steps from i to reach n-1         
        }
        
        return dp[i]=mini;  /**if not reached n-1, then it will not go in loop and return mini = INT_MAX-1 at some step where further going forward is not 
possible, back trackingto previous call temp = 1 + INT_MAX-1, mini = min(mini, INT_MAX), so we see for current j it will get INT_MAX as temp ans,
 while taking minimum it won't affect the answer
        
        */
    }
    
    int jump(vector<int>& nums) 
    {
        n = nums.size();
        vector<int>dp(n,-1);
        return solve(0, nums,dp);
    }
};
