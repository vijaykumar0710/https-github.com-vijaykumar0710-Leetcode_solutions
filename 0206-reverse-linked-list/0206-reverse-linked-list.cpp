class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *curr=head;
        ListNode *prev=NULL;
        ListNode *nxt=head;
        while(curr){
          nxt=curr->next;
          curr->next=prev;
          prev=curr;
          curr=nxt;
        }
        return prev;
    }
};