class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int n = neededTime.size();
        int ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            vector<int> v;
            v.push_back(neededTime[i]);
            while (colors[i] == colors[i + 1])
            {
                v.push_back(neededTime[i + 1]);
                i++;
            }
            if (v.size() != 0)
            {
                sort(v.begin(), v.end());
                int k = accumulate(v.begin(), v.end(), 0);
                ans += k - v[v.size() - 1];
            }
        }
        return ans;
    }
};