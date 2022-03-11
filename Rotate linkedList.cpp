/*LEETCODE #61 

Given the head of a linked list, rotate the list to the right by k places.

example
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Input: head = [0,1,2], k = 4
Output: [2,0,1]
**/


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next)
            return head;
        ListNode* tmp=head;
        int cnt=0;
        while(tmp)
        {
            cnt++;
            tmp=tmp->next;
        }

        int n=k%cnt; //stores how many to rotate
        int rotatefrom=cnt-n; //stores index from where to rotate
     
        ListNode* rotatefirst=head;
        ListNode* rotatelast=head;
        
          for(int i=0;i<rotatefrom-1;i++){
          rotatefirst=rotatefirst->next;
          rotatelast=rotatelast->next;
      }
        
        while(rotatelast->next)
            rotatelast=rotatelast->next;
        
        
        rotatelast->next=head;
        head=rotatefirst->next;
        rotatefirst->next=NULL;
    
        return head;
    }
};

/*-------------------------------------------NOTES----------------------------------------------------- 
1) find minimun number of nodes we have to rotate so that after k rotations we get desired result
2) find the index from where we have to shift it to front
3) point a pointer to the starting of the index mentioned in (2)
4) another loop to travere to the end and point ot the end
5) point the end pointer to the head of the given linkedlist
6) replace head with starting point of rotation node
7) return the new head

**/
