/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/

/* Solution available at ctci CTCI cracking the coding interview in C++ chapter */
class Solution {
public:
    map<Node*,Node*> mp;
    
    Node* copyNext(Node* n){
        if(n==nullptr) return nullptr;
        
        Node* new_node = new Node(n->val,nullptr,nullptr);
        if(mp.find(n)!=mp.end()){
            return mp.find(n)->second;
        } 
        mp.insert(make_pair(n,new_node));
        
        new_node->next=copyNext(n->next);
        new_node->random=copyNext(n->random);
        return new_node;
    }
    
    Node* copyRandomList(Node* head) {
        Node* new_head=copyNext(head);
        return new_head;
    }
};
