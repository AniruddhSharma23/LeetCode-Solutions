class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<vector<int>> v(rowIndex + 1);
        for (int i = 0; i < rowIndex + 1; i++)
        {
            vector<int> a(i + 1);
            for (int j = 0; j < i + 1; j++)
            {
                if (i == 0)
                {
                    a[j] = 1;
                }
                else if (j == 0 || j == i)
                {
                    a[j] = 1;
                }
                else
                {
                    a[j] = v[i - 1][j - 1] + v[i - 1][j];
                }
            }
            v[i] = a;
        }
        return v[rowIndex];
    }
};