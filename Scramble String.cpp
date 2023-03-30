//--------------------------------------------------------------------------DP HARD---------------------------------------------------------------------------------
/**
We can scramble a string s to get a string t using the following algorithm:

If the length of the string is 1, stop.
If the length of the string is > 1, do the following:
Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
Apply step 1 recursively on each of the two substrings x and y.
Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.

 

Example 1:

Input: s1 = "great", s2 = "rgeat"
Output: true
Explanation: One possible scenario applied on s1 is:
"great" --> "gr/eat" // divide at random index.
"gr/eat" --> "gr/eat" // random decision is not to swap the two substrings and keep them in order.
"gr/eat" --> "g/r / e/at" // apply the same algorithm recursively on both substrings. divide at random index each of them.
"g/r / e/at" --> "r/g / e/at" // random decision was to swap the first substring and to keep the second substring in the same order.
"r/g / e/at" --> "r/g / e/ a/t" // again apply the algorithm recursively, divide "at" to "a/t".
"r/g / e/ a/t" --> "r/g / e/ a/t" // random decision is to keep both substrings in the same order.
The algorithm stops now, and the result string is "rgeat" which is s2.
As one possible scenario led s1 to be scrambled to s2, we return true.
Example 2:

Input: s1 = "abcde", s2 = "caebd"
Output: false
*/

class Solution {
public:
    unordered_map <string,bool>mp;
    bool isScramble(string a, string b) {
      //if both the strings are equal then its true
        if(a.compare(b)==0)
        return true;
      //length can not be smaller than 1 that is it can not be an empty string 
        if(a.length()<=1)
        return false;
      //unique key to identify current combination
        string key=a+"hehe"+b;
      //memoization
        if(mp.find(key)!=mp.end())
        return mp[key];
        int n=a.length();
        bool flag=false;
      //trying all combinations from string length 1 to entire length
        for(int i=1;i<=n-1;i++){
          //2 cases
            if( (isScramble(a.substr(0,i),b.substr(n-i,i)) && isScramble(a.substr(i,n-i),b.substr(0,n-i))) || (isScramble(a.substr(0,i),b.substr(0,i)) && isScramble(a.substr(i,n-i),b.substr(i,n-i)) ) ){
                    flag=true;
                    mp[key]=flag;
                    break;
            }
        }

        return mp[key];

    }
};


//--------------------------------------------------------------------TWO CASES-------------------------------------------------------------------------
// CASE 1:  when the 1st half of string a equal 2nd half of string b and 2nd half of string a equals 1st half of string b
// CASE 2:  when the 1st half of string a equals 1st half of string b and second half of string a equals second half of string b
// the case 1 is the case where we perform the swap operation and case 2 is where we do not perform the swap operation

