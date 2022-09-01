/**
--------------------------------------------------------------recursion and memoization on matrix------------------------------------------------------------------

There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges,
and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above 
sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's
height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.


Example 1:


Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
Explanation: The following cells can flow to the Pacific and Atlantic oceans, as shown below:
[0,4]: [0,4] -> Pacific Ocean 
       [0,4] -> Atlantic Ocean
[1,3]: [1,3] -> [0,3] -> Pacific Ocean 
       [1,3] -> [1,4] -> Atlantic Ocean
[1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean 
       [1,4] -> Atlantic Ocean
[2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean 
       [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
[3,0]: [3,0] -> Pacific Ocean 
       [3,0] -> [4,0] -> Atlantic Ocean
[3,1]: [3,1] -> [3,0] -> Pacific Ocean 
       [3,1] -> [4,1] -> Atlantic Ocean
[4,0]: [4,0] -> Pacific Ocean 
       [4,0] -> Atlantic Ocean



*/


class Solution {
public:
    int m,n;
    
    bool s(vector<vector<bool>>& ocean, int i, int j, vector<vector<int>>& ht){
        //checking for out of bound and loop condition
        if (i<0 || j<0 || i==m || j==n || ht[i][j]==100004) return false;
      
      //memoization-- if that particular part has stored true already that means the path ultimately leads to ocean
        if (ocean[i][j]) return true;
        
        int k = ht[i][j];
      //storing a larger value to check if that path has been already visited and to avoid loop condition
        ht[i][j]=100004;
        bool zz = false;
      //checking for north
        if (i>0 && ht[i-1][j]<=k)   zz = zz || s(ocean,i-1,j,ht);
      //checking west
        if (j>0 && ht[i][j-1]<=k)   zz = zz || s(ocean,i,j-1,ht);
      //checking for south
        if (i<m-1 && ht[i+1][j]<=k) zz = zz || s(ocean,i+1,j,ht);
      //checking for east
        if (j<n-1 && ht[i][j+1]<=k) zz = zz || s(ocean,i,j+1,ht);
        
      //storing if it reaches oceans after the recursion bool value
        ocean[i][j]=zz;
      //backtracking and re stroing the previous height value so that that node can be revisited
        ht[i][j]=k;
        return zz;
        
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& ht) {
        m = ht.size();
        n = ht[0].size();
        vector<vector<bool>> pac(m, vector<bool> (n,false));
        vector<vector<bool>> atl(m, vector<bool> (n,false));
      
      //marking the nodes that are adjacent to the ocean is true because we can obviously reach oceans from them
        for (int i=0; i<m; i++){
            pac[i][0]=true;
            atl[i][n-1]=true;
        }
        for (int i=0; i<n; i++){
            pac[0][i]=true;
            atl[m-1][i]=true;
        }
      
      
        vector<vector<int>> res;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
              //recusrion call for both pacific and atlantic and if both returns true we store that node in answer
                if (s(pac,i,j,ht) && s(atl,i,j,ht)) res.push_back({i,j});
            }
        }return res;
    }
};
