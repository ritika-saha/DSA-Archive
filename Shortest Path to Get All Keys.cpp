/**
You are given an m x n grid grid where:

'.' is an empty cell.
'#' is a wall.
'@' is the starting point.
Lowercase letters represent keys.
Uppercase letters represent locks.
You start at the starting point and one move consists of walking one space in one of the four cardinal directions. You cannot walk outside the grid, or walk into a wall.

If you walk over a key, you can pick it up and you cannot walk over a lock unless you have its corresponding key.

For some 1 <= k <= 6, there is exactly one lowercase and one uppercase letter of the first k letters of the English alphabet in the grid. This means that there is 
exactly one key for each lock, and one lock for each key; and also that the letters used to represent the keys and locks were chosen in the same order as the English 
alphabet.

Return the lowest number of moves to acquire all keys. If it is impossible, return -1.

 

Example 1:


Input: grid = ["@.a..","###.#","b.A.B"]
Output: 8
Explanation: Note that the goal is to obtain all the keys not to open all the locks.
*/


class Solution {
    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, -1, 1};

    // Checking if new coordinates are going out of grid on not
    bool isValid(int x, int y, int rows, int cols) {
        return (x>=0 and x<rows and y>=0 and y<cols);
    }

    // Function to check whether current char is lowercase
    bool isLowerCase(char ch) {
        return (ch>='a' and ch<='z');
    }

    // Function to check whether current char is uppercase
    bool isUpperCase(char ch) {
        return (ch>='A' and ch<='Z');
    }


    // Return number of set bits in number
    int getNumberOfBits(int mask)
    {
        int ans = 0;

        while (mask != 0) {
            ans += (mask & 1);
            mask >>= 1; // Right Shift (same as divide by 2).
        }

        return ans;
    }

public:

    int shortestPathAllKeys(vector<string>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        int keys = 0;
        
        // {i, j, mask}
        queue<vector<int>> q;

        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {

                if(isLowerCase(grid[i][j])) {
                    keys++;
                }

                if(grid[i][j] == '@') {
                    q.push({i, j, 0});
                }
            }
        }
        set<vector<int>> vis; // {i,j, currMask}
        int steps = 0;
        
        while(not q.empty()) {
            int sz = q.size();

            for(int i=0; i<sz; i++) {

                vector<int> currCell = q.front();
                q.pop();

                int x = currCell[0];
                int y = currCell[1];
                int mask = currCell[2];

                // If we have collected all keys the return steps 
                if(getNumberOfBits(mask) == keys){
                    return steps;
                }

                for(int k=0; k<4; k++){
                    int newX = x + dx[k];
                    int newY = y + dy[k];

                    if (isValid(newX, newY, rows, cols) == false or grid[newX][newY] == '#') {
                        continue;
                    }

                    char newChar = grid[newX][newY];
                    int newMask = mask;

                    // If new char is lowercase, means we find a key so add it to our mask.
                    if (isLowerCase(newChar)) {
                        newMask |= (1 << (newChar - 'a'));
                    }

                    // If we have already visited current cell and mask is not updated then skip the current cell otherwise check if current lock (capital letter) key is present or not. 
                    if(
                        vis.find({newX, newY, newMask}) != vis.end() or
                      (isUpperCase(newChar) and !(mask&(1<<(newChar-'A'))))
                      )
                            continue;
                    
                    // Lastly push new char and newmask
                    q.push({newX, newY, newMask});
                    vis.insert({newX, newY, newMask});
                }
            }

            // Increase steps at each iteration
            steps++;
        }

        return -1;
    }
};
