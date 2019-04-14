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
    int i=0;
    void helper(TreeNode* n,int max,int min,int& max_diff){
        if(n==nullptr) return;
        
        if(max<n->val) max=n->val;
        if(min>n->val) min=n->val;
        
        if(n->left==nullptr && n->right==nullptr){
            int diff = -10000;
            if(max!=-1000 && min!=100000){
                diff=abs(max-min);
                if(diff>max_diff) max_diff=diff;
            }
            return;
        }
        helper(n->left,max,min,max_diff);
        helper(n->right,max,min,max_diff);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        int max_diff=-1000;
        int max=-1000;
        int min=100000;
        helper(root,max,min,max_diff);
        return max_diff;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        
        int ret = Solution().maxAncestorDiff(root);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
