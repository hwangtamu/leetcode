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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = (int)lists.size();

        ListNode **pos = new ListNode *[len];
        for (int i = 0; i < len; ++i)
            pos[i] = lists[i];

        ListNode *head = NULL;
        ListNode *cur = NULL;

        while (true) {
            int min_val = INT_MAX;
            int index = -1;
            for (int i = 0; i < len; ++i) {
                if (pos[i] && pos[i]->val < min_val) {
                    min_val = pos[i]->val;
                    index = i;
                }
            }
            if (index == -1)
                break;
            if (head == NULL) {
                head = new ListNode(min_val);
                cur = head;
            }
            else {
                cur->next = new ListNode(min_val);
                cur = cur->next;
            }
            pos[index] = pos[index]->next;
        }

        delete []pos;
        return head;
    }
};
