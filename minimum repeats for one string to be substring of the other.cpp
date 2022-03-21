/**GFG problem
Given two strings A and B. Find minimum number of times A has to be repeated such that B is a Substring of it. If B can never be a substring then return -1.

 Input:
A = "abcd"
B = "cdabcdab"
Output:
3
Explanation:
Repeating A three times (“abcdabcdabcd”),
B is a substring of it. B is not a substring
of A when it is repeated less than 3 times.

Input:
A = "ab"
B = "cab"
Output :
-1
Explanation:
No matter how many times we repeat A, we can't
get a string such that B is a substring of it.
*/

class Solution {
  public:
     bool isSafe(string a, string b) {
        // code here
        int freq[26] = {0};
        for(int i = 0; i < a.length(); i++) {
            freq[a[i]-'a']++;
        }
        
        for(int i = 0; i < b.length(); i++) {
            if(freq[b[i] - 'a'] == 0)
                return false;
        }
        return true;
    }
    
    int minRepeats(string a, string b) {
        string s = a;
        int ans = 1;
        if(isSafe(a,b)){
            while(s.find(b) == string::npos){
                s += a;
                ans++;
                if(s.length() > 2*b.length()) return -1;
            }
        }
        else
            return -1;
    
        return ans;
    }

};


/**
----------------------------------------------------------------------------NOTES-----------------------------------------------------------------------------
1)here we have ran a loop while the dummy string length is lesser than the second string length while we keep appending the 1st string to it
2)if the while condition satisfies then we keep on increasing the count which will be the answer eventually
3)if at any point the dummy string length is greater than the twice of length of second string then we return -1 as the condition isn't satisfied 
4) before entering the while loop we check whether the elements in the second loop consists of only combinations of the elements in 1st string 
5) otherwise return -1


*/
