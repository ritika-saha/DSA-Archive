/*
----------------------------------------------------------------------------BACKTRACKING----------------------------------------------------------------------------
Return all non-negative integers of length n such that the absolute difference between every two consecutive digits is k.

Note that every number in the answer must not have leading zeros. For example, 01 has one leading zero and is invalid.

You may return the answer in any order.

 

Example 1:

Input: n = 3, k = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.

**/

class Solution {
public:
      void help(int idx, int n, int k, int num, vector<int> &ans)
    {
        //IF THE NUMBER HAS REACHED RANGE LIMIT
        if(idx == n)
        {
            if(ans.size() == 0 || ans.back() != num)    //To prevent duplicate answers when rem - k == rem + k
                ans.push_back(num);                    
            return;
        }
        
        //GETTING THE LAST DIGIT
        int rem = num%10;
        
       
        if(rem + k < 10)
        {
            help(idx+1, n, k, num*10 + (rem+k), ans);
        }
        
        if(rem - k >= 0)
        {
            help(idx+1, n, k, num*10 + (rem-k), ans);
        }
        
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
      //STARTING FROM 1 TO PREVENT LEADING ZEROS
        for(int i = 1; i < 10; i++)
        {
            help(1, n, k, i, ans);
        }
        return ans;
    }
};
