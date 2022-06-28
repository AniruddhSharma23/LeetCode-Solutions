class Solution
{
public:
    int numPairsDivisibleBy60(vector<int> &time)
    {
        int n = time.size();
        vector<int> v(60, 0);
        int t = 0;
        for (int i = 0; i < n; i++)
        {
            int k = time[i] % 60;
            (k == 0) ? t += v[0] : t += v[60 - k];
            v[k]++;
        }
        return t;
    }
};