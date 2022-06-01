class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        sort(citations.begin(), citations.end(), greater<int>());
        int n = citations.size();
        int i;
        for (i = 0; i < n; i++)
        {
            if (i >= citations[i])
                break;
        }

        return i;
    }
};