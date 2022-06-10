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
    vector<int> nextLargerNodes(ListNode *head)
    {
        ListNode *curr = head;
        vector<int> v1;
        while (curr != NULL)
        {
            v.push_back(curr->val);
            curr = curr->next;
        }
        int n = v.size();
        vector<int> v2(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && v1[i] > v1[st.top()])
            {
                int k = st.top();
                v2[k] = v1[i];
                st.pop();
            }
            st.push(i);
        }
        return v2;
    }
};
