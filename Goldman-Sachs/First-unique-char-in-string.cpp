/* ------------------------ First Unique Character In String ---------------
   Leetcode Question Number : 387
   Leectode Difficulty Tag : Easy
   Leetcode Problem Link : https://leetcode.com/problems/first-unique-character-in-a-string/

---------------------------------------------------------------*/

class Solution {
public:
    
    // T.C. O(N) and S.C. O(26) ~ O(1)
    int firstUniqChar(string s) {
        vector<int>hash(26, 0);
        
        for(char ch: s)
            hash[ch - 'a'] ++;
        
        for(int i=0; i<s.length(); i++) {
            if(hash[s[i] - 'a'] == 1)
                return i;
        }
        
        return -1;
    }
};

