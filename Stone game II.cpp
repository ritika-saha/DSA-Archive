//-----------------------------------------------------GAME THEORY------------------------------------------------------

/**
Alice and Bob continue their games with piles of stones.  There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].  The objective of the game is to end with the most stones. 

Alice and Bob take turns, with Alice starting first.  Initially, M = 1.

On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M.  Then, we set M = max(M, X).

The game continues until all the stones have been taken.

Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.

 

Example 1:

Input: piles = [2,7,9,4,4]
Output: 10
Explanation:  If Alice takes one pile at the beginning, Bob takes two piles, then Alice takes 2 piles again. Alice can get 2 + 4 + 4 = 10 piles in total. If Alice takes two piles at the beginning, then Bob can take all three piles left. In this case, Alice get 2 + 7 = 9 piles in total. So we return 10 since it's larger. 
Example 2:

Input: piles = [1,2,3,4,5,100]
Output: 104
*/

class Solution {
public:
//3d dp cuz there are three changing parameters - m,start and turn
     int dp[101][101][101];
   int stonesAlice(vector<int>&piles,int m,int start,int turn){
       if(start==piles.size())
       return 0;
       int currtotal=0;
       //initializing ans according to turn cuz min and max are  there for different turns
       int ans=(turn==0)?0:INT_MAX;
       //top down memoization
       if(dp[m][start][turn]!=-1) return dp[m][start][turn];
       //according to question piles can be chosen as 1<=x<=2*m
       for(int x=1;x<=(m*2);x++){
           //calculating the current index
           int currind=start+x-1;
           if(currind>=piles.size())
           break;
           currtotal+=piles[currind];
           //cooperative game playing agent
           if(turn==0){
               int nextalicetotal=stonesAlice(piles,max(x,m),currind+1,1);
               //adding to the current total for alice
               int total=currtotal+nextalicetotal;
               ans=max(total,ans); //alice tries to maximize
           }
           else{
               int nextalicetotal=stonesAlice(piles,max(x,m),currind+1,0);
               //not adding to alice total but minimizing the answer
               ans=min(ans,nextalicetotal); //bob tries to minimize
           }
       }
       return dp[m][start][turn]=ans;
   }
    int stoneGameII(vector<int>& piles) {
        int m=1;
         int totalElements = sizeof(dp) / sizeof(dp[0][0][0]);
         //filling the 3d dp
        fill_n(reinterpret_cast<int*>(dp), totalElements, -1);
        return stonesAlice(piles,m,0,0);

    }
};
