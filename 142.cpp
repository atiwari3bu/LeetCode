/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
bool calCycle(ListNode* traverse,vector<ListNode*> buffer){
    for(auto iter=buffer.begin();iter!=buffer.end();++iter){
        if(*iter==traverse) return true;
    }
    return false;
}

void printBuffer(vector<ListNode*> buffer){
    std::cout<<" ----------------Buffer--------------------"<<std::endl;
    for(auto iter=buffer.begin();iter!=buffer.end();++iter){
        std::cout<<(*iter)->val<<"  ";
    }
    std::cout<<std::endl;
    std::cout<<"-------------------------------------------"<<std::endl;
}

class Solution {
public:
    ListNode *detectCycle(ListNode *head,int pos) {
        vector<ListNode*> buffer;
        ListNode* traverse=head;
        while(traverse->next!=nullptr){
            std::cout<<"Traverse value is "<<traverse->val<<std::endl;
            bool isCycle=calCycle(traverse,buffer);
            if(isCycle==false){ 
                buffer.push_back(traverse);
                traverse=traverse->next;
            }
            else return traverse;
            printBuffer(buffer);

        }
        return traverse;
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

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

int stringToInteger(string input) {
    return stoi(input);
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);
        getline(cin, line);
        int pos = stringToInteger(line);
        
        ListNode* ret = Solution().detectCycle(head, pos);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
