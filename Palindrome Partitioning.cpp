/**
Given a string s, partition s such that every 
substring
 of the partition is a 
palindrome
. Return all possible palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
*/

class Solution {
public:
  //function to check palindrome
    bool ispal(string s){
        int end=s.length()-1,i=0;
        while(i<end){
           if(s[i]!=s[end])
               return false;
            i++;
            end--;
        }
        return true;
    }
  
  //recursively generating substrings and backtracking
    void solve(int ind,int n,vector<string>&ds,vector<vector<string>>&ans,string s){
        if(ind==n){
            ans.push_back(ds);
            return;
        }
        
        for(int i=ind;i<n;i++){
          //getting the substring from the index to i-ind
            string temp=s.substr(ind,i-ind+1);
          //if it is palindrome we include it in and and increment the index and recusrively call the function again with the incremented index
            if(ispal(temp)){
                ds.push_back(temp);
                solve(i+1,n,ds,ans,s);
              //backtracking
                ds.pop_back();
                
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        solve(0,s.length(),ds,ans,s);
        return ans;
    }
};
