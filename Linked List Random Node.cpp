class Solution
{
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    int n = 0;
    Solution(ListNode *head)
    {
        ListNode *curr = head;
        while (curr != NULL)
        {
            n++;
            curr = curr->next;
        }
    }

    /** Returns a random node's value. */
    int getRandom()
    {
        int r = (rand()) % n; // random number between 0 to n
        ListNode *curr = head;
        while (r--)
        {
            curr = curr->next;
        }
        return curr->val;
    }
};
