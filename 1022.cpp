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
    int convertToBinary(string& v){
        int sum=0;
        for(int i=v.length()-1,j=1;i>=0;--i,j*=2){
            sum+=(v[i]-'0')*j;
        }
        return sum;
    }
    
    void rec(TreeNode* root,string s,vector<string>& v){
        if(root==nullptr) return;
        else if(root->left==nullptr && root->right == nullptr){
            s+=to_string(root->val);
            v.push_back(s);
            return;
        }
        s+=to_string(root->val);
        rec(root->left,s,v);
        rec(root->right,s,v);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        if(root==nullptr) return 0;
        vector<string> ans;
        string s;
        rec(root,s,ans);
        int sum=0;
        for(auto v:ans){
            sum+=convertToBinary(v);
        }
        return sum;
    }
};
