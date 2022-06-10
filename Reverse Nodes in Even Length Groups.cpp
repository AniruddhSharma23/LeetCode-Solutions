class Solution
{
public:
    ListNode *reverseEvenLengthGroups(ListNode *head)
    {

        // running group item count
        int gc = 1;

        // target group
        int i = 1;

        ListNode *curr = head;

        // first node of the current group
        ListNode *start;

        // store node value
        stack<int> st;

        while (curr)
        {
            st.push(curr->val);
            if (gc == i || curr->next == NULL)
            {
                // reverse list only if current length is even
                if (!(gc & 1))
                {
                    while (gc--)
                    {
                        start->val = st.top();
                        st.pop();
                        start = start->next;
                    }
                }

                start = curr->next;
                gc = 0;
                i++; // increment next group value
            }

            curr = curr->next;
            gc++;
        }

        return head;
    }
};