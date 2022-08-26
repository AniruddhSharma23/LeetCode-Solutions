class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        priority_queue<int> pq;
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pq.size() < k)
                    pq.push(matrix[i][j]);
                else
                {
                    if (pq.top() > matrix[i][j])
                    {
                        pq.pop();
                        pq.push(matrix[i][j]);
                    }
                }
            }
        }
        return pq.top();
    }
};

// Binary-Search
class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size();
        int l = matrix[0][0];
        int r = matrix[n - 1][n - 1];
        int ans = -1;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (countsmaller(matrix, m) >= k)
            {
                ans = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        return ans;
    }
    int countsmaller(vector<vector<int>> &matrix, int m)
    {
        int n = matrix.size();
        int c = n - 1;
        int count = 0;
        for (int r = 0; r < n; r++)
        {
            while (c >= 0 && matrix[r][c] > m)
                c--;
            count += c + 1;
        }
        return count;
    }
};