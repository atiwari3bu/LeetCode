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
    TreeNode* sortedArrayToBST(int start,int end,vector<int>& nums){
        if(end<start) return nullptr;
        
        int mid=(end+start)/2;
        TreeNode* node=new TreeNode(nums[mid]);
        node->left=sortedArrayToBST(start,mid-1,nums);
        node->right=sortedArrayToBST(mid+1,end,nums);
        
        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(0,nums.size()-1,nums);
    }
};
