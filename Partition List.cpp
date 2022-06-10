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
class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *l1 = new ListNode(0);
        ListNode *l2 = new ListNode(0);
        ListNode *k1 = l1;
        ListNode *k2 = l2;
        while (head != NULL)
        {
            if (head->val < x)
            {
                k1->next = head;
                k1 = k1->next;
            }
            else
            {
                k2->next = head;
                k2 = k2->next;
            }
            head = head->next;
        }
        k1->next = l2->next;
        k2->next = NULL;
        return l1->next;
    }
};