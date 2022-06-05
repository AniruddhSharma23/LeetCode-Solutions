class Solution
{
public:
    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
    {
        sort(arr2.begin(), arr2.end());
        int i = 0, j = 0;
        int count = 0;
        for (int i = 0; i < arr1.size(); i++)
        {
            int start = 0;
            int end = arr2.size() - 1;
            int mid;
            while (start <= end)
            {
                mid = start + (end - start) / 2;
                if (abs(arr1[i] - arr2[mid]) <= d)
                {
                    count++;
                    break;
                }

                if (arr2[mid] - arr1[i] > d)
                    end = mid - 1;
                else
                    start = mid + 1;
            }
        }
        return arr1.size() - count;
    }
};