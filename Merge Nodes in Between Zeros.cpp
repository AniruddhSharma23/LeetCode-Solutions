class Solution
{
public:
    ListNode *mergeNodes(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return NULL;
        }
        ListNode *curr = head->next;
        while (curr != NULL)
        {
            if (curr->next->val == 0) // if the next node is 0 (end of one sequence)
            {
                curr->next = curr->next->next; // move the pointer to the node next of 0
                curr = curr->next;             // set that node as curr
                // (note that this time we don't add the value, because now we will encounter new sequence)
            }
            else
            {
                curr->val = curr->val + curr->next->val; // keep adding the value of the next node to curr
                curr->next = curr->next->next;           // move curr to the node next of curr->next
            }
        }
        return head->next;
    }
};