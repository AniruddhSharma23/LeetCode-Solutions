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
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        int n = len(head);
        int size = n / k;
        int d = n % k;
        vector<ListNode *> v;
        if (head == NULL)
        {
            for (int i = 0; i < k; i++)
                v.push_back(NULL);
            return v;
        }
        ListNode *curr = head;
        if (n > k)
        {
            while (curr != NULL)
            {
                ListNode *nh = curr;
                ListNode *temp = NULL;
                for (int i = 0; i < size; i++)
                {
                    temp = curr;
                    curr = curr->next;
                }
                if (d > 0)
                {
                    temp = curr;
                    curr = curr->next;
                    d--;
                }
                temp->next = NULL;
                v.push_back(nh);
            }
        }
        else
        {
            while (curr != NULL)
            {
                ListNode *c = curr;
                curr = curr->next;
                c->next = NULL;
                v.push_back(c);
            }
            ListNode *temp = NULL;
            int p = k - v.size();
            while (p--)
            {
                v.push_back(temp);
            }
        }
        return v;
    }
};