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
    void reorderList(ListNode* head) {
        if(!head || !head -> next) return;
        ListNode* slow=head, *fast= head, *last=head;
        while(fast && fast -> next) {
            last=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        last -> next = NULL;

        ListNode* nxt=NULL, *prev=NULL;
        while(slow) {
            nxt = slow -> next;
            slow -> next = prev;
            prev = slow;
            slow = nxt;
        }
        if(head == prev) return;
        ListNode* h1=head, *h2=prev;
        ListNode* newHead = h1, *cur=h1;
        while(h1 && h2) {
            ListNode* n1 = h1->next;  
            ListNode* n2 = h2->next; 
            cur->next = h1;
            cur = cur->next;
            cur->next = h2;
            cur = cur->next;

            h1 = n1;
            h2 = n2;
        }
       
        head = newHead;
    }

};
