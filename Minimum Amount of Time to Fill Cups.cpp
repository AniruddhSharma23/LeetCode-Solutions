class Solution
{
public:
    int fillCups(vector<int> &amount)
    {
        int s = accumulate(amount.begin(), amount.end(), 0);
        int m = *max_element(amount.begin(), amount.end());
        return max(m, (s + 1) / 2);
    }
};