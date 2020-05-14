class Solution {
    public:
    /* Trie + max_heap */
    
    struct Node{
        Node* nodes[26] = {nullptr};
        priority_queue<string,vector<string>> pq;

    };


    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans(searchWord.length());
        Node* head = new Node();

        for(string& word : products){
            Node* traverse = head;
            
            for(char& ch : word){
                int index = ch - 'a';
                if(!traverse->nodes[index]) traverse->nodes[index] = new Node();
                
                traverse = traverse->nodes[index];
                traverse->pq.push(word);
                
                if(traverse->pq.size() > 3){
                    cout<<traverse->pq.top()<<endl;
                    traverse->pq.pop();
                }
            }

        }
        
        Node* traverse = head;
        int ans_index = 0;
        
        for(char& ch : searchWord){
            vector<string> part_ans;
            int index = ch-'a';
            
            if(!traverse->nodes[index]){
                break;
            }
            
            else traverse = traverse->nodes[index];
            
            while(!traverse->pq.empty()){ 
                string top_elem = traverse->pq.top();
                part_ans.push_back(top_elem);
                traverse->pq.pop();
            }
            
            
            ans[ans_index]=vector<string>(part_ans.rbegin(),part_ans.rend());
            ++ans_index;
        }

        
        return ans;
    }
};
