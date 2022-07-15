/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        bool cycle = false;
        ListNode *s = head;
        ListNode *f = head;
        while (f->next != NULL && f->next->next != NULL)
        {
            s = s->next;
            f = f->next->next;
            if (s == f)
            {
                cycle = true;
                break;
            }
        }
        if (cycle == false)
            return NULL;
        while (head != s)
        {
            head = head->next;
            s = s->next;
        }
        return head;
    }
};