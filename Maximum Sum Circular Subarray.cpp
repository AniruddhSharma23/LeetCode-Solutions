class Solution
{
public:
    int calc(vector<int> v) // based on Kadane's Algorithm
    {
        int n = v.size();
        int curr_sum = v[0], max_sum = v[0];
        for (int i = 1; i < n; i++)
        {
            if (curr_sum < 0)
                curr_sum = 0;
            curr_sum = curr_sum + v[i];
            max_sum = max(max_sum, curr_sum);
        }
        return max_sum;
    }
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int s1 = calc(nums); // sum of non-circular array
        for (auto x : nums)
            x *= -1;
        int s2 = sum - calc(nums); // sum of circular array
        return max(s1, s2);
    }
};