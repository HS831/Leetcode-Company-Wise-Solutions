/* ------------------------ Number of Islandss ---------------
   Leetcode Question Number : 200
   Leectode Difficulty Tag : Medium
   Leetcode Problem Link : https://leetcode.com/problems/number-of-islands/

---------------------------------------------------------------*/


class Solution {
public:
    bool isValid(int i, int j, int m, int n) {
        if(i >= m || i<0 || j >= n || j<0)
            return false;
        
        return true;
    }
    
    int bfs(int r, int c, int m, int n, vector<vector<char>>&grid) {
        
        queue<pair<int,int>>q;
        q.push({r, c});
        
        grid[r][c] = '0';
        vector<pair<int,int>>directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        int ans = 0;
        
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            for(auto dir : directions) {
                int i = curr.first + dir.first;
                int j = curr.second + dir.second;
                
                if(isValid(i, j, m, n) && grid[i][j] == '1') {
                    q.push({i, j});
                    grid[i][j] = '0';
                }
             }
        }
        
         ans++;
        return ans;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int ans = 0;
        for(int i=0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == '1') {
                  ans += bfs(i, j, m, n, grid);
                }
            }
        }
        
        return ans;
    }
};
