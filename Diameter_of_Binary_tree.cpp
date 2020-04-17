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
    int helper(TreeNode* root,int& max_len){
        if(!root) return 0;
        
        int lheight = helper(root->left,max_len);
        int rheight = helper(root->right,max_len);

        if(lheight + rheight > max_len) max_len = lheight+rheight;

        return max(lheight,rheight) + 1;
    } 
    
    int diameterOfBinaryTree(TreeNode* root) {
        int max_len = 0;
        helper(root,max_len);
        return max_len;
    }
};
