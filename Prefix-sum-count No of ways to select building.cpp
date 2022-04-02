/**
LEETCODE 2222

You are given a 0-indexed binary string s which represents the types of buildings along a street where:

s[i] = '0' denotes that the ith building is an office and
s[i] = '1' denotes that the ith building is a restaurant.
As a city official, you would like to select 3 buildings for random inspection. However, to ensure variety, no two consecutive buildings out of the selected buildings can be of the same type.

For example, given s = "001101", we cannot select the 1st, 3rd, and 5th buildings as that would form "011" which is not allowed due to having two consecutive buildings of the same type.
Return the number of valid ways to select 3 buildings.

 Example
 
 Input: s = "001101"
Output: 6
Explanation: 
The following sets of indices selected are valid:
- [0,2,4] from "001101" forms "010"
- [0,3,4] from "001101" forms "010"
- [1,2,4] from "001101" forms "010"
- [1,3,4] from "001101" forms "010"
- [2,4,5] from "001101" forms "101"
- [3,4,5] from "001101" forms "101"
No other selection is valid. Thus, there are 6 total ways.

*/

class Solution {
public:
    long long numberOfWays(string s) {
        long long int n=s.length();
        vector<pair<long long int,long long int>> pre(n);
        long long int one=0,zero=0;
        for(int i=0;i<n;i++){
            pre[i]={zero,one};
            if(s[i]=='0') zero++;
            else one++;
        }
        long long int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0'){
                ans+=pre[i].second*(one-pre[i].second);
            }
            else ans+=pre[i].first*(zero-pre[i].first);
        }
        return ans;
    }
};

/**
---------------------------------------------------------------------------NOTES-------------------------------------------------------------------------
1)we are using a vector pair to store the number of ones and zeros that come before each index
2) run a loop through the entire string and store the number of ones and zeros for each and increment accordingly
3)now in another loop for the string calculate answer
4) if the ith index is 0 then multiply the total 1s before and after the ith index
5) if ith index is 1 then multiply total 0s before and after i
6) keep adding step 4 and 5 to ans 
7) return ans
*/
