class Solution
{
public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        sort(boxTypes.begin(), boxTypes.end(), [](auto &a, auto &b)
             { return a[1] > b[1]; });
        int n = boxTypes.size();
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            if (truckSize > 0)
            {
                int boxes = min(truckSize, boxTypes[i][0]);
                k += boxes * boxTypes[i][1];
                truckSize -= boxes;
            }
            else
                break;
        }
        return k;
    }
};