/**
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
 

Example 1:


Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
      //SET TO STORE UNIQUE COMBINATIONS
        unordered_set<string>st;
      //TRAVERSING THE BOARD
      
      //----------------------------------------box number for any cell [i, j] is (i / 3) * + j / 3, taking (3 * 3) boxes------------------------------------------
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                  //IF THAT PARTICULAR NUMBER PATTERN IN A PARTICULAR ROW IS ALREADY PRESENT
                if(st.count("row"+to_string(i)+"*"+to_string(board[i][j])))
                    return false;
                  //IF THE PARTICULAR NUMBER IS ALREADY PRESENT IN THE PARTICULAR COLUMN
                if(st.count("col"+to_string(j)+"*"+to_string(board[i][j])))
                    return false;
                  //IF THE PARTICULAR NUMBER IS ALREADY PRESENT IN THE PARTICULAR BOX
                if(st.count("box"+to_string((i/3)*3+(j/3))+"*"+to_string(board[i][j])))
                    return false;
                
                  //INSERTING UNIQUE PATTERN FOR THAT PARTICULAR NUMBER IN A PARTICULAR ROW AS A QUIQUE STRING WHICH CAN BE DONE USING ROW+ THE NUMBER'S INDEX + 
                  //UNIQUE SYMBOL + THE BOARD NUMBER 
                  
                st.insert("row"+to_string(i)+"*"+to_string(board[i][j]));
                st.insert("col"+to_string(j)+"*"+to_string(board[i][j]));
                st.insert("box"+to_string((i/3)*3+(j/3))+"*"+to_string(board[i][j]));
                }
            }
        }
        return true;
    }
};
