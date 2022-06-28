/* ------------------------ Minimum Path Sum ---------------
   Leetcode Question Number : 64
   Leectode Difficulty Tag : Medium
   Leetcode Problem Link : https://leetcode.com/problems/minimum-path-sum/

---------------------------------------------------------------*/

class Solution {
public:
    /* ------------------------------ RECURSION + MEMOIZATION ----------------------------------
        In this question we have to find minimum sum of elements if we are travelling from
        top-left corner of grid to bottom - right corner of grid i.e from (0 , 0) to (m-1, n-1)
        
        The path through which we can travel is also defined and we have been given two choices
        for any particular point of time.
            1st choice : We can move down from current position ( cannot change the column ).
            2nd choice : We can move right from current position ( cannot change row ).
            
        Therefore, we can see a pattern of Knapsack here ( like 0 and 1 choice) and since it is
        a optimization problem, we can apply dynamic programming to it.
        
        The most efficient way of approaching any DP problem is to figure out its recurrence
        relation and DP state.
        For this question we can clearly see our recurrence relation / DP state :
            
            (Top - Down approach)
            
            a) dp(grid, r, c): dp(grid, r + 1, c);
            b) dp(grid, r, c) : dp(grid, r, c+1);
            
            c) ans = min(a, b) + grid[r][c];
            
        After writing recursive code, we can see that two variables/state are changing so 
        to memoize it we can use 2D vector.
        
    ----------------------------------------------------------------------------------------*/
    
    int m,n;
    vector<vector<int>>memo;
    int dp(vector<vector<int>>&grid, int r, int c) {
        if( r>=m || c>=n )
            return INT_MAX;
        
        if(r == m-1 && c == n-1)
            return grid[r][c];
        
        if(memo[r][c] != -1)
            return memo[r][c];
        
        int ans = INT_MAX;
        int down = dp(grid, r+1, c);
        int right = dp(grid, r, c+1);
        
        ans = min(down, right) + grid[r][c];
        
        return memo[r][c] = ans;
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        memo.resize(m+1, vector<int>(n+1, -1));
        return dp(grid, 0, 0);
    }
};