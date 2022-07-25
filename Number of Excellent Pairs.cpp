class Solution
{
public:
    unsigned int calc(unsigned int n)
    {
        unsigned int count = 0;
        while (n)
        {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
    long long countExcellentPairs(vector<int> &nums, int k)
    {

        set<int> st(nums.begin(), nums.end());
        long long ans = 0;
        vector<int> v;
        for (auto x : st)
        {
            int cnt = calc(x);
            if (2 * cnt >= k)
                ans++;
            v.push_back(cnt);
        }
        sort(v.begin(), v.end());
        int l = 0;
        int r = v.size() - 1;
        while (l < r)
        {
            if (v[l] + v[r] >= k)
            {
                ans += (r - l) * 2;
                r--;
            }
            else
                l++;
        }
        return ans;
    }
};