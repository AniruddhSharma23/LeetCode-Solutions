class Solution
{
public:
    int countLargestGroup(int n)
    {
        unordered_map<int, int> mp;
        int p = 0;
        int m = INT_MIN;
        for (int i = 1; i <= n; i++)
        {
            int k = 0;
            while (i > 0)
            {
                k += i % 10;
                i /= 10;
            }

            mp[k]++;
            if (mp[k] > m)
            {
                m = mp[k];
                p = 0;
            }
            if (mp[k] == m)
            {
                p++;
            }
        }
        return p;
    }
};