Link : https : // leetcode.com/problems/build-array-from-permutation/discuss/1797703/C++-Explanation-or-Time-O(n)

               C++ Explanation |
               Time O(n)

                   * *Method : ***We create a vector array v
                                   *Run a loop to insert the values in v
                                       *According to the problem we want v[i] = nums[nums[i]] so we push_back the required value in our vector array v
                                                                                * Finally,
                                                                         return v.* **Time Complexity : O(n) * **where, n is the size of array nums *O(n)
because we run the loop n times

    **Code : **
``` class Solution
{
public:
    vector<int> buildArray(vector<int> &nums)
    {
        vector<int> v;
        for (int i = 0; i < nums.size(); i++)
        {
            v.push_back(nums[nums[i]]);
        }
        return v;
    }
};
```