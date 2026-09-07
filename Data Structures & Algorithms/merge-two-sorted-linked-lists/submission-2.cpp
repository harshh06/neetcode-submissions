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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        ListNode* a = list1, *b = list2, *head = NULL, *cur = NULL;
        while(a && b) {
            if (!head) {
                if (a -> val <= b -> val) {
                    head = a;
                    cur = a;
                    a = a -> next;
                } else {
                    head = b;
                    cur = b;
                    b = b -> next;
                }
            } else {
                if (a -> val <= b -> val) {
                    cur -> next = a;
                    cur = a;
                    a = a -> next;
                } else {
                    cur -> next = b;
                    cur = b;
                    b = b -> next;
                }
            }
        }
        while(a) {
            cur -> next = a;
            cur = cur -> next;
            a = a -> next;
        }
        while(b) {
            cur -> next = b;
            cur = cur -> next;
            b = b -> next;
        }
        return head;
    }
};
