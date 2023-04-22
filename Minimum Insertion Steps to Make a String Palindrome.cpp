/**
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

 

Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.
Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".
*/

class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
      //finding lcs among string and its revese which will give the longest palindrome subsequence in the string
        string a=s;
        reverse(s.begin(),s.end());
        string b=s;
      //tabulation way of finding lcs among the string and its reverse
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(a[i-1] == b[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
      //----------------------------------------------------------------------------------------------------------------------
      // THE Minimum Insertion Steps to Make a String Palindrome IS THE DIFFERENCE BETWEEN THE LENGTH OF THE STRING AND THE LENGTH OF LCS
      //BECAUSE LCS GIVES THE NUMBER OF CHAR THAT ARE ALREADY PALINDROME AND DOESNT NEED ANY FURTHER INSERTION AND THE DIFFENECE GIVES THE EXTRA CHARACTERS THAT 
      //NEED TO BE INSERTED TO MAKE PALINDROME
      //-----------------------------------------------------------------------------------------------------------------------------
        return n - dp[n][n];
    }
};
