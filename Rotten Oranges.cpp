//------------------------------------------------------------------GRAPH----------------------------------------------------------------------------
/**
Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

We have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], 
[i,j-1], [i,j+1] (up, down, left and right) in unit time. 
 

Example 1:

Input: grid = {{0,1,2},{0,1,2},{2,1,1}}
Output: 1
Explanation: The grid is-
0 1 2
0 1 2
2 1 1
Oranges at positions (0,2), (1,2), (2,0)
will rot oranges at (0,1), (1,1), (2,2) and 
(2,1) in unit time.
*/

class Solution
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
      
      //KEEPING TRACK OF NUMBER OF FRESH ORANGES
        int fresh=0;
        int m=grid.size();
        int n=grid[0].size();
      
      // {{ROW,COL},TIME_TILL_THAt_NODE_OF _THAT_LEVEL
        queue<pair<pair<int,int>,int>>q;
      
      //KEEPING TRACK OF ALL THE NODES THAT ARE ALREADY ROTTEN AND NEWLY ROTTEN
        vector<vector<int>>vis(m,vector<int>(n,0));
        
      //MARKING ROTTEN ORANGES IN VISTIED ARRAY AND COUNTING THE NUMBER OF FRESH ORANGES ORIGINALLY PRESENT
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    vis[i][j]=2;
                    q.push({{i,j},0});
                }
                if(grid[i][j]==1)
                fresh++;
            }
        }
        
        int cnt=0,ans=0;
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1}; 
        
      
       while(q.empty()==false){
           int r=q.front().first.first;
           int c=q.front().first.second;
           int t=q.front().second;
         
         //MAXIMUM TIME WILL BE CONSIDERED
           ans=max(ans,t);
           q.pop();
         //ROTTENING IN ALL 4 DIRECTIONS FOR CURRENT NODE
           for(int i=0;i<4;i++){
               int nr=r+delRow[i];
               int nc=c+delCol[i];
               if(nr>=0 && nr<m && nc>=0 && nc<n && vis[nr][nc]!=2 && grid[nr][nc]==1){
                   vis[nr][nc]=2;
                   q.push({{nr,nc},t+1});
                 //COUNTING NUMBER OF FRESH ORNAGE THAT ARE ROTTEN IN THIS BFS
                   cnt++;
               }
           }
       }
      
      
      //IF CNT OF FRESH ORNAGES TOUCHED IN THE BFS IS NOT EQUAL TO THE NUMBER OF FRESH ORANGES ORIGINALLY  PRESNENT THAT MEANS ALL ORANGES ARE NOT ROTTEN
      //EVEN AFTER THE BFS SO WE RETURN -1
       if(cnt!=fresh) return -1;
       
       return ans;
        
    }
};
