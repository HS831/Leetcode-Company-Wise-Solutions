/* ------------------------ Longest Substring without repeating characters ---------------
   Leetcode Question Number : 3
   Leectode Difficulty Tag : Medium
   Leetcode Problem Link : https://leetcode.com/problems/longest-substring-without-repeating-characters/

---------------------------------------------------------------*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if( s == " ")
            return 1;
        
        unordered_map<char, int>alpha;
        
        int longest = INT_MIN;
        int j = 0;
        for(int i=0; i<n; i++) {
            alpha[s[i]]++;
            
            while(alpha[s[i]] > 1) {
                alpha[s[j]]--;
                j++;
            }
            
            longest = max(longest, i - j + 1);
        }
        
        return longest == INT_MIN ? 0 : longest;
    }
};