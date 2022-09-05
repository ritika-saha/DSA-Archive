/**
-----------------------------------------------------------------------Backtracking------------------------------------------------------------------------------

You are given a 0-indexed m x n binary matrix mat and an integer cols, which denotes the number of columns you must choose.

A row is covered by a set of columns if each cell in the row that has a value of 1 also lies in one of the columns of the chosen set.

Return the maximum number of rows that can be covered by a set of cols columns.

 

Example 1:



Input: mat = [[0,0,0],[1,0,1],[0,1,1],[0,0,1]], cols = 2
Output: 3
Explanation:
As shown in the diagram above, one possible way of covering 3 rows is by selecting the 0th and 2nd columns.
It can be shown that no more than 3 rows can be covered, so we return 3.





*/

class Solution {
public:
    int maxi = INT_MIN;
    void helper(vector<vector<int>> &mat , int m , int n , int cols , int idx , vector<int> &vis){
        if(cols == 0 or idx==n){
            int cnt = 0;
            for(int p = 0 ; p < m ; p++){
                bool check = true;
                for(int q = 0 ; q < n; q++){
                    // if cell is 1 and not visited then we cannot take this row
                    if(mat[p][q] == 1 and vis[q] == 0){
                        check = false;
                        break;
                    }
                }
                if(check) cnt++;
            }
            maxi = max(maxi,cnt);
            return;
        }
        
        // picking idx th column and marking column as visited
        vis[idx]=1;
      
      //pick
        helper(mat,m,n,cols-1,idx+1,vis);
      
      //backtracking 
        vis[idx]=0;
        
        // not picking
        helper(mat,m,n,cols,idx+1,vis);
        return;
        
    }
    int maximumRows(vector<vector<int>>& mat, int cols) {
        int m = mat.size();
        int n = mat[0].size();
        
      //visited array to keep a track o rows that are visited
        vector<int> vis(n);
        
        helper(mat,m,n,cols,0,vis);
        return maxi;
    }
};
