class Solution
{
public:
    long long distinctNames(vector<string> &ideas)
    {
        unordered_map<string, long long> mp;

        long long k = 0;
        int n = ideas.size();
        for (int i = 0; i < n; i++)
        {
            string a = ideas[i];
            a.erase(0, 1);
            mp[a]++;
            ideas[i] = a;
        }
        for (int i = 0; i < n; i++)
        {
            int p = mp[ideas[i]];
            if (p == 1)
            {
                k += n - 1;
            }
        }

        return k;
    }
};