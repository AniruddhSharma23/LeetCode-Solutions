class Solution
{
public:
    int maxCoins(vector<int> &piles)
    {
        sort(piles.begin(), piles.end());
        int k = 0;
        int n = piles.size();
        int d = n / 3;
        int i = n - 2;
        while (d--)
        {
            k += piles[i];
            i -= 2;
        }
        return k;
    }
};