class Solution
{
public:
    string solve(vector<string> &words, int maxWidth, int i, int k, int st)
    {
        string s = "";
        if (i == st)
        {
            int ext = maxWidth - words[i].length();
            s += words[i];
            while (ext--)
                s += " ";
            return s;
        }
        int no_of_blocks = i - st;
        k -= no_of_blocks;
        int spaces_req = maxWidth - k;
        int curr = spaces_req / no_of_blocks;
        int extra_space = spaces_req % no_of_blocks;
        for (int j = st; j <= i; j++)
        {
            s += words[j];
            if (j != i)
            {
                for (int p = 0; p < curr; p++)
                    s += " ";
                if (extra_space > 0)
                {
                    s += " ";
                    extra_space--;
                }
            }
        }
        return s;
    }
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        int n = words.size();
        string s = "";
        vector<string> v;
        int st = 0, k = 0;
        for (int i = 0; i < n; i++)
        {
            s += words[i] + " ";
            k += words[i].length() + 1;
            if (k - 1 == maxWidth)
            {
                s.pop_back();
                v.push_back(s);
                s = "";
                k = 0;
                st = i + 1;
            }
            else if (k - 1 > maxWidth)
            {
                s = solve(words, maxWidth, i - 1, k - 2 - words[i].length(), st);
                v.push_back(s);
                i--;
                s = "";
                st = i + 1;
                k = 0;
            }
            else
            {
                if (i == n - 1)
                {
                    while (k < maxWidth)
                    {
                        s += " ";
                        k++;
                    }
                    v.push_back(s);
                }
            }
        }
        return v;
    }
};