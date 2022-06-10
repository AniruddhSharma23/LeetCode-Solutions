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
    int len(ListNode *head)
    {
        ListNode *curr = head;
        int n = 0;
        while (curr != NULL)
        {
            n++;
            curr = curr->next;
        }
        return n;
    }
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head->next == NULL)
        {
            return NULL;
        }
        int n = len(head);
        int m = n / 2;
        ListNode *curr = head;
        ListNode *prev = NULL;
        while (m--)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        delete (curr);
        return head;
    }
};