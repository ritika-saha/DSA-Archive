/**
LEETCODE= 844 using two pointer approach

Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

 

Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".
Example 2:

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".
Example 3:

Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".


*/

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int j=0,k=0;
        // for 1st string
        for(int i=0;i<s.size();i++)
        {
           if(s[i]=='#')
           {
                j--;
                j=max(0,j); // j will never be -ve
           }
           else
           {
               s[j]=s[i];
               j++;
           }
        }
        // for 2nd string
        for(int i=0;i<t.size();i++)
        {
           if(t[i]=='#')
           {
                k--;
                k=max(0,k); // k will never be -ve
           }
           else
           {
               t[k]=t[i];
               k++;
           }
        }
        if(j!=k) return false;
        else
        {
            for(int i=0;i<k;i++)
            {
                if(s[i]!=t[i]) return false;
            }
            return true;
        } 
    }
};


