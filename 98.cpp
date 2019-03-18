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

    /* O(1) space complexity */
		bool helper(TreeNode* n,int& min,int& max){
        if(n==nullptr) return true;
        if(max!=-10000 && n->val>= max || min!=-10000 && n->val<=min) return false;
        return (helper(n->left,min,n->val) && helper(n->right,n->val,max));
    }
    
    bool isValidBST(TreeNode* root) {
        int min=-10000;
        int max=-10000;
        return helper(root,min,max);    
    }
};
