/**
LEETCODE- 81 (used Binary Search alsgo)

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

example-------
Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false

*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
       int l=0,r=nums.size()-1;
        
        while(l<=r){
            int mid=l+(r-l)/2;
            
            //if target found at mid
            if(nums[mid]==target)
                return true;
            
            //incase of duplicate elements found
            if(nums[l]==nums[mid] && nums[r]==nums[mid])
            {
                l++;
                r--;
            }
            
            
            //searching in the first half of the array
          else  if(nums[l]<=nums[mid]){
                if(nums[mid]>target && nums[l]<=target)
                    r=mid-1;
                else
                    l=mid+1;
            }
            
            
            //searching in the second half of the array
            else  if(nums[l]>nums[mid]){
                if(nums[mid]<target && nums[r]>=target)
                    l=mid+1;
                else
                    r=mid-1;
            }
        }
        return false;
    }
};


/**
------------------------------------------------------------------NOTES--------------------------------------------------------------------------------------------
1)here we've initialized left to 0 and right to size of array-1
2) we traverse the array until l<=r and calculate the mid in every iteration
3) we check if arr[mid] is the target then return true if it is
4) next condiiton we check in there are duplicated elements then the mid will be equal to the left and right which indicates duplicated thus we bring the left
and right towards the middle by incrementing the left and decrementing the right by one
5) then we check if the element is present in the first half of the array then the left will be smaller or equal to the mid
6) if yes then we check if the target is smaller than mid then we decrement the right to mid-1 else increment left to mid+1
7) we do the same for the 2md half and when we reach the target the loop returns true
8) if we don't reach the target after the loop we return false

*/
