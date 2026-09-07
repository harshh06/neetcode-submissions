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
    ListNode* reverse(ListNode* head) {
        if(!head) return NULL;
        ListNode* prev=NULL, *cur=head, *nxt = NULL;
        while(cur) {
            nxt = cur -> next;
            cur -> next= prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }

    ListNode* returnMid(ListNode* head) {
        ListNode* slow = head, *fast = head, *prev = NULL;
        while(fast && fast -> next) {
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }  
        prev -> next = NULL;  
        return slow;
    }

    void reorderList(ListNode* head) {
        if(!head || !head -> next) return; 
        ListNode* mid = returnMid(head);
        ListNode* head2 = reverse(mid);
        ListNode dummy;
        ListNode* cur = &dummy;
        int bit = 1;
        ListNode* tmp = head;
        while(head && head2) {
            if(bit) {
                cur -> next = head;
                head = head -> next;
            } else {
                cur -> next = head2;
                head2 = head2 -> next;
            }
            cur = cur -> next;
            bit ^= 1;
        }
        cur -> next = head2;
    }
};
