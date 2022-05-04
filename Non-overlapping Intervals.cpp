class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        // m is the minimum length of the interval
        int m = intervals[0][1];
        int k = 0;
        for (int i = 1; i < n; i++)
        {
            // if the first element of the vector is less than minimum length then it means there is a collison
            // increase count k
            // set m to min as later on we want minimum collision possible
            if (intervals[i][0] < m)
            {
                k++;
                m = min(m, intervals[i][1]);
            }
            else
            {
                m = intervals[i][1]; // if no collision then just simply update m
            }
        }
        return k;
    }
};