class Solution
{
public:
    typedef pair<int, int> pi;
    int largestValsFromLabels(vector<int> &values, vector<int> &labels, int numWanted, int useLimit)
    {
        vector<pi> v;
        int n = values.size();
        for (int i = 0; i < n; i++)
        {
            v.push_back(make_pair(values[i], labels[i]));
        }
        sort(v.begin(), v.end());
        unordered_map<int, int> mp;

        int s = 0;
        int k = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (k < numWanted)
            {
                int val = v[i].first;
                int lb = v[i].second;
                if (mp[lb] < useLimit)
                {
                    s += val;
                    k++;
                    mp[lb]++;
                }
            }
            else
                break;
        }
        return s;
    }
};