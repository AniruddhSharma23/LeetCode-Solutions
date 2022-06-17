class Solution
{
public:
    int findShortestSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int mn = n;
        int mx = 0;
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]].push_back(i);
            int sz = mp[nums[i]].size();
            mx = max(mx, sz);
        }
        for (auto x : mp)
        {
            int sz = x.second.size();
            if (sz == mx)
            {
                int len = x.second[sz - 1] - x.second[0] + 1;
                mn = min(mn, len);
            }
        }
        return mn;
    }
};

/*
we create a map whose key will be the nums[i] and each key will have a vector array which will
store the indexes where nums[i] appeared in nums
now the most occuring element will have the vector of largest size
and there can be more than 1 maximum occuring element
so in the second for loop we check for the min length of the subarray
note that when we store the indexes in vector array then the index of first occurence of nums[i]=v[0]
nd index of last occurence of nums[i]=v[sz-1] where sz is size of v
so the subarray length will be v[sz-1]-v[0]+1
update the min length mn and return it
*/