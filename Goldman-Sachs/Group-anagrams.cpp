/* ------------------------ Group Anagrams ---------------
   Leetcode Question Number : 70
   Leectode Difficulty Tag : Easy
   Leetcode Problem Link : https://leetcode.com/problems/group-anagrams/

---------------------------------------------------------------*/

class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>>ans;
        
        vector<string>s;
        for(string &st : strs) {
            string a = st;
            sort(a.begin(), a.end());
            s.push_back(a);
        }
        
        unordered_map<string, vector<string>>ump;
        
        for(int i=0; i<n; i++) {
            string st = s[i];
            ump[st].push_back(strs[i]);
        }
        
        for(auto &it : ump) {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};