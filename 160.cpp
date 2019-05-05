/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int calDistance(ListNode* n){
        int dist=0;
        while(n!=nullptr){
            ++dist;
            n=n->next;
        }
        return dist;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==nullptr || headB==nullptr) return nullptr;
        int n1=calDistance(headA);
        int n2=calDistance(headB);
        
        if(n1<n2){
            int i=0,diff=n2-n1;
            while(i!=diff){
                headB=headB->next;
                ++i;
            }
        }
        
        else{
            int i=0,diff=n1-n2;
            while(i!=diff){
                headA=headA->next;
                ++i;
            }
        }
        
        while(headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }

        return headA;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

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
        int intersectVal = stringToInteger(line);
        getline(cin, line);
        ListNode* listA = stringToListNode(line);
        getline(cin, line);
        ListNode* listB = stringToListNode(line);
        getline(cin, line);
        int skipA = stringToInteger(line);
        getline(cin, line);
        int skipB = stringToInteger(line);
        
        ListNode* ret = Solution().getIntersectionNode(intersectVal, listA, listB, skipA, skipB);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
