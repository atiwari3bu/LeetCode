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
    int calHeight(TreeNode* root,bool& ans){
        if(root==nullptr) return 0;
        else{
            int lheight=calHeight(root->left,ans);
            int rheight=calHeight(root->right,ans);
        
        
        if(lheight-rheight>1 || rheight-lheight>1) ans=false;
        
        if(lheight>rheight)
            return (lheight+1);
        else return (rheight + 1);
        }
    }
    
    bool isBalanced(TreeNode* root) {
        bool ans=true;;
        int val=calHeight(root,ans);
        return ans;
    }
};
