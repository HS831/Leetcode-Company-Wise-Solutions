/* ------------------------ Game of Life ---------------
   Leetcode Question Number : 289
   Leectode Difficulty Tag : Medium
   Leetcode Problem Link : https://leetcode.com/problems/game-of-life/

---------------------------------------------------------------*/

class Solution {
public:

    // T.C. O(n^2) S.C. O(n^2)
    int live_or_dead(vector<vector<int>>&grid, int m, int n, int r, int c) {
        int neighbour = 0;
        
        if(r-1>=0)
            neighbour += grid[r-1][c];      // Vertical Up
        if(r+1<m)
            neighbour += grid[r+1][c];      // Vertical Down
        if(c-1>=0)
            neighbour += grid[r][c-1];      // Horizontal Left
        if(c+1 < n)
            neighbour += grid[r][c+1];      // Horizontal Right
        
        if(r-1>=0 && c-1>=0)
            neighbour += grid[r-1][c-1];    // Left Diagonal Up
        
        if(r-1>=0 && c+1<n)
            neighbour += grid[r-1][c+1];    // Right Diagonal Up
        
        if(r + 1 < m && c + 1 < n)
            neighbour += grid[r+1][c+1];    // Right Diagonal Down
        
        if(r+1<m && c-1>=0)
            neighbour += grid[r+1][c-1];    // Left Diagonal Down
        
        return neighbour;                   // Returning total number of neighbours
        
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<int>>grid(m, vector<int>(n, 0));
        grid = board;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int cnt_of_negh = live_or_dead(grid, m, n, i, j);
                if(board[i][j] == 1) {
                    
                    if(cnt_of_negh < 2 || cnt_of_negh >3 )
                        board[i][j] = 0;
                }
                else {
                    if(cnt_of_negh == 3)
                        board[i][j] = 1;
                }
            }
        }
    }
};