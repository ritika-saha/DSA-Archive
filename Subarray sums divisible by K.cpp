/**
Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
Example 2:

Input: nums = [5], k = 9
Output: 0
*/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int>v=nums;
        //calculating prefix sum
        for(int i=1;i<nums.size();i++)
        v[i]=v[i]+v[i-1];

        //vector to store the mod count 
        vector<int>modcnt(k);
        modcnt[0]=1;
        for(auto x:v){
            if(x<0) x=(x%k+k)%k;
            modcnt[x%k]++; 
        }
        int ans=0;

        //n choose 2
        for(auto it:modcnt)
        ans+=it*(it-1)/2;

        return ans;
    }
};

/**
----------------------------------------------------------------NOTE-----------------------------------------------------------------------------------------------
For any subarray [i..j] whose sum is divisible by k, we can easily see that prefixSum[j] - prefixSum[i-1] = 0.
Thus if there are any repetitions in our prefixSum%k array, that represents a required subarray.

So if we have the count of every possible value of prefixSum%k, we can determine if there are any subarray that end at the current index and the sum is divisible by k.
*/
