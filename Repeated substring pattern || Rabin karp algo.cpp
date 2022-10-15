/**
Given two strings a and b, return the minimum number of times you should repeat string a so that string b is a substring of it. If it is impossible 
for b​​​​​​ to be a substring of a after repeating it, return -1.

Notice: string "abc" repeated 0 times is "", repeated 1 time is "abc" and repeated 2 times is "abcabc".

 

Example 1:

Input: a = "abcd", b = "cdabcdab"
Output: 3
Explanation: We return 3 because by repeating a three times "abcdabcdabcd", b is a substring of it.
*/

class Solution {
private:
  //standard base
    int BASE = 1000000;
public:
    int repeatedStringMatch(string A, string B) {
        if(A == B) return 1;
        int count = 1;
        string source = A;
      //adding source until length is smaller
        while(source.size() < B.size()){
            count++;
            source+=A;
        }
      //if equal then number of repeatations is count
        if(source == B) return count;
      
      //if not equal we check using rabin karp incase pattern is differnt but is substring
        if(Rabin_Karp(source,B) != -1) return count;
      
      //checking using another time
        if(Rabin_Karp(source+A,B) != -1) return count+1;
      
      //if substring cant be formed
        return -1;
    }
  
  
  //----------------------------------------------------------------RABIN KARP PATTERN MATCHING ---------------------------------------------------------
    int Rabin_Karp(string source, string target){
        if(source == "" or target == "") return -1;
        int m = target.size();
        int power = 1;
      
      
        for(int i = 0;i<m;i++){
            power = (power*31)%BASE;
        }
        int targetCode = 0;
        for(int i = 0;i<m;i++){
            targetCode = (targetCode*31+target[i])%BASE;
        }
        int hashCode = 0;
        for(int i = 0;i<source.size();i++){
            hashCode = (hashCode*31 + source[i])%BASE;
            if(i<m-1) continue;
            if(i>=m){
                hashCode = (hashCode-source[i-m]*power)%BASE;
            }
            if(hashCode<0)
                hashCode+=BASE;
            if(hashCode == targetCode){
                if(source.substr(i-m+1,m) == target)
                    return i-m+1;
            }
        }
        return -1;
    }
};
