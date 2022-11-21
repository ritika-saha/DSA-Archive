/**

You are given an m x n matrix maze (0-indexed) with empty cells (represented as '.') and walls (represented as '+'). You are also given the entrance of the maze, 
where entrance = [entrancerow, entrancecol] denotes the row and column of the cell you are initially standing at.

In one step, you can move one cell up, down, left, or right. You cannot step into a cell with a wall, and you cannot step outside the maze. Your goal is to find 
the nearest exit from the entrance. An exit is defined as an empty cell that is at the border of the maze. The entrance does not count as an exit.

Return the number of steps in the shortest path from the entrance to the nearest exit, or -1 if no such path exists.

 

Example 1:


Input: maze = [["+","+",".","+"],[".",".",".","+"],["+","+","+","."]], entrance = [1,2]
Output: 1
Explanation: There are 3 exits in this maze at [1,0], [0,2], and [2,3].
Initially, you are at the entrance cell [1,2].
- You can reach [1,0] by moving 2 steps left.
- You can reach [0,2] by moving 1 step up.
It is impossible to reach [2,3] from the entrance.
Thus, the nearest exit is [0,2], which is 1 step away.
*/

class Solution {
private:
    vector<int> dx = {0, -1, 1, 0}, dy = {1, 0, 0, -1}; // 4 direction to move
    int m, n; // to store row and column

private:
    // check for valid index
    bool isValid(int x, int y) {
        return x >= 0 and y >= 0 and x < m and y < n;
    }

    int find(vector<vector<char>> &maze, int st1, int st2) {
        // get the row and col
        m = maze.size(), n = maze[0].size();
        int mn = INT_MAX;

        // init the vis array and queue
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int, int>>q;

        // mark the curent user cell to visited and push position in queue
        vis[st1][st2] = 1;
        q.push({st1, st2});

        int move = 0;

        // until queue is empty do move in 4 direction untill you reach exit
        while (!q.empty()) {
            // get the queue size
            int s = q.size();
            //checking for boundary at every step rather than checking at next level to avoid the TLE
            while (s--) {
                // take the first element from queue
                auto cur = q.front();
                q.pop(); // remove it

                // check if person reach to any of the boundary and also check if person making move to reach boundary i.e person doesn't staying at boundary initially
                if ((cur.first != st1 or cur.second != st2) and (cur.first == 0 or cur.first == m - 1 or cur.second == 0 or cur.second == n - 1)) {
                    return move;
                }
                
                // check in 4 dir
                for (int i = 0; i < 4; ++i) {
                    // get the new adj row and col
                    int x = cur.first + dx[i];
                    int y = cur.second + dy[i];
                    // if the new position is not visited or it should be a valid position also it's not a wall then make moves
                    if (isValid(x, y) and !vis[x][y] and maze[x][y] == '.') {
                        vis[x][y] = 1;
                        q.push({x, y});
                    }
                }
            }
            // increment the moves
            move++;
        }
        
        // if not able to reach boundary
        return -1;
    }
    
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        // pass the maze and starting position
        return find(maze, entrance[0], entrance[1]);
    }
};
