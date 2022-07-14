class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        vector<int> v(n, 1);
        for (int i = 0; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
                v[i] = v[i - 1] + 1;
        }
        return accumulate(v.begin(), v.end(), 0);
    }
};