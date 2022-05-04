class Solution
{
public:
    bool isOperator(string c)
    {
        if (c == "+" || c == "-" || c == "/" || c == "*")
        {
            return true;
        }
        return false;
    }
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        int n = tokens.size();
        for (int i = 0; i < n; i++)
        {
            if (!isOperator(tokens[i]))
            {
                st.push(stoi(tokens[i]));
            }
            else
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if (tokens[i] == "+")
                {
                    st.push(b + a);
                }
                else if (tokens[i] == "-")
                {
                    st.push(b - a);
                }
                else if (tokens[i] == "/")
                {
                    st.push(b / a);
                }
                else
                {
                    st.push(b * a);
                }
            }
        }
        return st.top();
    }
};