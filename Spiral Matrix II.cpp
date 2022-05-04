class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> v(n, vector<int>(n, -1));
        int r = 0;
        int c = 0;
        int k = 1;

        while (k <= n * n)
        {

            // right
            for (; c < n && k <= n * n; c++)
            {
                if (v[r][c] != -1)
                {
                    break;
                }
                else
                {
                    v[r][c] = k;
                }
                k++;
            }
            r++;
            c--;

            // down
            for (; r < n && k <= n * n; r++)
            {
                if (v[r][c] != -1)
                {
                    break;
                }
                else
                {
                    v[r][c] = k;
                }
                k++;
            }
            r--;
            c--;

            // left
            for (; c >= 0 && k <= n * n; c--)
            {
                if (v[r][c] != -1)
                {
                    break;
                }
                else
                {
                    v[r][c] = k;
                }
                k++;
            }
            r--;
            c++;

            // up
            for (; r >= 0 && k <= n * n; r--)
            {
                if (v[r][c] != -1)
                {
                    break;
                }
                else
                {
                    v[r][c] = k;
                }
                k++;
            }
            r++;
            c++;
        }
        return v;
    }
};