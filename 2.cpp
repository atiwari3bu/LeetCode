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
        
        string addStrings(string s1,string s2){
            std::cout<<"S1 "<<s1<<std::endl;
            std::cout<<"S2 "<<s2<<std::endl;
            string add;
            if(s1.length()<s2.length()){
                string temp=s1;
                s1=s2;
                s2=temp;
            }
            
            int carry=0;
            for(int i=0;i<s1.length();++i){
                int no2=0;
                int temp;
                int no1=s1[i] - '0';
                if(i<s2.length())no2=s2[i] - '0';
                std::cout<<no1<<std::endl;
                if(i<s2.length()) temp=no1+no2+carry;
                else temp=no1+carry;
                
                if(temp>=10){ 
                    add+=to_string(temp%10);
                    carry=1;
                }
                else{
                    add+=to_string(temp%10);
                    carry=0;
                }
            }
            if(carry==1) add+='1';
            return add;
        }
        
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            string s1;
            string s2;
            while(l1!=nullptr){
                s1.append(to_string(l1->val));
                l1=l1->next;
            }
            while(l2!=nullptr){
                s2.append(to_string(l2->val));
                l2=l2->next;
            }    
            string s3=addStrings(s1,s2);
            std::cout<<s3<<std::endl;
            
            ListNode* head=new ListNode(s3[0]-'0');
            ListNode* traverse=head;
            
            for(int i=1;i<s3.length();++i){
                traverse->next=new ListNode(s3[i]-'0');
                traverse=traverse->next;
            }
            return head;
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
        ListNode* l1 = stringToListNode(line);
        getline(cin, line);
        ListNode* l2 = stringToListNode(line);
        
        ListNode* ret = Solution().addTwoNumbers(l1, l2);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
