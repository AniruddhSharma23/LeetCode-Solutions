class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        int r = 0, c = 0;
        vector<int> v;
        bool up = true;
        while (r < m && c < n)
        {
            if (up)
            {
                while (r > 0 && c < n - 1)
                {
                    v.push_back(mat[r][c]);
                    r--;
                    c++;
                }
                v.push_back(mat[r][c]);
                if (c == n - 1)
                    r++;
                else
                    c++;
            }
            else
            {
                while (r < m - 1 && c > 0)
                {
                    v.push_back(mat[r][c]);
                    r++;
                    c--;
                }
                v.push_back(mat[r][c]);
                if (r == m - 1)
                    c++;
                else
                    r++;
            }
            up = !up;
        }
        return v;
    }
};