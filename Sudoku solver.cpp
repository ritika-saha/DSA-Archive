/**

Ofcourse we gotta solve the given sudoku

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

*/


class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
      solve(board);  
    }
    
    bool solve(vector<vector<char>>&board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    for(char k='1';k<='9';k++){
                        if(isValid(board,i,j,k)){
                            board[i][j]=k;
                            
                        if(solve(board))
                            return true; //by recursion checks if inserting k still keeps the sudoku valid and consicutive trues will keep the recursion running for the currently running pattern
                            else
                             board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValid(vector<vector<char>>board,int row,int col,char k){
        for(int i=0;i<9;i++){
            if(board[row][i]==k)
                return false;
            if(board[i][col]==k)
                return false;
            if(board[(3*(row/3))+(i/3)][3*(col/3)+(i%3)]==k)
                return false;
        }
        return true;
    }
};
