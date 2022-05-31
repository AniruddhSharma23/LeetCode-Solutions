class Solution
{
public:
    double trimMean(vector<int> &arr)
    {
        double n = arr.size();
        double k = n / 20;
        double s = 0;
        sort(arr.begin(), arr.end());
        for (int i = k; i < n - k; i++)
        {
            s += arr[i];
        }
        return s / (n - (2 * k));
    }
};