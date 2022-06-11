class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        unordered_map<char, int> mp;
        for (char c : s1)
        {
            mp[c]++;
        }
        int k = mp.size();
        int n2 = s2.length();
        int n1 = s1.length();
        if (n2 < n1)
        {
            return false;
        }
        int i = 0;
        int j = 0;
        int n = 0;
        while (j < n2)
        {
            if (mp.find(s2[j]) != mp.end())
            {
                mp[s2[j]]--;
                if (mp[s2[j]] == 0)
                {
                    k--;
                }
            }
            if ((j - i + 1) < n1)
            {
                j++;
            }
            else if ((j - i + 1) == n1)
            {
                if (k == 0)
                {
                    return true;
                }
                if (mp.find(s2[i]) != mp.end())
                {
                    mp[s2[i]]++;
                    if (mp[s2[i]] == 1)
                    {
                        k++;
                    }
                }
                j++;
                i++;
            }
        }
        return false;
    }
};