class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next=head;
        ListNode *prev = dummy, *curr = head;
        
        while(curr) {
            bool isDuplicate = false;
            while(curr->next && curr->val == curr->next->val) {
                isDuplicate = true;
                curr = curr->next;
            }
            if(isDuplicate)
                prev->next = curr->next;
            else
                prev = curr;
            curr = curr->next;
        }
		
        return dummy->next;
    }
};
