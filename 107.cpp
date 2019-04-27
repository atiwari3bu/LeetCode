/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    /* Preorder solution provided below */
    
 // https://leetcode.com/problems/binary-tree-level-order-traversal/discuss/33468/One-of-C%2B%2B-solutions-(preorder)
 
    void preOrder(vector<vector<int>>& ans,TreeNode* root,int depth){
        if(root==nullptr) return ;
        if(depth>ans.size()){
            ans.push_back(vector<int>{root->val});
        }
        else ans[depth-1].push_back(root->val);
        
        preOrder(ans,root->left,depth+1);
        preOrder(ans,root->right,depth+1);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        int depth=1;
        preOrder(ans,root,depth);
        return vector<vector<int>>(ans.rbegin(),ans.rend());
    }
};
