/**
Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance 
to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.

The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.

 

Example 1:


Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
Output: 2
Explanation: The cell (1, 1) is as far as possible from all the land with distance 2.
*/

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        vector<vector<int>>visited=grid; //not manipulating the given input is a good practice
        queue<pair<int,int>>q; //pushing all the land coordinates in the queue
        int n=grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                q.push({i,j});
            }
        }
        int distance=-1; //distance -1 so that 0 distance is also considered
        if(q.size()==n*n||q.empty()) //is queue is empty means no land or queue is all land then no valid answer so return -1
        return -1;
        
      //considering bfs in all 4 directions 
        int delx[]={-1,0,1,0};
        int dely[]={0,1,0,-1};
      //performing bfs on the lands
        while(q.empty()==false){
            int size=q.size();
            while(size--){
                auto [r,c]=q.front();
                q.pop();
              //going on all 4 directins of the current land and marking it visited and pushing in  queue if it is water
                for(int i=0;i<4;i++){
                    int nr=r+delx[i];
                    int nc=c+dely[i];
                    if(nr>=0 && nc>=0 && nr<n && nc<n && visited[nr][nc]==0){
                        visited[nr][nc]=1;
                        q.push({nr,nc});
                    }
                }
            }
          //THE ANSWER IS THE NUMBER OF TIMES THE BFS RUNS THAT IS THE MAX DISTANCE WE HAVE TO GO FROM LAND TO WATER
            distance++;
        }
        return distance;
    }
};
