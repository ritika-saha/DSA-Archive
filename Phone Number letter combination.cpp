/**
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
*/

//----------------------------------------------------------------------------BACKTRACKING ----------------------------------------------------------------------

class Solution {
public:
    void solve(int cnt,string ds,string digits,unordered_map<char,string>&mp,vector<string>&ans){
      //length of combination reached means one of the combination has been found
        if(cnt==digits.length()){
            ans.push_back(ds);
            return;
        }
      //string to be combined
        string tmp=mp[digits[cnt]];
        for(int i=0;i<tmp.length();i++){
            ds+=tmp[i];
          //recursion strp- here we pass cnt+1 so that the combination is done with the next string
            solve(cnt+1,ds,digits,mp,ans);
          //BACKTRACKING STEP
            ds.pop_back();
        }
        return ;
    }
   
    vector<string> letterCombinations(string digits) {
      //map to strore the strings to be combined
        unordered_map<char,string>mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
      //index to travese through digits 
       int cnt=0;
      //string ds to carry the current combination in a recursion stack
       string ds="";
       vector<string>ans;
       if(digits.size()==0) return ans;

        solve(cnt,ds,digits,mp,ans);
        return ans;
    }
};
