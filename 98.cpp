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
    void inorder(TreeNode* node,vector<int>& v){
        if(node==nullptr) return;
        
        inorder(node->left,v);
        v.push_back(node->val);
        inorder(node->right,v);
    }
    
    bool isValidBST(TreeNode* root) {
        vector<int> v;
        inorder(root,v);   
        if(v.size()==1 || v.size()==0) return true;
        for(int i=1;i<v.size();++i){
            if(v[i]<=v[i-1]) return false;
        }
        
        return true;
    }
};
