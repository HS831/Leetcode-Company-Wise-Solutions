/* ------------------------ Subarray Sum Equals K ---------------
   Leetcode Question Number : 560
   Leectode Difficulty Tag : Medium
   Leetcode Problem Link : https://leetcode.com/problems/subarray-sum-equals-k/

---------------------------------------------------------------*/

class Solution {
public:
    /* Negative numbers sliding window approach will not work */
    
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>ump;
        ump[0]++;
        int cnt = 0, sum = 0;
        for(int i=0; i<n; i++) {
            sum += nums[i];
            cnt += ump[sum - k];
            ump[sum]++;
        }
        
        return cnt;
    }
};
