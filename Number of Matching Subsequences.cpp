/**
LEETCODE 792

Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without
changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
 

Example 1:

Input: s = "abcde", words = ["a","bb","acd","ace"]
Output: 3
Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".



*/


class Solution {
public:
   bool isSubsequence(string s1, string s2, int m, int n){
		//This function behaves simliar to the one in previous approach
        int j = 0;
        for(int i = 0; i < m && j < n; i++){
            if(s1[i] == s2[j]) j++;
        }
        return j == n;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
		
		//Hashmap with string and bool pair
		// Storing whether a string is subsequence or not!
        map<string, bool> mp;
        for(auto x: words){
		
			//if the string has already occurred then don't compute again
            if(mp.find(x) != mp.end()) {
				// if that string has value true that means it is subsequence, count++
                if(mp[x] == true) {
                    count++;
                }
				//if not, go for next string
                continue;
            }
			
			// if not calculated previously, compute the value and assign to x(current string from words)
            mp[x] = isSubsequence(s, x, s.size(), x.size());
            count += (mp[x] == true);
        }
		// return the final count of number of subsequences.
        return count;
    }
};



//gotta consider cases where it has already been checked if a string is subsequnence or it'll give a TLE
