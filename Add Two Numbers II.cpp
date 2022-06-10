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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        stack<ListNode *> s1, s2, s3;
        while (l1 != NULL)
        {
            s1.push(l1);
            l1 = l1->next;
        }
        while (l2 != NULL)
        {
            s2.push(l2);
            l2 = l2->next;
        }
        int carry = 0;
        while (!s1.empty() && !s2.empty())
        {
            int k = s1.top()->val + s2.top()->val + carry;
            ListNode *temp = new ListNode(k % 10);
            s3.push(temp);
            carry = (k > 9) ? 1 : 0;
            s1.pop();
            s2.pop();
        }
        while (!s1.empty())
        {
            int k = s1.top()->val + carry;
            ListNode *temp = new ListNode(k % 10);
            s3.push(temp);
            carry = (k > 9) ? 1 : 0;
            s1.pop();
        }
        while (!s2.empty())
        {
            int k = s2.top()->val + carry;
            ListNode *temp = new ListNode(k % 10);
            s3.push(temp);
            carry = (k > 9) ? 1 : 0;
            s2.pop();
        }
        if (carry == 1)
        {
            ListNode *temp = new ListNode(1);
            s3.push(temp);
        }
        ListNode *prev = new ListNode(-1);
        if (!s3.empty())
        {
            prev = s3.top();
        }
        while (!s3.empty())
        {
            ListNode *curr = s3.top();
            s3.pop();
            if (s3.empty())
            {
                curr->next = NULL;
            }
            else
            {
                curr->next = s3.top();
            }
        }
        return prev;
    }
};