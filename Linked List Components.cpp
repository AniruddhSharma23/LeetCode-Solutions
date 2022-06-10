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
    int numComponents(ListNode *head, vector<int> &nums)
    {
        unordered_set<int> st;
        vector<int> v;
        ListNode *curr = head;
        while (curr != NULL)
        {
            v.push_back(curr->val);
            curr = curr->next;
        }
        for (auto x : nums)
        {
            st.insert(x);
        }
        int n = 0;
        int k = 0;
        for (auto x : v)
        {
            if (st.find(x) != st.end())
            {
                k++;
            }
            else
            {
                if (k > 0)
                {
                    n++;
                }
                k = 0;
            }
        }
        if (k > 0)
        {
            n++;
        }
        return n;
    }
};