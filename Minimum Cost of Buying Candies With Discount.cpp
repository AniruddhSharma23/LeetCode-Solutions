class Solution
{
public:
    int minimumCost(vector<int> &cost)
    {
        int n = cost.size();
        sort(cost.begin(), cost.end());
        int k = 0;
        int s = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (k != 2)
            {
                s += cost[i];
                k++;
            }
            else
            {
                k = 0;
            }
        }
        return s;
    }
};