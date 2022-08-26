class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int k = 0;
        for (int i = 0; i <= n; i++)
        {
            k ^= i;
        }
        for (int i = 0; i < n; i++)
        {
            k ^= nums[i];
        }
        return k;
    }
};
class Solution
{
public:
    void cyclesort(vector<int> &nums)
    {
        int n = nums.size(), i = 0;
        while (i < n)
        {
            int j = nums[i];
            if (j < n && nums[i] != nums[j])
                swap(nums[i], nums[j]);
            else
                i++;
        }
    }
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        cyclesort(nums);
        for (int i = 0; i < n; i++)
            if (nums[i] != i)
                return i;
        return n;
    }
};