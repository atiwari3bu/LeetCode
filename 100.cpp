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
    void TreeElements(TreeNode* p, vector<int> & v){
        if(p==nullptr){
            v.push_back(0);
            return;
        }
        v.push_back(p->val);
        TreeElements(p->left,v);
        TreeElements(p->right,v);
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if((p==nullptr && q!=nullptr) || (p!=nullptr && q==nullptr)) return false;
        vector<int> v1,v2;
        TreeElements(p,v1);
        TreeElements(q,v2);
        for(auto iter=v1.begin(),iter1=v2.begin();iter!=v1.end(),iter1!=v2.end();++iter,++iter1){
            if(*iter!=*iter1) return false;
        }
        return true;
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* p = stringToTreeNode(line);
        getline(cin, line);
        TreeNode* q = stringToTreeNode(line);
        
        bool ret = Solution().isSameTree(p, q);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
