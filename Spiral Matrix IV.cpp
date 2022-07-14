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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
    {
        vector<vector<int>> v(m, vector<int>(n, -1));
        ListNode *curr = head;
        int r = 0, c = 0;
        while (curr != NULL)
        {

            // left to right
            while (c < n && curr != NULL && v[r][c] == -1)
            {
                v[r][c] = curr->val;
                curr = curr->next;
                c++;
            }
            r++;
            c--;

            //
            while (r < m && curr != NULL && v[r][c] == -1)
            {
                v[r][c] = curr->val;
                curr = curr->next;
                r++;
            }
            r--;
            c--;

            // right to left
            while (c >= 0 && curr != NULL && v[r][c] == -1)
            {
                v[r][c] = curr->val;
                curr = curr->next;
                c--;
            }
            r--;
            c++;

            // down to top
            while (r >= 0 && curr != NULL && v[r][c] == -1)
            {
                v[r][c] = curr->val;
                curr = curr->next;
                r--;
            }
            r++;
            c++;
        }
        return v;
    }
};