class Solution
{
public:
    vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
    {
        int k = original.size();
        if (k != m * n)
        {
            return {};
        }
        vector<vector<int>> v(m, vector<int>(n, 0));
        for (int i = 0; i < k; i++)
        {
            v[i / m][i % n] = original[i];
        }
        return v;
    }
};