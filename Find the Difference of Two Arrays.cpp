class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> v1;
        vector<int> v2;

        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;
        for (int i = 0; i < n1; i++)
        {
            mp1[nums1[i]]++;
        }
        for (int i = 0; i < n2; i++)
        {
            mp2[nums2[i]]++;
        }
        for (int i = 0; i < n1; i++)
        {
            if (mp2.find(nums1[i]) == mp2.end())
            {
                v1.push_back(nums1[i]);
                mp2[nums1[i]]++;
            }
        }
        for (int i = 0; i < n2; i++)
        {
            if (mp1.find(nums2[i]) == mp1.end())
            {
                v2.push_back(nums2[i]);
                mp1[nums2[i]]++;
            }
        }

        return {v1, v2};
    }
};