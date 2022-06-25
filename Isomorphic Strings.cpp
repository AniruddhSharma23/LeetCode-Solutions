class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> mp;
        set<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (mp.find(s[i]) != mp.end())
            {
                if (mp[s[i]] != t[i])
                {
                    return false;
                }
            }
            else
            {
                if (st.count(t[i]) > 0)
                {
                    return false;
                }
                else
                {
                    st.insert(t[i]);
                    mp[s[i]] = t[i];
                }
            }
        }
        return true;
    }
};