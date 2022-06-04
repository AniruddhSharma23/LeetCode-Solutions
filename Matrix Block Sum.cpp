class Solution
{
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int k)
    {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> v(m, vector<int>(n, 0));
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < m; i++)
            {
                if (i == 0)
                {
                    v[i][j] = mat[i][j];
                }
                else
                {
                    v[i][j] = v[i - 1][j] + mat[i][j];
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mat[i][j] = 0;
                int ri = (i - k < 0) ? 0 : i - k;
                int rj = (i + k > m - 1) ? m - 1 : i + k;
                int ci = (j - k < 0) ? 0 : j - k;
                int cj = (j + k > n - 1) ? n - 1 : j + k;
                for (int p = ci; p <= cj; p++)
                {
                    mat[i][j] += v[rj][p];
                }

                if (ri > 0)
                {
                    for (int p = ci; p <= cj; p++)
                    {
                        mat[i][j] -= v[ri - 1][p];
                    }
                }
            }
        }
        return mat;
    }
};