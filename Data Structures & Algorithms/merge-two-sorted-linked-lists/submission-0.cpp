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
        // ListNode* h1=list1, h2=list2;
        if(!list1) return list2;
        if(!list2) return list1; 
        ListNode* head = NULL, *cur=NULL;
        while(list1 && list2) {
            ListNode* tmp = NULL;
            if(list1-> val <= list2-> val) {
                tmp= list1;
                list1 = list1 -> next;
            } else {
                tmp = list2;
                list2 = list2 -> next;
            }
            if(!head) {
                head = tmp;
                cur = tmp;
            } else {
                cur -> next = tmp;
                cur = cur -> next;
            }
        }
        while(list1) {
            cur -> next = list1;
            cur = cur -> next;
            list1 = list1 -> next;
        }
        while(list2) {
            cur -> next = list2;
            cur = cur -> next;
            list2 = list2 -> next;
        }
        return head;
    }
};
