// efficient:
class Solution
{
public:
    typedef pair<string, int> pi;
    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries)
    {
        vector<int> ans;
        int n = nums.size();
        for (auto &q : queries)
        {
            vector<pi> v;
            for (int i = 0; i < n; i++)
            {
                int t = q[1];
                int n1 = nums[i].size();
                string s = nums[i].substr(n1 - t);
                v.push_back({s, i});
            }
            sort(v.begin(), v.end());
            int k = q[0];
            ans.push_back(v[k - 1].second);
        }
        return ans;
    }
};

// min-heap
class Solution
{
public:
    typedef pair<string, int> pi;
    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries)
    {
        vector<int> ans;
        int n = nums.size();
        for (auto &q : queries)
        {
            priority_queue<pi, vector<pi>, greater<pi>> pq;
            for (int i = 0; i < n; i++)
            {
                int t = q[1];
                int n1 = nums[i].size();
                string s = nums[i].substr(n1 - t);
                pq.push({s, i});
            }
            int k = q[0];
            k--;
            while (k--)
                pq.pop();
            auto x = pq.top().second;
            ans.push_back(x);
        }
        return ans;
    }
};

// max-heap

class Solution
{
public:
    typedef pair<string, int> pi;
    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries)
    {
        vector<int> ans;
        int n = nums.size();
        for (auto &q : queries)
        {
            priority_queue<pi> pq;
            for (int i = 0; i < n; i++)
            {
                int t = q[1];
                int k = q[0];
                int n1 = nums[i].size();
                string s = nums[i].substr(n1 - t);
                auto x = pq.top().first;
                if (pq.size < k)
                    pq.push({s, i});
                else
                {
                    if (x > s)
                    {
                        pq.pop();
                        pq.push({s, i});
                    }
                }
            }
            auto x = pq.top().second;
            ans.push_back(x);
        }
        return ans;
    }
};

// naive:

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