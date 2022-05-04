/*
Method:

we want to find the pairs whose sum is k and remove them
so we create a hashmap mp
now the numbers greater than k in the nums array are of no use as the nums array consist of integers greater than 0
so we only add integers that are less than k only
now first check if the k-nums[i] has already occured
if it has and it's curr number of occurence i.e. mp[nums[i]]>0 then we increase the count c and decrease its occurence
note that in this step we didn't added anything to the map hence there won't be any problem( will explain this more with the help of an example)
if it isin't there then we add it to the map if the integer is less than k

example:
    for nums = [3,1,3,4,3]
    i=0;
        3<6 but mp[3]=0 so we add 3 in the map
    i=1
        1<6 but mp[5]=0 so we add 1 in the map
    i=2
        3<6 and mp[6-3]=1>0 so we found a pair
        increase c to 1
        and mp[3]--
        Note that here we didn't added anything so currently there is no 3 in the map
        if we would have added 3 then later on this 3 must have counted itself as a pair as mp[3]=mp[6-3]
        so in order to account for the case when the nums[i]=k-nums[i] we won't add anything in this
    i=3
        4<6 and mp[2]=0 so add 4 to map
    i=4
        3<6 but mp[3]=0 so add 3 to map
    hence c=1

Time Complexity: O(n)
    as we run a for loop n times

Space Complexity: O(n)
    as we created a map of size n
*/
// code:

class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {

        unordered_map<int, int> mp;
        int i, n, c;
        c = 0;
        n = nums.size();
        for (i = 0; i < n; i++)
        {
            if (nums[i] < k && mp.find(k - nums[i]) != mp.end() && mp[k - nums[i]] > 0)
            {
                c++;
                mp[k - nums[i]]--;
            }
            else if (nums[i] < k)
            {
                mp[nums[i]]++;
            }
        }
        return c;
    }
};