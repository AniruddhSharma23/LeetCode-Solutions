class Solution
{
public:
    int partitionString(string s)
    {
        int ans = 1;
        unordered_set<char> st;
        for (auto c : s)
        {
            if (st.find(c) != st.end())
            {
                ans++;
                st.clear();
            }
            st.insert(c);
        }
        return ans;
    }
};

// O(1):

class Solution
{
public:
    int partitionString(string s)
    {
        int ans = 1;
        int check = 0;
        for (auto c : s)
        {
            int k = c - 'a';
            int n = 1 << k;
            if (n & check)
            {
                ans++;
                check = 0;
            }
            check = check | n;
        }
        return ans;
    }
};