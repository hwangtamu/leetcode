class Solution {
public:

    int AddNode(ListNode **head, ListNode **cur, int sum)
    {
        int val = sum % 10;
        int d = sum / 10;
        ListNode *node = new ListNode(val);
        if (*head == NULL) {
            *head = node;
            *cur = node;
        }
        else {
            (*cur)->next = node;
            *cur = node;
        }
        return d;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *head = NULL, *cur = NULL;
        int d = 0;

        while (l1 && l2) {
            int sum = l1->val + l2->val + d;
            d = AddNode(&head, &cur, sum);
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1) {
            int sum = l1->val + d;
            d = AddNode(&head, &cur, sum);
            l1 = l1->next;
        }

        while (l2) {
            int sum = l2->val + d;
            d = AddNode(&head, &cur, sum);
            l2 = l2->next;
        }

        if (d)
            d = AddNode(&head, &cur, d);

        return head;
    }
};
