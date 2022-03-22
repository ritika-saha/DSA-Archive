/** LEETCODE 1663

You are given two integers n and k. Return the lexicographically smallest string with length equal to n and numeric value equal to k.
The numeric value of a string consisting of lowercase characters is defined as the sum of its characters' numeric values. For example, the numeric value of the string "abe" is equal to 1 + 2 + 5 = 8.

Input: n = 3, k = 27
Output: "aay"
Explanation: The numeric value of the string is 1 + 1 + 25 = 27, and it is the smallest string with such a value and length equal to 3.
*/

class Solution {
public:
    string getSmallestString(int n, int k) {
        string s;
        for(int i=0;i<n;i++)
            s+='a';
        k-=n;
        for(int i=n-1;i>=0;i--){
            if(k==0)
                break;
            else if(k<25){
                s[i]=(char)(s[i]+k);
                k=0;
            }
            else{
                s[i]=(char)(s[i]+25);
                k-=25;
            }
        }
        return s;
    }
};


/**
----------------------------------------------------------------------------NOTES-----------------------------------------------------------------------------
1) we initialize the answer string (ans) with n number of a and so the sum till now will be n since a=1
2) we reduce the value of k by n
3) then we traverse the string from backwards to get the lexicographically smallest string 
4) if k is 0 we break from the loop because we've already got our answer
5) if k is smaller than 25 we add k to the ith index and make k=0
6) if k>25 we add 25 to the ith index and reduce k by 25 and then continue the loop
7) by the end of the loop we'll have the required answer
*/

