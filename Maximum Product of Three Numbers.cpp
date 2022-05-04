/*
**Method:**

* sort the array
* in variable r store the product of two greatest negative numbers and the largest positive number
* in variable k store the product of three largest positive numbers
* return max(k,r)

*/
//**Code:**

class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int r = 0;
        int k = nums[n - 1] * nums[n - 2] * nums[n - 3];
        if (nums[0] < 0 && nums[1] < 0)
        {
            r = nums[0] * nums[1] * nums[n - 1];
        }
        return max(r, k);
    }
};
```

    // *Happy Coding :)*