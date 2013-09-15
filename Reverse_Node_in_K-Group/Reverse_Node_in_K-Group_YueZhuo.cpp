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
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *v = new ListNode(1);
        ListNode *last = v;
        ListNode *cur = head;
        v->next = head;

        while (true) {
            int cnt = 0;
            ListNode *prev = cur;
            while (cnt < k) {
                if (!prev)
                    break;
                prev = prev->next;
                ++cnt;
            }
            if (cnt < k)
                break;
            ListNode *tmp_last = cur;
            for (int i = 0; i < k; ++i) {
                ListNode *next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }
            last->next = prev;
            last = tmp_last;
        }


        ListNode *ans = v->next;
        delete v;
        return ans;
    }
};
