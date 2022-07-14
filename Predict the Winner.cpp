class Solution
{
public:
    map<vector<long long>, long long> memo;
    long long solve(int i, int j, int n, vector<int> &nums)
    {
        if (i > j || i >= n || j < 0)
            return 0;
        vector<long long> k{i, j};
        if (memo[k] != 0)
            return memo[k];
        int option1 = min(solve(i + 1, j - 1, n, nums), solve(i + 2, j, n, nums));
        int option2 = min(solve(i + 1, j - 1, n, nums), solve(i, j - 2, n, nums));
        memo[k] = max(nums[i] + option1, nums[j] + option2);
        return memo[k];
    }
    bool PredictTheWinner(vector<int> &nums)
    {
        int n = nums.size();
        int first_score = solve(0, n - 1, n, nums);
        int total_score = accumulate(nums.begin(), nums.end(), 0);
        return first_score >= total_score - first_score;
    }
};