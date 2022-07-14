class Solution
{
public:
    int findLengthOfShortestSubarray(vector<int> &arr)
    {
        int n = arr.size();
        int r = n - 1;
        while (r > 0 && arr[r - 1] <= arr[r])
            r--;
        int l = 0, res = r;
        while (l < r && (l == 0 || arr[l - 1] <= arr[l]))
        {
            while (r < n && arr[r] < arr[l])
                r++;
            res = min(res, r - l - 1);
            l++;
        }
        return res;
    }
};
/*
arr = 1 2 3 10 4 2 3 5
    = 1 2 # # # 2 3 5   (l=1, r=5)

*/