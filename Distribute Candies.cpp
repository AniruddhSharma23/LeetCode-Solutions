class Solution
{
public:
    int distributeCandies(vector<int> &candyType)
    {
        int n = candyType.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[candyType[i]]++;
        }
        int k = mp.size();
        if (k >= n / 2)
        {
            return n / 2;
        }
        return k;
    }
};