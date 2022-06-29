/* ------------------------ Product of Array Except Self ---------------
   Leetcode Question Number : 238
   Leectode Difficulty Tag : Medium
   Leetcode Problem Link : https://leetcode.com/problems/product-of-array-except-self/

---------------------------------------------------------------*/

class Solution {
public:

    // T.C. O(N) and S.C. O(N)
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix_prod(n);
        vector<int>suffix_prod(n);
        
        prefix_prod[0] = 1, suffix_prod[n-1] = 1;
        
        for(int i=1; i<n; i++)
            prefix_prod[i] = prefix_prod[i-1] * nums[i-1];
        
        for(int i=n-2; i>=0; i--)
            suffix_prod[i] = suffix_prod[i+1] * nums[i+1];
        
        vector<int>ans(n);
        
        for(int i=0; i<n; i++)
            ans[i] = prefix_prod[i] * suffix_prod[i];
        
        return ans;
    }
};

/* A little space optimization */


class Solution {
public:
    // T.C. O(N) and S.C. O(N) [ only for returning answer vector (did not use any extra space as stated in follow - up)]
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int>ans(n);
        
        ans[0] = 1;
        for(int i=1; i<n; i++)
            ans[i] = ans[i-1] * nums[i-1];
        
        int suff = 1;
        for(int i=n-1; i>=0; i--) {
            ans[i] = ans[i] * suff;
            suff = suff * nums[i];
        }
        
        return ans;
    }
};