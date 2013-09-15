/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL)
            return NULL;
        ListNode *cur = head;
        if (cur->next == NULL)
            return head;

        head = cur->next;
        ListNode *prev = NULL;
        while (cur && cur->next) {
            ListNode *next = cur->next;
            cur->next = next->next;
            next->next = cur;
            if (prev)
                prev->next = next;
            prev = cur;
            cur = cur->next;
        }
        return head;
    }
};
