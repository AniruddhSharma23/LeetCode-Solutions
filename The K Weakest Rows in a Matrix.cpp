#define pr pair<int, int>
class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {

        priority_queue<pr, vector<pr>, greater<pr>> pq;
        for (int i = 0; i < mat.size(); i++)
        {
            int s = accumulate(mat[i].begin(), mat[i].end(), 0); // sum of all the elements of the ith row
            pq.push(make_pair(s, i));                            // store the sum and index as a pair in priority queue
        }
        // priority queue will arrange the pairs according to the first index and in the increasing order
        // so pop out k top elements from the priority queue
        vector<int> v;
        while (k--)
        {
            v.push_back(pq.top().second);
            pq.pop();
        }
        return v;
    }
};