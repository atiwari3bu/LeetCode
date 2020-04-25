class Solution {
public:
    Node* flatten(Node* head) {
        Node* traverse = head;
        
        while(traverse){
            if(!traverse->child){ // Meaning there are no child
                if(traverse->next) traverse->next->prev=traverse;
                traverse = traverse -> next;
            }
            
            else{  // There is child
                Node* should_be_next = traverse->next;
                traverse -> next = traverse->child;
                
                while(traverse->next!=nullptr){
                    if(traverse->child){ // recursion case
                        traverse -> next = flatten(traverse->child);
                        traverse -> child = nullptr;
                    }   
                    if(traverse->next) traverse->next->prev = traverse; 
                    traverse = traverse->next;
   
                }
                
                traverse -> next = should_be_next;
                traverse -> child = nullptr;
                if(traverse->next) traverse->next->prev = traverse; 
                traverse = traverse -> next;
            }
        }
        
        return head;
    }
};
