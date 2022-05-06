/*
Method:

    * create a stack containg a pair of char and int
    * the char will be the ith character of s and int will store the consecutive number of occurence of this char
    * if the stack is empty or the top element char values doesn't matches with ith character of s then add that char in the s
    * otherwise pop out the top element and push the ith character and update its number of occurence
    * now once the number of occurence reaches k then pop out that pair
    * finally create a new string p
    * run the loop through the stack and store the elements in p
    * note that element must be store as many times as they have occured( that's why there is a another while loop)
    * note that p will be in reverse order as we are storing it by poping out from stack so in the end don't forget to reverse p

*/

// Code:

class Solution
{
public:
    string removeDuplicates(string s, int k)
    {
        int n = s.length();
        if (n < k)
        {
            return s;
        }
        stack<pair<char, int>> st;
        for (int i = 0; i < n; i++)
        {
            if (st.empty() || st.top().first != s[i])
            {
                st.push({s[i], 1});
            }
            else
            {
                auto c = st.top();
                st.pop();
                st.push({s[i], c.second + 1});
            }
            if (st.top().second == k)
            {
                st.pop();
            }
        }
        string p = "";
        while (!st.empty())
        {
            auto c = st.top();
            st.pop();
            while (c.second > 0)
            {
                p.push_back(c.first);
                c.second--;
            }
        }
        reverse(p.begin(), p.end());
        return p;
    }
};