class Solution
{
public:
    void cyclesort(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0;
        while (i < n)
        {
            int j = nums[i];
            if (j > 0 && j <= n && nums[i] != nums[j - 1])
                swap(nums[i], nums[j - 1]);
            else
                i++;
        }
    }
    int firstMissingPositive(vector<int> &nums)
    {
        cyclesort(nums);
        int k = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0 && nums[i] != k)
            {
                return k;
            }
            if (nums[i] == k)
            {
                k++;
            }
        }
        return k;
    }
};