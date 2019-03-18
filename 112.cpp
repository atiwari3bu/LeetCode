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
    void helper(TreeNode* root,int sum,int current_sum,bool& is_path){
        if(root==nullptr){
            return;
        }
        current_sum+=root->val;
        if(current_sum==sum && root->left==nullptr && root->right==nullptr){
            is_path=true;
        }
        
        if(is_path==false){
            helper(root->left,sum,current_sum,is_path);
            helper(root->right,sum,current_sum,is_path);
        }
    }
    
    
    bool hasPathSum(TreeNode* root, int sum) {
        int current_sum=0;
        bool is_path=false;
        helper(root,sum,current_sum,is_path);
        return is_path;
    }
};
