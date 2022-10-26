/**
Given an integer array nums and an integer k, return true if nums has a continuous subarray of size at least two whose elements sum up to a multiple of k, 
or false otherwise.

An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.

 

Example 1:

Input: nums = [23,2,4,6,7], k = 6
Output: true
Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.
Example 2:

Input: nums = [23,2,6,4,7], k = 6
Output: true
Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.
Example 3:

Input: nums = [23,2,6,4,7], k = 13
Output: false
 
*/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
      
        int n = nums.size();

        // curr_sum will keep track of sum from start till ith

        int curr_sum = 0;

        // declare a hashmap

        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++)
        {
            // update curr_sum

            curr_sum += nums[i];

            // if multiple of k found 

            if(curr_sum % k == 0 && i > 0)
            {
                return true;
            }
            
          //if there exists a curr_sum%k in the map already it means that there is the reminder that is present in the array previously till a point so 
          //after that point curr_sum%k==0 must exist   till i from the index of the curr_sum%k
            if(mp.count(curr_sum % k) && (i - mp[curr_sum % k] >= 2))
            {
                return true;
            }

            // if curr_sum % k is not present in map then insert it into map

            if(mp.count(curr_sum % k) == 0)
            {
                mp[curr_sum % k] = i;
            }
        }

        return false;
    }
};
