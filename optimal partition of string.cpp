/**
Given a string s, partition the string into one or more substrings such that the characters in each substring are unique. That is, no letter appears in a 
single substring more than once.

Return the minimum number of substrings in such a partition.

Note that each character should belong to exactly one substring in a partition.

 

Example 1:

Input: s = "abacaba"
Output: 4
Explanation:
Two possible partitions are ("a","ba","cab","a") and ("ab","a","ca","ba").
It can be shown that 4 is the minimum number of substrings needed.
Example 2:

Input: s = "ssssss"
Output: 6
Explanation:
The only valid partition is ("s","s","s","s","s","s").
*/

//-------------------------------------------------------------stack implementation ------------------------------------------------------------------------
class Solution {
public:
    int partitionString(string s) {
        unordered_set<char>st;
        int ans=1;
        for(int i=0;i<s.length();i++){
            if(st.find(s[i])!=st.end()){
                ans++;
                st.clear();
            }
            st.insert(s[i]);
        }
        return ans;
    }
};

//-------------------------------------------------------------Bit masking-------------------------------------------------------------------------------------
class Solution {
public:
    int partitionString(string s) {
        int mask=0,ans=1,i=0;
        while(i<s.length()){
            int val=s[i]-'a';
            if(mask & (1<<val)){
                ans++;
                mask=0;
            }
            mask=mask | (1<<val);
            i++;
        }
        return ans;
    }
};
