class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
            return n;
        unordered_set<int> st(nums.begin(), nums.end());
        int k = 0;
        for (auto x : st)
        {
            if (st.find(x - 1) == st.end())
            {
                int t = x;
                int count = 1;
                while (st.find(t + 1) != st.end())
                {
                    t++;
                    count++;
                }
                k = max(k, count);
            }
        }
        return k;
    }
};