/* ------------------------ Knight Probability in Chessboard ---------------
   Leetcode Question Number : 688
   Leectode Difficulty Tag : Medium
   Leetcode Problem Link : https://leetcode.com/problems/knight-probability-in-chessboard/

---------------------------------------------------------------*/

class Solution {
public:
    /* ------------------------------ RECURSION + MEMOIZATION---------------------------------*/
    
    vector<vector<vector<double>>>memo;
    double dp(int n, int k, int r, int c) {
        if(r<0 || r>=n || c<0 || c>=n)
            return 0;
        
        if(k == 0)
            return 1;
        
        if(memo[r][c][k] != -1)
            return memo[r][c][k];
        
        
        double ans = 0.0;
        ans =  dp(n, k-1, r+1, c+2) + dp(n, k-1, r+1, c-2) + 
               dp(n, k-1, r+2, c+1) + dp(n, k-1, r+2, c-1) +
               dp(n, k-1, r-1, c+2) + dp(n, k-1, r-1, c-2) +
               dp(n, k-1, r-2, c+1) + dp(n, k-1, r-2, c-1);
        
      
        return memo[r][c][k] = ans;
    }
    
    double knightProbability(int n, int k, int row, int column) {
       memo.resize(n+1, vector<vector<double>>(n+1, vector<double>(k+1, -1)));
        
       double res = dp(n, k, row, column);  
       return (double)res*(1.0)/(double)pow(8, k)*1.0;
    }
};