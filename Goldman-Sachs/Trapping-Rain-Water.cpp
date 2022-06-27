/* ------------------------ Trapping Rain Water ---------------
   Leetcode Question Number : 42
   Leectode Difficulty Tag : Hard
   Leetcode Problem Link : https://leetcode.com/problems/trapping-rain-water/

---------------------------------------------------------------*/


class Solution {
public:
    // T.C. O(N) and S.C. O(N)
    int approach_1(vector<int>&height, int n) {
        vector<int>left_max(n, 0);
        vector<int>right_max(n, 0);
        
        int ans = 0;
        left_max[0] = height[0];
        right_max[n-1] = height[n-1];
        
        // Computing left max array
        for(int i=1; i<n; i++) {
            left_max[i] = max(height[i], left_max[i-1]);
        }
        
        // Computing right max array
        for(int j=n-2; j>=0; j--) {
            right_max[j] = max(height[j], right_max[j+1]);
        }
        
        // Computing amount of water trapped
        for(int i=1; i<n-1; i++) {
            ans += min(left_max[i], right_max[i]) - height[i];
        }
        
        return ans;
    }
    
    /* ---------------------------------- Optimized Approach ------------------------------------------------------*/
    // T.C. O(N) and S.C. O(1)
    int approach_2(vector<int>&height, int n) {
        int left = 0, right = n-1;
        
        int ans = 0, max_left = height[0], max_right = height[n-1];
        while(left <= right) {
            
            if(height[left] < height[right]) {
                
                if(height[left] > max_left)
                    max_left = height[left];
                else
                    ans += max_left - height[left] ;
                
                left++;
            }
            else {
             
             if(height[right] > max_right)
                 max_right = height[right];
             else
                 ans += max_right - height[right];
             
             right--;
           }
        }
        
        return ans;
    }
    
    
    int trap(vector<int>& height) {
        int n = height.size();
        int app_1 = approach_1(height, n);
        int app_2 = approach_2(height, n);
        
        return app_2;
    }
};