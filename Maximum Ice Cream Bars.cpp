class Solution
{
public:
    int maxIceCream(vector<int> &costs, int coins)
    {
        sort(costs.begin(), costs.end());
        int k = 0;
        for (auto x : costs)
        {
            if (x <= coins)
            {
                coins -= x;
                k++;
            }
            else
                break;
        }
        return k;
    }
};