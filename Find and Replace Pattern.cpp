/**
LEETCODE 890

Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.

A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.

 

Example 1:

Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation, since a and b map to the same letter.


*/


class Solution {
public:
    vector<int> findPattern(string s){
       if(s.length()==0)
           return {};
        unordered_map<char,int>mp;
        vector<int>pattern;
        int ind=0;
        for(int i=0;i<s.length();i++){
            if(mp.find(s[i])==mp.end()){
                //incremeting for every unique index
                ind++;
                mp[s[i]]=ind;
               pattern.push_back(ind);
            }
            else{
                //if not unique add previously found pattern value
                pattern.push_back(mp[s[i]]);
            }
        }
        return pattern;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<int> patterns_pattern=findPattern(pattern);
        vector<string>ans;
        for(int i=0;i<words.size();i++){
            vector<int>words_pattern=findPattern(words[i]);
            //matching pattern to see if they have same pattern
            if(patterns_pattern==words_pattern)
                ans.push_back(words[i]);
        }
        return ans;
    }
};
