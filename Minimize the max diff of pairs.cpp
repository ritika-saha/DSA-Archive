/**
You are given a 0-indexed integer array nums and an integer p. Find p pairs of indices of nums such that the maximum difference amongst all the pairs is minimized. 
Also, ensure no index appears more than once amongst the p pairs.

Note that for a pair of elements at the index i and j, the difference of this pair is |nums[i] - nums[j]|, where |x| represents the absolute value of x.

Return the minimum maximum difference among all p pairs. We define the maximum of an empty set to be zero.

 

Example 1:

Input: nums = [10,1,2,7,1,3], p = 2
Output: 1
Explanation: The first pair is formed from the indices 1 and 4, and the second pair is formed from the indices 2 and 5. 
The maximum difference is max(|nums[1] - nums[4]|, |nums[2] - nums[5]|) = max(0, 1) = 1. Therefore, we return 1.
*/

class Solution {
public:
    bool validate(int mid,vector<int>&nums,int p){
        int n=nums.size();
        int cnt=0;
      //we count the number of pairings that can be formed that have difference less than equal to mid that is the target differnce
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]<=mid){
                cnt++;
              //increment i here is the current pairing is possible because we ca not reuse single index twice 
                i+=1;
            }
        }
      //if number of pairs formed is greater than or equal to the number of required pairs
        return cnt>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
      //FOR PROBLEMS WHERE WE NEED TO MAXIMISE THE MIN OR MINIMISE THE MAX APPLY BINARY SEARCH
        sort(nums.begin(),nums.end());
      //search space (differences) can be between 0 and the differnece between the smallest and largest in the array
        int low=0,high=nums[nums.size()-1]-nums[0];
        int ans=INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;
          //if p number of pairings are possible as validated by validate function then we minimise the search function uptill mid-1 and update ans
            if(validate(mid,nums,p)){
                high=mid-1;
                ans=mid;
            }
            else
            low=mid+1;
        }
        return ans;
    }
};
