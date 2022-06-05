/**
This is ofcourse the famous N-Queens problem.

speaking of conditons -
----> place 1 queen in every row
----> place 1 queen in every column
----> no queen should attack another queen (a queen can attack in 8 directions)

example:---
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]

*/



class Solution {
public:
    void solver(int col,vector<vector<string>>&ans,int n,vector<string>&board,vector<int>leftrow,vector<int>upperdiag,vector<int>lowerdiag){
        if(col==n){
            ans.push_back(board);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(leftrow[row]==0 && lowerdiag[row+col]==0 && upperdiag[n-1+col-row]==0){
                board[row][col]='Q';
                leftrow[row]=1;
                lowerdiag[row+col]=1;
                upperdiag[n-1+col-row]=1;
                solver(col+1,ans,n,board,leftrow,upperdiag,lowerdiag);
                 board[row][col]='.';
                leftrow[row]=0;
                lowerdiag[row+col]=0;
                upperdiag[n-1+col-row]=0;
                
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<int>leftrow(n,0),upperdiag(2*n-1),lowerdiag(2*n-1);
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
            board[i]=s;
        vector<vector<string>> ans;
        solver(0,ans,n,board,leftrow,upperdiag,lowerdiag);
        return ans;
    }
};



/**
-----------------------------------------------------------------NOTES (aka major takeaways)---------------------------------------------------------------------
---> as we move from one column to another we only gotta check the left side that is left row, left upper ans lower diagonal.
---> for left diagonal we check the row index if it has any queen .....basically hashing
---> for lower diagonal we check the index row+column 
---> for upper diagonal we check indexes n-1+column-row

*/
