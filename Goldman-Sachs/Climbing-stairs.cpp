/* ------------------------ Product of Array Except Self ---------------
   Leetcode Question Number : 70
   Leectode Difficulty Tag : Easy
   Leetcode Problem Link : https://leetcode.com/problems/climbing-stairs/

---------------------------------------------------------------*/

class Solution {
public:
    
    /* ------------------ RECURSION + MEMOIZATION -------------------------*/
    
    vector<int>memo;
    int approach_1(int n) {
        if(n<0)
            return 0;
        
        if( n==0 )
            return 1;
        
        if(memo[n] != -1)
            return memo[n];
        
        int ans = 0;
        ans += approach_1(n-1) + approach_1(n-2);
        
        return memo[n] = ans;
    }
    
    int climbStairs(int n) {
        if(n == 1)
            return 1;
        memo.resize(n+1, -1);
        int app_1 = approach_1(n);
        return app_1;
        
    }
};

/* --------------------------------- Tabulation O(N) Time  and O(N) space solution -----------------------------------*/

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)
            return 1;
        vector<int>dp(n);
        
        dp[0] = 1;
        dp[1] = 2;
        for(int i=2; i<n; i++)
            dp[i] = dp[i-1] + dp[i - 2];
        
        return dp[n-1];
    }
};


