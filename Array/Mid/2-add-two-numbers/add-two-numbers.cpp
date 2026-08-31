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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* anchor = new ListNode(0);
        ListNode* current = anchor;

        int carry = 0;

        while(l1 != nullptr ||  l2 != nullptr || carry != 0)
            {
                int val_l1 = (l1 != nullptr) ? l1->val : 0;
                int val_l2 = (l2 != nullptr) ? l2->val : 0;

                if (l1 != nullptr) l1 = l1->next;
                if (l2 != nullptr) l2 = l2->next;

               int sum = val_l1 + val_l2 + carry;
               carry = sum /10;
               int final_sum = sum % 10;

               current->next = new ListNode(final_sum);
               current = current->next;

            }

        return anchor->next;
    }
};