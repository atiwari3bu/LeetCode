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
    bool helper(TreeNode* s, TreeNode* t){
        if(s && !t) return false;
        else if(!s && t) return false;
        else if(!s && !t) return true;
        else if(s->val!=t->val) return false;
        else{
            bool val = helper(s->left,t->left) && helper(s->right,t->right);
            return val;
        }
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s || !t) return false;
        
        if(s->val==t->val){
            if(helper(s,t)) return true;
        }
        
        return isSubtree(s->left,t) || isSubtree(s->right,t);
    }
};
