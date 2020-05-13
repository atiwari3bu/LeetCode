class Trie {
    public:
    /** Initialize your data structure here. */
    class Node{
        public:
        char ch;
        Node* nodes[26] = {nullptr};
        bool isWord;

        Node(char ch){
            this->ch = ch;
            this->isWord = false;
        }
    };

    Node* root;

    Trie() {
        this->root = new Node('*'); 
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* traverse = this->root;

        for(char& ch : word){
            int index = ch - 'a';

            if(traverse->nodes[index]==nullptr){
                traverse->nodes[index] = new Node(ch);
            }

            traverse = traverse->nodes[index]; 
        } 
        
        if(traverse) traverse->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* traverse = this->root;
        
        for(auto& ch : word){
            int index = ch - 'a';
            if(!traverse->nodes[index]) return false;
            traverse = traverse->nodes[index];  
        }
        
        return traverse->isWord? true : false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* traverse = this->root;
        
        for(auto& ch : prefix){
            int index = ch - 'a';
            if(!traverse->nodes[index]) return false;
            traverse = traverse->nodes[index];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
