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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = n;
        ListNode *ahead = head;

        while (m--)
            ahead = ahead->next;

        if (ahead == NULL)
            return head->next;

        ListNode *pos = head;
        while (ahead->next) {
            pos = pos->next;
            ahead = ahead->next;
        }
        pos->next = pos->next->next;

        return head;
    }
};
