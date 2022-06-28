class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;
        int i = 0, n = nums.size();
        sort(nums.begin(), nums.end());

        while (i < n - 3)
        {
            int j = i + 1;
            while (j < n - 2)
            {
                int p = j + 1, q = n - 1;
                while (p < q)
                {
                    long long int sum = (long long int)nums[p] + (long long int)nums[q];
                    if (sum == (long long int)((long long int)target - (long long int)nums[i] - (long long int)nums[j]))
                    {
                        ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                        long long int a = (long long int)nums[p];
                        while (p < q && a == (long long int)nums[p])
                        {
                            p++;
                        }
                        long long int b = (long long int)nums[q];
                        while (p < q && b == (long long int)nums[q])
                        {
                            q--;
                        }
                    }
                    else if (sum < (long long int)((long long int)target - (long long int)nums[i] - (long long int)nums[j]))
                    {
                        p++;
                    }
                    else
                    {
                        q--;
                    }
                }

                long long int c = (long long int)nums[j];
                while (j < n - 2 && c == (long long int)nums[j])
                {
                    j++;
                }
            }

            long long int d = (long long int)nums[i];
            while (i < n - 3 && d == (long long int)nums[i])
            {
                i++;
            }
        }
        return ans;
    }
};