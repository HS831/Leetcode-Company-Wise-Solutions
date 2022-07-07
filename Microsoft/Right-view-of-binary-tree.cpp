/* ------------------------ Right View of Binary Tree ---------------
   Leetcode Question Number : 199
   Leectode Difficulty Tag : Medium
   Leetcode Problem Link : https://leetcode.com/problems/binary-tree-right-side-view/

---------------------------------------------------------------*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr)
            return {};
        
        queue<TreeNode*>q;
        q.push(root);
       
        vector<int>v;
        
        while(!q.empty()) {
            int level = q.size();
            for(int i=level-1; i>=0; i--) {
                auto curr = q.front();
                q.pop();
                if(i == 0)
                    v.push_back(curr->val);
                
                if(curr->left != nullptr)
                    q.push(curr->left);
                
                if(curr->right != nullptr)
                    q.push(curr->right);
            }
        }
        
        return v;
    }
};