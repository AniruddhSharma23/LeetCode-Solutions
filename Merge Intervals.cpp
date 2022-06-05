class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &v)
    {
        int n, i;
        n = v.size();
        sort(v.begin(), v.end());
        vector<vector<int>> k;

        k.push_back(v[0]);
        for (i = 1; i < n; i++)
        {
            if (v[i][0] <= k.back()[1] && (v[i][1] > k.back()[1]))
            {
                k.back()[1] = v[i][1];
            }
            if (v[i][0] > k.back()[1])
            {
                k.push_back(v[i]);
            }
        }
        return k;
    }
};