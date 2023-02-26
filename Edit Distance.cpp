//---------------------------------------------------------------DP-------------------LC HARD----------------------------------------------------------------------

/**
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();
        int dp[m+1][n+1];

      //initializing the 0th row and column
        for(int i=0;i<=m;i++)
        dp[i][0]=i;
        for(int j=0;j<=n;j++)
        dp[0][j]=j;

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
              //if the letters are same we dont do anything but propagate the previous value to the current dp index
                if(word1[i-1]==word2[j-1])
                dp[i][j]=dp[i-1][j-1];
              //if they are not equal then there are 3 operations we can do and consider the one that is giving the minimun value 
                else{
                  //insert letter from word2 into word1
                    int insertop=dp[i][j-1];
                  //delete letter from word1
                    int deleteop=dp[i-1][j];
                  //replace letter in word1 with letter from word2
                    int replaceop=dp[i-1][j-1];
                  //adding 1 for the one operation we have done here and consider the minimum of the three operations
                    dp[i][j]=1+min(insertop,min(deleteop,replaceop));

                }
            }
        }

        return dp[m][n];
    }
};
