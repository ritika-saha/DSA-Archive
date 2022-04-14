/*
Given an array of distinct integers candidates and a target integer target, 
return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. 
Two combinations are unique if the frequency of at least one of the chosen numbers is different.

(PICK AND NOT PICK RECURSIVE CONCEPT)
**/

class Solution {
public:
    vector<vector<int>> helper(int ind,vector<vector<int>>&ans,vector<int>&ds,int target,vector<int>c){
        //base case
        if(ind==c.size()){
            if(target==0){
                ans.push_back(ds);
                
            }
            return ans;
        }
        //pick
        if(c[ind]<=target){
            ds.push_back(c[ind]);
            helper(ind,ans,ds,target-c[ind],c);
            //popping back for future not pick
            ds.pop_back();
        }
        
        //not pick
        helper(ind+1,ans,ds,target,c);
        return ans;
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>ds;
        return helper(0,ans,ds,target,candidates );
    }
};
