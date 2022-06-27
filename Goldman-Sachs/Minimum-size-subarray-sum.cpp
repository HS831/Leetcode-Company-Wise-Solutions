/* ------------------------ Minimum Size Subarray Sum ---------------
   Leetcode Question Number : 209
   Leectode Difficulty Tag : Medium
   Leetcode Problem Link : https://leetcode.com/problems/minimum-size-subarray-sum/

---------------------------------------------------------------*/

class Solution {
public:
    
    // T.C. O(N) and S.C. O(1)
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        
        int sum = 0, j = 0;
        int min_len = INT_MAX;
        for(int i=0; i<n; i++) {
            sum += nums[i];
            
            while(sum >= target) {
                min_len = min(min_len, i- j + 1);
                sum -= nums[j];
                j++;
            }
        }
        
        return min_len == INT_MAX ? 0 : min_len;
    }
};