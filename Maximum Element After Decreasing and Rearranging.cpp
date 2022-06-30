class Solution
{
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int mn = 1, n = arr.size();
        for (int i = 1; i < n; i++)
            if (arr[i] > mn)
                mn++;
        return mn;
    }
};