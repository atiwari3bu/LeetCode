class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* traverse = head;
        
        /* Swapping two at a time*/
        while(traverse && traverse->next){
            swap(traverse->val,traverse->next->val);
            traverse = traverse->next->next;
        }
        
        return head;
    }
};
