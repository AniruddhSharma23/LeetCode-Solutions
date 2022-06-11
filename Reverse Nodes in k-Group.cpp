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
        int n = 0;
        while (head != NULL)
        {
            head = head->next;
            n++;
        }
        return n;
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL || len(head) < k)
        {
            return head;
        }
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *temp = NULL;
        int p = k;
        while (curr != NULL && p--)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        if (temp != NULL)
        {
            head->next = reverseKGroup(temp, k);
        }
        return prev;
    }
};