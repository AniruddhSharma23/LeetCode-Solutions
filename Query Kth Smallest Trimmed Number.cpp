class Solution
{
public:
    typedef pair<string, int> pi;

    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries)
    {
        int nq = queries.size(), n = nums.size(), len = (int)nums[0].length();
        vector<vector<int>> rank(len + 1);
        vector<pi> v(n);

        for (int i = 0; i <= len; i++)
            rank[i].resize(n + 1);
        for (int i = 1; i <= len; i++)
        {
            v.clear();
            v.resize(n);
            for (int j = 0; j < n; j++)
            {
                v[j].first = nums[j].substr(len - i, i);
                v[j].second = j;
            }
            sort(v.begin(), v.end());
            for (int k = 0; k < n; k++)
                rank[i][k] = v[k].second;
        }
        vector<int> ans(nq);
        int ind = 0;
        for (auto x : queries)
        {
            int k = x[0];
            int t = x[1];
            ans[ind++] = rank[t][k - 1];
        }
        return ans;
    }
};