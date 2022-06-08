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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int len = 1;
        ListNode *temp = head;
        while (temp->next != NULL)
        {
            len++;
            temp = temp->next;
        }
        if ((len < n) || (len == 1 && n == 1))
        {
            return NULL;
        }
        if (len == n)
        {
            head = head->next;
            return head;
        }
        ListNode *curr = head;
        int i = 0;
        while (i < len - n - 1)
        {
            curr = curr->next;
            i++;
        }
        curr->next = curr->next->next;
        return head;
    }
};