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
		ListNode* helper(ListNode* node, int curr_position,int& total_nodes){
			if(node == nullptr){
				total_nodes = curr_position;
				return nullptr;
			}

			ListNode* middleNode = helper(node->next,curr_position+1,total_nodes);

			if(total_nodes/2 == curr_position){
				return node;
			}

			else return middleNode;

		} 


		ListNode* middleNode(ListNode* head) {
			int total_nodes = 0;
			return helper(head,0,total_nodes);
		} 


		int length=0;
		ListNode* middleNode(ListNode* head) {
			ListNode* traverse=head;
			while(traverse->next!=NULL){
				traverse=traverse->next;
				++length;
			}
			int elem=length/2;
			ListNode* traverse1=head;
			int middle=0;
			while(traverse1->next!=NULL){
				if(middle == elem) break;
				traverse1=traverse1->next;
				++middle;
			}
			if(length % 2==0) return traverse1;
			else traverse1=traverse1->next;
			return traverse1;
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
		ListNode* head = stringToListNode(line);

		ListNode* ret = Solution().middleNode(head);
		string out = listNodeToString(ret);
		cout << out << endl;
	}
	return 0;
}
