class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> v(m * n, 0);
        int r, c, i, j;
        i = j = r = c = 0;
        while (i < m * n)
        {
            // left to right
            while (c < n && matrix[r][c] != -101)
            {
                v[i] = matrix[r][c];
                matrix[r][c] = -101;
                c++;
                i++;
            }
            r++;
            c--;

            // top to down
            while (r < m && matrix[r][c] != -101)
            {
                v[i] = matrix[r][c];
                matrix[r][c] = -101;
                r++;
                i++;
            }
            r--;
            c--;

            // right to left
            while (c >= 0 && matrix[r][c] != -101)
            {
                v[i] = matrix[r][c];
                matrix[r][c] = -101;
                c--;
                i++;
            }
            r--;
            c++;

            // down to top
            while (r >= 0 && matrix[r][c] != -101)
            {
                v[i] = matrix[r][c];
                matrix[r][c] = -101;
                r--;
                i++;
            }
            r++;
            c++;
        }
        return v;
    }
};