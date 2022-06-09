class Solution
{
public:
    string minWindow(string s, string p)
    {
        unordered_map<char, int> mp;
        int np = p.length();
        int ns = s.length();
        for (int i = 0; i < np; i++)
        {
            mp[p[i]]++;
        }
        int count = mp.size();
        int i = 0;
        int j = 0;
        int len = INT_MAX;
        pair<int, int> ans;
        while (j < ns)
        {
            if (mp.find(s[j]) != mp.end())
            {
                mp[s[j]]--;
                if (mp[s[j]] == 0)
                {
                    count--;
                }
                if (count == 0)
                {
                    while (count == 0)
                    {
                        if (j - i + 1 < len)
                        {
                            len = j - i + 1;
                            ans = {i, len};
                        }
                        if (mp.find(s[i]) != mp.end())
                        {
                            mp[s[i]]++;
                            if (mp[s[i]] == 1)
                            {
                                count++;
                            }
                        }
                        i++;
                    }
                }
            }
            j++;
        }
        return (len == INT_MAX ? "" : s.substr(ans.first, ans.second));
    }
};

/*
 * Store the occurrence of characters of the given pattern in a hashmap mp.
 * count is the size of map
 * now start from the begining of s and see if the character is present in map, if it is then decrease its number of occurence
 * now if mp[s[i]]==0 i.e. till this point we found one of the character from p in s (including its duplicates)
 * so decrease the count
 * and if count ==0 then it means we got a substring in s which contains all the characters from p
 * now the idea is :
 *     If such a window found, try to minimize it by removing extra characters from the beginning of the current window.
 *     delete one character from first and again find this deleted key at right
 * we do this by first updating the length and saving the starting index "i" and len as a pair in ans
 * then as now all the elements in map has <=0 number of occurences, we start from i and increase the occurence
 * if it becomes 1 that means we found a new starting index and increase the count and leave the loop
 * Now, repeat the process till we reach the end of the string s
 * at last, return the substring starting from index i and of length len
 */