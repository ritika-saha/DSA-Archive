/**
You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.

Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.

 

Example 1:

Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
Example 2:

Input: nums = [5,6,7,8,9], x = 4
Output: -1
Example 3:

Input: nums = [3,2,20,1,1,3], x = 10
Output: 5
Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.
*/

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
      //total sum of the array elements
        int total=accumulate(nums.begin(),nums.end(),0);
      //WE FIND THE MAXIMUM SUBARRAY WITHIN THE ARRAY EXCLUSING WHICH WE CAN ACHIEVE THE SUM X AS ASKED . TO THE TARGET SUM OF THIS SUB ARRAY WILL BE THE DIFFERENCE AS BELOW
        int target=total-x;
        if(target<0)
        return -1;
        if(target==0)
        return nums.size();

        int n=nums.size();
        int ops=INT_MAX;
        int currsum=0;
      //WE FOLLOW A 2-POINTER SLIDING WINDOW APPROACH AND WE KEEP ADDING ELEMENTS IN THE CURRENT SUB-ARRAY AND INCREMENT RIGHT AND WHEN THE SUM EXCEEDS THE TARGET WE REMOVE
      //FROM THE LEFT AND MOVE THE LEFT POINTER FORWARD THUS DECREASING THE WINDOW
      //THIS LEAVES OUT THE ELEMENTS ONLY ON THE OUTSIDE WHICH IS IN ACCORDANCE WITH THE ASKED QUESTION BECAUSE WE CAN REMOVE ONLY THE ELEMENTS FROM FRONT AND BACK
        int left=0,right=0;
        while(right<n){
            currsum+=nums[right];
            right++;
            while(currsum>target && left<n){
                currsum-=nums[left];
                left++;
            }
            if(currsum==target){
                ops=min(ops,(n-(right-left)));
            }
        }

        return ops==INT_MAX?-1:ops;
    }
};
