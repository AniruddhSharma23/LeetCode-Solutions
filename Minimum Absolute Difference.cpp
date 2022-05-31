class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int m = INT_MAX;
        for (int i = 1; i < arr.size(); i++)
        {
            m = min(arr[i] - arr[i - 1], m);
        }
        vector<vector<int>> v;
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] - arr[i - 1] == m)
            {
                v.push_back({arr[i - 1], arr[i]});
            }
        }
        return v;
    }
};
Minimum Absolute Difference