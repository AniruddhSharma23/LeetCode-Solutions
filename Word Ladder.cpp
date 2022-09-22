class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        int k = beginWord.length();
        set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        int ans = 0;
        if (st.find(endWord) == st.end())
            return 0;
        while (!q.empty())
        {
            int n = q.size();
            while (n--)
            {
                string s = q.front();
                q.pop();
                if (s == endWord)
                    return ans;
                st.erase(s);
                for (int i = 0; i < k; i++)
                {
                    string t = s;
                    for (int j = 0; j < 26; j++)
                    {
                        t[i] = 'a' + j;
                        if (st.count(t))
                        {
                            q.push(t);
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};