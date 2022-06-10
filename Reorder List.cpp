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
    void reorderList(ListNode *head)
    {
        if (head == NULL || head->next == NULL || head->next->next == NULL)
        {
            return;
        }
        ListNode *curr = head->next;
        ListNode *p = head->next;
        ListNode *q = head->next->next;
        while (p->next != NULL && p->next->next != NULL)
        {
            p = p->next;
            q = q->next;
        }
        head->next = q;
        q->next = curr;
        p->next = NULL;
        reorderList(q->next);
        return;
    }
};