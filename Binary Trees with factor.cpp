/**
823. Binary Trees With Factors

Given an array of unique integers, arr, where each integer arr[i] is strictly greater than 1.

We make a binary tree using these integers, and each number may be used for any number of times. Each non-leaf 
node's value should be equal to the product of the values of its children.

Return the number of binary trees we can make. The answer may be too large so return the answer modulo 109 + 7.

 

Example 1:

Input: arr = [2,4]
Output: 3
Explanation: We can make these trees: [2], [4], [4, 2, 2]
Example 2:

Input: arr = [2,4,5,10]
Output: 7
Explanation: We can make these trees: [2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2].

*/

class Solution {
public:
   
 const int mod = 1e9 + 7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
      //sorting for binary search
        sort(arr.begin(), arr.end());
      //to store the number of trees that can be formed with that particular node
        vector<long> dp(n);
      //to store ultimate answer
        int res = 0;
      //loop to go over each node
        for (int i = 0; i < n; i++)
        {
            int target = arr[i];
            int p = 0, q = i ; 
          //ways is 1 because atleast one tree with one node can be formed with the current node
            long ways = 1;
          //binary search to find the factors
            while(p <= q)
            {
                long mul = (((long)arr[p]) * (arr[q]));
                if (mul == target) 
                {
                  
                    if (p == q) ways += (dp[p] * dp[q]) % mod;
                    else ways += ((dp[p] * dp[q]) * 2) % mod;
                    p++;
                    q--;
                }
                else if (mul < target) p++;
                else if (mul > target) q--;
            }
            dp[i] = ways;
            res  = (int)((res + dp[i]) % mod);
        }
        return res ;
    }
};

