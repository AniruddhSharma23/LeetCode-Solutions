class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        int ns = spells.size();
        int np = potions.size();
        vector<int> v(ns, 0);
        sort(potions.begin(), potions.end());
        int i;
        int j;
        long long k = 0;
        for (i = 0; i < ns; i++)
        {
            int l = 0;
            int r = np - 1;
            while (l <= r)
            {
                int m = l + (r - l) / 2;
                long long k2 = (long long)spells[i] * (long long)potions[m - 1];
                long long k1 = (long long)spells[i] * (long long)potions[m];
                if (k1 >= success && k2 < success)
                {
                    k = m;
                    break;
                }
                else if (k2 >= success)
                {
                    r = m;
                }
                else
                {
                    l = m;
                }
            }
            if (k != 0)
            {
                v[i] = np - k;
            }
        }
        return v;
    }
};

class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        int ns = spells.size();
        int np = potions.size();
        vector<int> v(ns, 0);
        vector<double> v2(np, 0.0);
        for (int i = 0; i < np; i++)
        {
            v2[i] = (double)(success / potions[i]);
        }
        for (int i = 0; i < ns; i++)
        {
            int k = 0;
            for (int j = 0; j < np; j++)
            {
                if ((double)spells[i] >= v2[j])
                {
                    k++;
                }
            }
            v[i] = k;
        }
        return v;
    }
};