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
    int pairSum(ListNode *head)
    {
        ListNode *curr = head;
        vector<int> v;
        while (curr != NULL)
        {
            v.push_back(curr->val);
            curr = curr->next;
        }
        int n = v.size();
        int l = 0;
        int r = n - 1;
        int m = INT_MIN;
        while (l < r)
        {
            int s = v[l] + v[r];
            m = max(s, m);
            l++;
            r--;
        }
        return m;
    }
};