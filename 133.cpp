/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
    /* Solution is same as https://leetcode.com/problems/copy-list-with-random-pointer/ */

    /* Same as clone list in ctci chapter C++ */
    
public:
    map<Node*,Node*> mp;
    
    Node* cloneGraph(Node* node) {
        if(node==nullptr) return nullptr;
        if(mp.find(node)!=mp.end()) return mp.find(node)->second;
        
        Node* new_node = new Node(node->val);
        mp.insert(make_pair(node,new_node));
        
        for(auto neigh : node->neighbors){
            new_node->neighbors.push_back(cloneGraph(neigh));
        }
        
        return new_node;
        
    }
};
