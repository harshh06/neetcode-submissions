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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len =0;
        ListNode* slow = head, *fast = head;
        while(fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
            len++;
        }
        if(!fast) len *= 2;
        else len = len*2 + 1;
        int target = len-n;
        slow = head;
        ListNode* prev= NULL;
        while(target--) {
            prev = slow;
            slow = slow -> next;
        }
        cout << slow -> val << "\n";
        if(!prev) return slow -> next;
        ListNode* tmp = slow;
        prev -> next = slow -> next;
        delete(slow);

        return head;
    }
};
