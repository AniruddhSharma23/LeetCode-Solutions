class Solution
{
public:
    int minNumberOfHours(int x, int y, vector<int> &en, vector<int> &ex)
    {
        int n = en.size();
        int s1 = accumulate(en.begin(), en.end(), 0);
        int ans = 0;
        if (x <= s1)
            ans += s1 - x + 1;
        vector<int> v(n);
        v[0] = ex[0];
        for (int i = 1; i < n; i++)
            v[i] = ex[i] + v[i - 1];
        int mx = v[0];
        for (int i = 1; i < n; i++)
            mx = max(mx, ex[i] - v[i - 1]);
        if (y <= mx)
            ans += mx - y + 1;
        return ans;
    }
};