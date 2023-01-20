/**
Given an integer array nums, return all the different possible non-decreasing subsequences of the given array with at least two elements. 
You may return the answer in any order.

 

Example 1:

Input: nums = [4,6,7,7]
Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
Example 2:

Input: nums = [4,4,3,2,1]
Output: [[4,4]]
*/

class Solution {
public:
    void solve(int ind,vector<int>nums,vector<int>&tmp,set<vector<int>>&s){
        int n=nums.size();
      //base condition
        if(ind>=n){
            if(tmp.size()>=2)
            s.insert(tmp);
            return;
        }
      //if the temp array is empty or the element at the current index is greater than the last element in the vector then it can make a non decresing array
        if(tmp.size()==0||nums[ind]>=tmp.back()){
          //pushing back the current element int the temp array
            tmp.push_back(nums[ind]);
          //recursion call to the function with the current element included in temp
            solve(ind+1,nums,tmp,s);
          //backtracking step
            tmp.pop_back();
        }
      //recussion call without the current element incase its not greater than the previous elemnt 
        solve(ind+1,nums,tmp,s);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
      //temporary vector to store the current elements one by one
        vector<int>tmp;
      //set so we don't store duplicate vectors
        set<vector<int>>s;
        solve(0,nums,tmp,s);
      //casting the set containing the answer vectors into vector
        vector<vector<int>>ans=vector(s.begin(),s.end());
        return ans;
    }
};
