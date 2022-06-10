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
    ListNode *rev(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        Node *prev = NULL;
        Node *curr = head;
        while (curr != NULL)
        {
            Node *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *curr = head;
        ListNode *prev = curr;
        while (curr != NULL && left > 1)
        {
            prev = curr;
            curr = curr->next;
            left--;
        }
        ListNode *c1 = curr;
        int k = right - left;
        while (k--)
        {
        }
        ListNode *nc = reverse(curr);
        prev->next = nc;

        curr = nc;
    }
};