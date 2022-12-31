//-------------------------------------LEETCODE HARD-----------------------RECURSION & BACKTRACKING ------------------------------------------------------------

/**
You are given an m x n integer array grid where grid[i][j] could be:

1 representing the starting square. There is exactly one starting square.
2 representing the ending square. There is exactly one ending square.
0 representing empty squares we can walk over.
-1 representing obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

 

Example 1:


Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
*/


class Solution {
    // Dimensions 
    int m, n;

    // Direction Vectors
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

public:
    // function to check for the validity of CELLij
    bool isvalid(int i, int j)
    {
        return i >= 0 and j >= 0 and i < m and j < n;
    }

    int dfs(int i, int j, int left, pair<int, int> dest, vector<vector<int>> &grid)
    {
        // Base case
        if (left == -1 and pair<int, int>(i, j) == dest)
            return 1;

        // Mark visited
        grid[i][j] = -1;

        int ans = 0;
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];

            // Add up all possibilities to answer
            if (isvalid(x, y) and grid[x][y] != -1)
                ans += dfs(x, y, left - 1, dest, grid);
        }

        // Backtrack
        grid[i][j] = 0;

        return ans;
    }

    int uniquePathsIII(vector<vector<int>> &grid)
    {
        m = grid.size(), n = grid[0].size();

        pair<int, int> src, dest;
        int empty = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                    empty++;
                if (grid[i][j] == 1)
                    src = {i, j};
                if (grid[i][j] == 2)
                    dest = {i, j};
            }
        }

        return dfs(src.first, src.second, empty, dest, grid);
    }
};
