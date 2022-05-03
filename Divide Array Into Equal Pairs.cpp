Link: https://leetcode.com/problems/divide-array-into-equal-pairs/discuss/1887146/C++-Solution-oror-HashMap-oror-Time-O(n)-oror-Space-O(n)-oror-Explained-oror-Short 
C++ Solution || HashMap || Time O(n) || Space O(n) || Explained || Short

**Method:**
* now there are 2* n elements and there will be n pairs
* hence each pair is of length =2
* now as the pair must contain a single element i.e the 2 element present in one pair must be same
* so if any element occurs odd number of time then we can say that there will be atleast one pair which violates the above condition and hence can return false
* so we create a hashmap and store the occurences of each element( key = element, value = number of occurences)
* then we traverse through each key value pair of our map and check if any key has value as an odd number
* if it is then return false
* otherwise if we didn't encounter any such pair then we return true
* **Time Complexity: O(n)**
	* n = size of nums
	* as the for loop runs at most n times
* **Space Complexity: O(n)**
	* as we created a hashmap of size n

**Code:**

```
class Solution
{
public:
    bool divideArray(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        for (auto x : mp)
        {
            if (x.second % 2 == 1)
            {
                return false;
            }
        }
        return true;
    }
};
```

*Happy Coding :-)*
