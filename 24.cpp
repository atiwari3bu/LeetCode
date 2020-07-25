/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* curr_head = head;
        ListNode* curr_next = head->next;
        ListNode* curr_next_next = head->next->next;
        
        head = head->next;
        head->next = curr_head;
        curr_head->next = curr_next_next;
        ListNode* traverse = curr_head;
        
        
        while(traverse->next && traverse->next->next){

            ListNode* curr_traverse = traverse->next;
            ListNode* curr_next = traverse->next->next;
            ListNode* curr_next_next = traverse->next->next->next;


            traverse->next = curr_next;
            curr_next->next = curr_traverse;
            curr_traverse->next = curr_next_next;
            
            traverse = traverse->next->next;

        }
        
        
        return head;
        
    }
}
