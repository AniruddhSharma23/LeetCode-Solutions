class Solution
{
public:
    int minMutation(string start, string end, vector<string> &bank)
    {
        set<string> st(bank.begin(), bank.end());
        queue<string> q;
        q.push(start);
        int ans = 0;
        while (!q.empty())
        {
            int n = q.size();
            while (n--)
            {
                string s = q.front();
                if (s == end)
                    return ans;

                q.pop();
                st.erase(s);
                for (int i = 0; i < 8; i++)
                {
                    string t = s;
                    t[i] = 'A';
                    if (st.find(t) != st.end())
                        q.push(t);
                    t[i] = 'C';
                    if (st.find(t) != st.end())
                        q.push(t);
                    t[i] = 'G';
                    if (st.find(t) != st.end())
                        q.push(t);
                    t[i] = 'T';
                    if (st.find(t) != st.end())
                        q.push(t);
                }
            }
            ans++;
        }
        return -1;
    }
};