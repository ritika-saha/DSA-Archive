//-------------------------------------------------------------------GRAPH----------------------------------------------------------------------------
/**
Given a binary grid of n*m. Find the distance of the nearest 1 in the grid for each cell.
The distance is calculated as |i1  - i2| + |j1 - j2|, where i1, j1 are the row number and column number of the current cell, and i2, j2 are
the row number and column number of the nearest cell having value 1.
 

Example 1:

Input: grid = {{0,1,1,0},{1,1,0,0},{0,0,1,1}}
Output: {{1,0,0,1},{0,0,1,1},{1,1,0,0}}
Explanation: The grid is-
0 1 1 0 
1 1 0 0 
0 0 1 1 
0's at (0,0), (0,3), (1,2), (1,3), (2,0) and
(2,1) are at a distance of 1 from 1's at (0,1),
(0,2), (0,2), (2,3), (1,0) and (1,1)
respectively.
*/


class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int m=grid.size();
	    int n=grid[0].size();
    //VISITED ARRAY 
	    vector<vector<int>>vis(m,vector<int>(n,0));
    //ARRAY STORING THE SHORTEST DISTANCE TO NEAREST 1 FROM THAT PARTICULAR NODE
	    vector<vector<int>>dist(m,vector<int>(n,0));
    //{{ROW,COL},DISTANCE}
	    queue<pair<pair<int,int>,int>>q;
    
    //LOOP TO INSERT 1S IN THE GIVEN GRID INTO THE QUEUE TO START THE CALCULATION OF DFS FROM THEM
	    for(int i=0;i<m;i++){
	        for(int j=0;j<n;j++){
	            if(grid[i][j]==1){
	                vis[i][j]=1;
	                q.push({{i,j},0});
	            }
	            else
	            vis[i][j]=0;
	        }
	    }
	    int delrow[]={0,+1,0,-1};
	    int delcol[]={+1,0,-1,0};
    
	    while(q.empty()==false){
	        int r=q.front().first.first;
	        int c=q.front().first.second;
	        int d=q.front().second;
        //STORING THE DISTANCE FOR THE CURRENT NODE
	        dist[r][c]=d;
	        q.pop();
        //SINCE WE'VE FOUND THE DISTANCE FOR THE PARTICULAR NODE NOW THE DISTANCE FROM THAT NODE TO ALL OTHER NODES ADJACENT TO IT WILL BE 1 MORE THAN IT
	        for(int i=0;i<4;i++){
	            int nr=r+delrow[i];
	            int nc=c+delcol[i];
	            if(nr>=0 && nr<m && nc>=0 && nc<n && vis[nr][nc]==0){
                //INSERTING THE NODES WITH A DISTANCE INCREASED BY 1
	                q.push({{nr,nc},d+1});
	                vis[nr][nc]=1;
	            }
	        }
	    }
	    return dist;
	}
};
