
/*LeetCode #82 
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. 
Return the linked list sorted as well.

eg- Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
**/


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

/*Note- created a dummy node to store the ultimate answer's pointer, ran a loop from begin to end of given list and in the nested loop incremented it until no duplicate was found
for the current element . If the current node is not duplicate then added it to the answer list and updated the prev to the current .....else if it is duplicate then updated 
prev's next to the current's next**/
