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
    void helper(TreeNode* root,int& sum){
        if(root==nullptr) return;
        helper(root->right,sum);
        sum+=root->val;
        root->val=sum;
        helper(root->left,sum);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        int sum=0;
        helper(root,sum);
        return root;
    }
};
