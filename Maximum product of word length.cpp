/**

----------------------------------------------------------USING BIT MANIPULATION------------------------------------- 

Given a string array words, return the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters.
If no such two words exist, return 0.


Example :

Input: words = ["a","ab","abc","d","cd","bcd","abcd"]
Output: 4
Explanation: The two words can be "ab", "cd".
Example :

Input: words = ["a","aa","aaa","aaaa"]
Output: 0
Explanation: No such pair of words.




*/


class Solution {
public:
    int getstate(string s)//returns the decimal rep of the set bits of each string
    {
        int state=0;
        for(auto it:s){
            state |=1<<(it-'a');
        }
        return state;
    }
    
    int maxProduct(vector<string>& words) {
     int state[words.size()];
        for(int i=0;i<words.size();i++){
            state[i]=getstate(words[i]); //stores the state of each string
        }
        
        int maxi=INT_MIN;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if((state[i]&state[j])==0){ // if the strings are different the & op will give 0
                    int ans=words[i].length()*words[j].length(); //storing the possible answer
                    if(maxi<ans)
                        maxi=ans;// storing the maximum answer
                }
            }
        }
        if(maxi==INT_MIN)
            return  0;
        return maxi;
    }
};

/**
---------------------------------------------------------------------------notes--------------------------------------------------------------------------------
getstate sets the bits of the every character present in that string to 1 and returns the cumulative binary to decimal ... 
eg - abd will become 1101 (places 0,1,2,3) which is 13 


*/
