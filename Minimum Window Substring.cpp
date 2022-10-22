//----------------------------------------------------SLIDING WINDOW HARD PROBLEM-----------------------------------------------------------------------------
/**
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is 
included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
*/

class Solution {
public:
    string minWindow(string s, string t) {
      //POINTERS STARTING AT THE STARTING INDEX OF STRING S
        int i=0,j=0;
      //KEPPING TRACK OF THE CURRENT WINDOW SIZE
        int window=INT_MAX;
      //MAP TO STORE THE CHARS AND FREQUENCY OF UNIQUE LETTERS IN T
        unordered_map<char,int>mp;
      //STARTING INDEX OF THE SUBSTRING
        int start=0;
      //FILLING THE MAP
        for(auto it:t)
            mp[it]++;
        
      //VARIABLE TO KEEP TRACK OF THE NUMBER OF UNIQUE CHARACTERS IN T AND IF ALL THE REQUIRED CHARACTERS ARE PRESENT IN THE CURRENT WINDOW
        int count=mp.size();
      
      //TRAVERING THE GIVEN STRING S  
        while(j<s.length()){
          //DECREASING THE COUNT OF THE CURRENT VARIABLE
            mp[s[j]]--;
          
          //IF THE COUNT OF THE CURRENT VARIABLE IS 0 THAT MEANS THAT CHARACTER AND THE ENTIRE AMMOUNT OF IT THAT IS REQUIRED IS ALREADY FOUND IN THE CURRENT WINDOW 
            if(mp[s[j]]==0)
                count--;  //DECREASING COUNT SYMBOLISING ONE UNIQUE CHARACTER HAS ALREADY BEEN FOUND
            
          //WHILE THE ALL THE CHARACTERS AREE PRESENT IN THE CURRENT WINDOW WE REMOVE CHARACTERS FROM THE BEGINING THAT ARE NOT NECESSARY TO REDUCE WINDOW SIZE
            while(count==0){
              //IF THE CURENT WIDNOW IS SMALLER THAN PREVIOUS WINDOW WE REPLACE IT AND MOVE START TO I
                if(j-i+1<window){
                    window=j-i+1;
                    start=i;
                }
              //INCREASE THE COUNT OF THE REMOVED CHARACTER 
                mp[s[i]]++;
              
              //IF THE COUNT OF IT IS GREATER THAN 0 THAT MEANS WE REQUIRE THAT CHARACTER IN THE CURRENT WINDOW SO WE INCREASE THE COUNT
                if(mp[s[i]]>0)
                    count++;
                
                i++;
                
            }
            j++;
            
        }
        
            
        //IF WINDOW SIZE IS MAX THAT MEANS THERE IS NO SUCH SUBSSTRING
    if(window==INT_MAX)
        return "";
    return s.substr(start,window);
        
    }
};
