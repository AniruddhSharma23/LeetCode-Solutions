class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int n1 = students.size();
        int n2 = sandwiches.size();
        queue<int> q;
        queue<int> p;
        for (int i = 0; i < n1; i++)
        {
            q.push(students[i]);
        }
        for (int i = 0; i < n2; i++)
        {
            p.push(sandwiches[i]);
        }
        int k = 0;
        while (n1 > 0 && n2 > 0)
        {
            if (p.front() == q.front())
            {
                q.pop();
                p.pop();
                k = 0;
                n1--;
                n2--;
            }
            else
            {
                int a = q.front();
                q.pop();
                q.push(a);
                k++;
                if (k >= q.size())
                {
                    break;
                }
            }
        }
        return q.size();
    }
};