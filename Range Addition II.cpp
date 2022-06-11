class Solution
{
public:
    int maxCount(int m, int n, vector<vector<int>> &ops)
    {
        int r = m;
        int c = n;
        int k = m * n;
        for (auto x : ops)
        {
            r = min(r, x[0]);
            c = min(c, x[1]);
            k = min(k, r * c);
        }
        return k;
    }
};