/**
LEETCODE- 1695  SLIDING WINDOW AND HASHMAP

You are given an array of positive integers nums and want to erase a subarray containing unique elements. 
The score you get by erasing the subarray is equal to the sum of its elements.

Return the maximum score you can get by erasing exactly one subarray.

Example 1:

Input: nums = [4,2,4,5,6]
Output: 17
Explanation: The optimal subarray here is [2,4,5,6].
Example 2:

Input: nums = [5,2,1,2,5,2,1,2,5]
Output: 8
Explanation: The optimal subarray here is [5,2,1] or [1,2,5].



*/

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
      int st=0,end=0,n=nums.size(); 
        int sum=0,ans=0;
        unordered_map<int,int> mp;
        while(end<n){
            sum+=nums[end]; //adds the current element to the sum
            mp[nums[end]]++; //marks it present in the hashmap
            int curEl=nums[end];
            end++; //incrementing the end index
            while(mp[curEl]>1){ //if the current element was already present in the sub array then remove elements from start until we encounter the problem element 
                int left=nums[st];
                st++; //incrementing start index
                mp[left]--;  //unmarking it from hashmap
                sum-=left; //removing it from the sum
            }
            ans=max(ans,sum); //max cuz we gotta chose the maximum 
        }
        
        
    return ans;
    }
};
