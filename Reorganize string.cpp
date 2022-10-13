/**
Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.

 

Example 1:

Input: s = "aab"
Output: "aba"
Example 2:

Input: s = "aaab"
Output: ""
*/

class Solution {
public:
    string reorganizeString(string S) {
          string res="";
      //strore the frequency of each character 
        unordered_map<char,int> mp;
      //to store and retrieve 2 chars with greatest frequency 
        priority_queue<pair<int,char>>pq;
        
        for(auto s: S)
            mp[s]+=1;
        
        for(auto m: mp)
            pq.push(make_pair(m.second,m.first));
        
      //loop until only one element is remaining
        while(pq.size()>1){
          //1st greatest
            auto top1= pq.top();
            pq.pop();
          
          //second greatest
            auto top2 = pq.top();
            pq.pop();
            
            res+=top1.second;
            res+=top2.second;
            
          //reducing frequency
            top1.first -=1;
            top2.first -= 1;
            
          //adding them back if there are more of the same element remaining
            if(top1.first > 0)
                pq.push(top1);
            
            if(top2.first > 0)
                pq.push(top2);
        }
        
      //if the last element remaining has frequency more than 1 it means a string can not be formed that follows the given condition
        if(!pq.empty()){
            if(pq.top().first > 1)
                return "";
            
            else
                res+=pq.top().second;
        }
        
        return res;
        
    }
};
