class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int n = s.length();
        stack<int> st;
        st.push(-1);
        int m = 0;
        for (int i = 0; i < n; i++)
        {
            int p = st.size();
            if (s[i] == '(')
            {
                st.push(i);
            }
            else
            {
                st.pop();
                if (st.empty())
                {
                    st.push(i);
                }
                else
                {
                    int k = i - st.top();
                    m = max(m, k);
                }
            }
        }
        return m;
    }
};
