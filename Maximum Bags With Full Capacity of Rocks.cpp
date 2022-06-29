class Solution
{
public:
    int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks)
    {
        vector<int> space;
        int n = rocks.size();
        for (int i = 0; i < n; i++)
            space.push_back(capacity[i] - rocks[i]);
        sort(space.begin(), space.end());
        int k = 0;
        for (auto x : space)
        {
            if (x <= additionalRocks)
            {
                k++;
                additionalRocks -= x;
            }
            else
                break;
        }
        return k;
    }
};