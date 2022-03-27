Method :
    //
    // We sort the given array
    // now the most efficient way would to send the lightest and heaviest person together
    // because if we choose two heaviest person then it can exceed limit and we might have to send them alone
    // if we choose two lightest then they may not exceed limit but then the highest would go alone *
    // so we use the two pointer approach and
    // check if the first and last index exceed the limit
    // if it does then we sent the heaviest one alone
    // why?
    // because all the elements after the first one are heavier and thus if the first can 't go with the last element then there is no chance that any middle element will satisfy the criteria with this last element
    // if it doesn' t then send the first and last element together and shift the pointers accordingly
    // no matter which situtaion arises we have to increase the count as the boat will leave either with one person or two
    // hence the k++ is common in both if and else statement that's why we can just write it seperately( to save the space)
    // now return the count variable k
    Time Complexity : O(nLogn)
                      // the sorting takes O(n logn) * the two pointer while loop takes O(n)
                      // hence overall is O(nLogn)
                      Space Complexity : O(1)
                                         // as we created only one variable to store the count
                                         // hence the space complexity is linear

                                         Code :

    class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        sort(people.begin(), people.end());
        int n = people.size();
        int l = 0;
        int r = n - 1;
        int k = 0;
        while (l <= r)
        {
            if (people[l] + people[r] > limit)
            {
                r--;
            }
            else
            {
                l++;
                r--;
            }
            k++;
        }
        return k;
    }
};

// Happy Coding :-)