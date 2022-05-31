class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        int n = columnTitle.size();
        int k = 0;

        for (int i = 0; i < n; i++)
        {
            int p = (columnTitle[i] - 64);
            k += pow(26, n - i - 1) * p;
        }
        return k;
    }
};