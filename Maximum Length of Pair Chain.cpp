class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), [](auto a, auto b)
             { return a[0] < b[0]; });
        vector<int> lis(n, 1);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (pairs[j][1] < pairs[i][0])
                    lis[i] = max(lis[i], lis[j] + 1);
            }
        }
        return *max_element(lis.begin(), lis.end());
    }
};

// greedy:

class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        int n = pairs.size(), count = 1;
        sort(pairs.begin(), pairs.end(), [&](auto a, auto b)
             { return a[1] < b[1]; });
        int prev = pairs[0][1];
        for (int i = 1; i < n; ++i)
        {
            if (pairs[i][0] > prev)
            {
                count++;
                prev = pairs[i][1];
            }
        }
        return count;
    }
};