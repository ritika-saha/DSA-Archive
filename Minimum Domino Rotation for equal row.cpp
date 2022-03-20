/**
LeetCode 1007: Minimum domino rotation for equal row (greedy)

In a row of dominoes, tops[i] and bottoms[i] represent the top and bottom halves of the ith domino. (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)

We may rotate the ith domino, so that tops[i] and bottoms[i] swap values.

Return the minimum number of rotations so that all the values in tops are the same, or all the values in bottoms are the same.

If it cannot be done, return -1.

eg--Input: tops = [2,1,2,4,2,2], bottoms = [5,2,6,2,3,2]
Output: 2
Explanation: 
The first figure represents the dominoes as given by tops and bottoms: before we do any rotations.
If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2.
*/

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottom) {
        int n=tops.size();
        vector<int> ctop(7,0);
        vector<int>cbottom(7,0);
        vector<int> same(7,0);
        for(int i=0;i<n;i++){
            ctop[tops[i]]++;
            cbottom[bottom[i]]++;
            if(tops[i]==bottom[i])
                same[tops[i]]++;
        }
        for(int i=0;i<7;i++){
            if(ctop[i]+cbottom[i]-same[i]==n)
                return n-max(ctop[i],cbottom[i]);
        }
        return -1;
        
    }
};



/**
--------------------------------------------------------------NOTES:---------------------------------------------------------------------------------------
Here i have
1)calculated the frequency of each element of the top and bottom arrays 
2)also calculated the frequency of the elemeants that are in the same index
3)in the second loop we check for a condition where the sum of the frequency of an element in the top as well as the bottom array minus the same index frequency is 
equal to the size of array
4) if we find such condition it means the array can be swapped into the equal one that is the required answer
*/
