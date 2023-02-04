/**
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
*/

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
//we have to find if such a substring exists in s2 which is a permutation of s1, which means we have to find a substring in s2 such that the frequency of the
//characters in that substring is same as the frequency of the characters in s1.
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------

class Solution {
  //function to check in the frequencies are same that is the strings are permutation 
    bool areVectorsEqual(vector<int> a, vector<int> b){
        for(int i=0; i<26; i++){
            if(a[i]!=b[i]) return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size()) return false;
      //creating frequency array for s1
        vector<int> freqS1(26, 0);
        for(char c: s1) freqS1[c-'a']++;
        
        vector<int> freqS2(26, 0);
      //j for s2 and i for characters in the window
        int i=0, j=0;
        
        while(j<s2.size()){
          //including current character from s2 into the current window
            freqS2[s2[j]-'a']++;
            //if window size equal to size of s1
            if(j-i+1==s1.size()){
                if(areVectorsEqual(freqS1, freqS2)) return true;
            }
            
          //if window size is smaller we increase the window
            if(j-i+1<s1.size()) j++;
          //else if the window size is same but the window isn't valid
            else{
              //we exclude the first character from the window
                freqS2[s2[i]-'a']--;
                i++;
                j++;
            }
        }
        return false;
    }
};
